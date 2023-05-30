#include "biginteger.h"
#include <algorithm>
#include <sstream>

using namespace std;

BigInteger::BigInteger(){ 
}

BigInteger::BigInteger(const string &cad){
  if(cad.empty()){
    numero.push_back(0);
    signo = true;
  }
  else{
    if(cad[0] == '-'){
      signo = false;
      for(int i = cad.size()-1; i > 0; i--)
        numero.push_back(cad[i]-'0');
    }
    else{
      signo = true;
      for(int i = cad.size()-1; i >= 0; i--)
        numero.push_back(cad[i]-'0');
  	}
  }
  delZero(numero);
}

BigInteger::BigInteger(const BigInteger &num){
  numero = num.numero;
  signo = num.signo;
}

/*************************
* Operaciones Auxiliares *
*************************/

string BigInteger::vectorToString(vector<int> &numero,bool signo){
  string palabra;
  if(signo == false)
    palabra.push_back('-');
  for(int i = numero.size()-1; i >= 0; i--)
    palabra.push_back(numero[i]+'0');
  return palabra;
}

void BigInteger::delZero(vector<int> &numero){
  int i = numero.size()-1;
  while(numero[i] == 0){
    numero.pop_back();
    i--;
  }
}

bool BigInteger::Equal(vector<int> &numero, vector<int> &num){
  bool ans = true;
  int i = numero.size()-1;
  if(numero.size() == num.size()){
    while(i >= 0 && ans){
        if(numero[i] != num[i])
          ans = false;
        i--;
    }
  }
  else
    ans = false;
  return ans;
}

bool BigInteger::Minor(vector<int> &numero, vector<int> &num){
  int i = numero.size()-1;
  bool ans, flag = true;
  if(numero.size() < num.size())
    ans = true;
  else if(numero.size() > num.size())
    ans = false;
  else{
    while(i >= 0 && flag){
      if(numero[i] > num[i]){
        ans = false;
        flag = false;
      }
      else if(numero[i] < num[i]){
        ans = true;
        flag = false;
      }
      i--;
    }
  }
  return ans;
}

void BigInteger::sum(vector<int> &numero, vector<int> &num){
  int count = 0;
  if(numero.size() > num.size()){
    while(numero.size() != num.size())
      num.push_back(0);
  }
  else if(numero.size() < num.size()){
    while(numero.size() != num.size())
      numero.push_back(0);
  }
  if(numero.size() == num.size()){
    for(int i = 0; i < numero.size(); i++){
      if(numero[i] + num[i] > 9 && i < numero.size()-1){
        numero[i] = (numero[i] + num[i]) % 10;
        numero[i+1] += 1;
      }
      else if(numero[i] + num[i] > 9 && i < numero.size()){
        numero[i] = (numero[i] + num[i]) % 10;
        count++;
      }
      else
        numero[i] += num[i];
    }
  }
  numero.push_back(count);
  delZero(num);
  delZero(numero);
}

void BigInteger::subtraction(vector<int> &numero, vector<int> &num){
  if(numero.size() > num.size()){
    while(numero.size() != num.size())
      num.push_back(0);
  }
  else if(numero.size() < num.size()){
    while(numero.size() != num.size())
      numero.push_back(0);
  }
  for(int i = 0; i < numero.size(); i++){
    if(numero[i] < 0 && numero.size()-1){
      numero[i] += 10;
      numero[i+1] -= 1;
    }
    if((numero[i] - num[i]) < 0 && i < numero.size()-1){
      numero[i] = ((numero[i] + 10) - num[i]);
      numero[i+1] -= 1;
    }
    else if((numero[i] - num[i]) < 0 && i < numero.size())
      numero[i] = ((numero[i] + 10) - num[i]);
    else  
      numero[i] -= num[i];
  }
  delZero(numero);
  delZero(num);
}

void BigInteger::subtraction2(vector<int> &numero, vector<int> &num){
  if(numero.size() > num.size()){
    while(numero.size() != num.size())
      num.push_back(0);
  }
  else if(numero.size() < num.size()){
    while(numero.size() != num.size())
      numero.push_back(0);
  }
  for(int i = 0; i < numero.size(); i++){
    if(numero[i] < 0 && numero.size()-1){
      numero[i] += 10;
      num[i+1] -= 1;
    }
    if((num[i] - numero[i]) < 0 && i < numero.size()-1){
      numero[i] = ((num[i] + 10) - numero[i]);
      num[i+1] -= 1;
    }
    else if((num[i] - numero[i]) < 0 && i < numero.size())
      numero[i] = ((num[i] + 10) - numero[i]);
    else  
      numero[i] = num[i] - numero[i];
  }
  delZero(numero);
  delZero(num);
}

void BigInteger::multiplication(vector<int> &ans, vector<int> &aux, int &times){
  int carry = 0, mult;
  for(int i = 0; i < aux.size(); i++){
    mult = aux[i] * times + carry;
    carry = mult / 10;
    ans[i] = mult % 10;
  }
  if(carry > 0)
    ans.push_back(carry);
}

/**********************
* Operaciones del TAD *
**********************/

void BigInteger::add(BigInteger &num){
  if(signo == true && num.signo == true)
    sum(numero, num.numero);
  else if(signo == true && num.signo == false){
    if(Minor(numero, num.numero)){
      subtraction2(numero, num.numero);
      signo = false;
    }
    else{
      subtraction(numero, num.numero);
      signo = true;
    }
  }
  else if(signo == false && num.signo == false){
    sum(numero, num.numero);
    signo = false;
  }
  else if(signo == false && num.signo == true){
    if(Minor(numero, num.numero)){
      subtraction2(numero, num.numero);
      signo = true;
    }
    else{
      subtraction(numero, num.numero);
      signo = false;
    }
  }
}

void BigInteger::product(BigInteger &num){
  int times, count = 0;
  vector<int> aux = numero;
  vector<int> ans = numero;
  for(int i = 0; i < num.numero.size(); i++){
    times = num.numero[i];
    multiplication(ans, aux, times);
    for(int i = 0; i < count; i++)
      ans.insert(ans.begin(), 0);
    if(count == 0)
      numero = ans;
    else
      sum(numero, ans);
    count++;
    ans = aux;
  }
  if(signo != num.signo)
    signo = false;
  else
    signo = true;   
}

void BigInteger::substract(BigInteger &num){
  if(signo == false && num.signo == false){
    if(Minor(numero, num.numero)){
      subtraction2(numero, num.numero);
      signo = true; 
    }
    else if(Equal(numero, num.numero)){
      numero.clear();
      numero.push_back(0);
      signo = true;
    }
    else{
      subtraction(numero, num.numero);
      signo = false;
    }
  }
  else if(signo == true && num.signo == true){
    if(Minor(numero, num.numero)){
      subtraction2(numero, num.numero);
      signo = false; 
    }
    else if(Equal(numero, num.numero)){
      numero.clear();
      numero.push_back(0);
      signo = true;
    }
    else{
      subtraction(numero, num.numero);
      signo = true;
    } 
  }
  else if(signo == false && num.signo == true){
    sum(numero, num.numero);
    signo = false;
  }
  else if(signo == true && num.signo == false)
    sum(numero, num.numero);
}

void BigInteger::quotient(BigInteger &num){
  int cocientetmp = 0, cociente = 0;
  int count = 1, diff = 0;
  vector<int> tmp;
  if(numero.size() < num.numero.size()){
    numero.clear();
    signo = true;
    numero.push_back(0);
  }
  else if(Equal(numero, num.numero)){
    numero.clear();
    numero.push_back(1);
  }
  else{
    if(signo != num.signo)
      signo = false;
    else
      signo = true;
    while(Minor(num.numero, numero)){
      tmp = num.numero;
      reverse(tmp.begin(), tmp.end());
      while(numero.size() != tmp.size()){
        tmp.push_back(0);
        diff++;
      }
      reverse(tmp.begin(), tmp.end());
      if(Minor(numero, tmp)){
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        diff--;
        reverse(tmp.begin(), tmp.end());
      }
      if(diff != 0){
        for(int i = 0; i <= diff; i++){
          cocientetmp = count;
          count *= 10;
        }
      }
      else{
        cocientetmp++;
      }
      subtraction(numero, tmp);
      tmp.clear();
      diff = 0;
      cociente += cocientetmp;
      count = 1;
      cocientetmp = 0;
    }
    numero.clear();
    ostringstream convertir;
    convertir << cociente;
    string cadena = convertir.str();
    for(int i = 0; i < cadena.size(); i++){
      numero.push_back(cadena[i]-'0');
    }
    reverse(numero.begin(), numero.end());
  }
}


void BigInteger::remainder(BigInteger &num){
  int diff = 0;
  vector<int> tmp;
  if(numero.size() < num.numero.size()){
    diff = 0;
  }
  else if(Equal(numero, num.numero)){
    numero.clear();
    numero.push_back(0);
  }
  else{
    while(Minor(num.numero, numero)){
      tmp = num.numero;
      reverse(tmp.begin(), tmp.end());
      while(numero.size() != tmp.size()){
        tmp.push_back(0);
        diff++;
      }
      reverse(tmp.begin(), tmp.end());
      if(Minor(numero, tmp)){
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        diff--;
        reverse(tmp.begin(), tmp.end());
      }
      subtraction(numero, tmp);
      tmp.clear();
      diff = 0;
    }
  }
  if((signo && !num.signo) || (!signo && num.signo))
    add(num);
  if(signo != num.signo)
      signo = false;
}

void BigInteger::pow(const int &num){
  string aux = vectorToString(numero, signo);
  BigInteger ans(aux);
  if(num == 0){
    numero.clear();
    numero.push_back(1);
  }
  else{
    if(num > 0){
      for(int i = 1; i < num; i++)
        product(ans);
      if(num % 2 == 0)
        signo = true;
      else
        signo = false;
      }
    else{
      signo = true;
      numero.clear();
      numero.push_back(0);
    }
  }
}

  /*******************
  *   ANALIZADORAS   *
  *******************/

string BigInteger::toString(){
  string ans;
  if(signo == false)
    ans.push_back('-');
  for(int i = numero.size()-1; i >= 0; i--)
    ans.push_back(numero[i] +'0');
  return ans;
}

BigInteger BigInteger::sumarListaValores(list<BigInteger> &lista){
  list<BigInteger>::iterator it;
  BigInteger ans("0");
  BigInteger c;
  for(it = lista.begin(); it != lista.end(); it++){
    c = *it;
    ans.add(c);
  }
  return ans;
}

BigInteger BigInteger::multiplicarListaValores(list<BigInteger> &lista){
  list<BigInteger>::iterator it;
  BigInteger ans("1");
  BigInteger c;
  for(it = lista.begin(); it != lista.end(); it++){
    c = *it;
    ans.product(*it);
  }
  return ans;
}

  /*******************************
  *   SOBRECARGA DE OPERADORES   *
  *******************************/

BigInteger BigInteger::operator+(BigInteger& num){
  string palabra;
  palabra = vectorToString(numero, signo);
  BigInteger ans(palabra);
  ans.add(num);
  return ans;
}

BigInteger BigInteger::operator-(BigInteger& num){
  string palabra;
  palabra = vectorToString(numero, signo);
  BigInteger ans(palabra);
  ans.substract(num);
  return ans;
}

BigInteger BigInteger::operator*(BigInteger& num){
  string palabra;
  palabra = vectorToString(numero, signo);
  BigInteger ans(palabra);
  ans.product(num);
  return ans;
}

BigInteger BigInteger::operator/(BigInteger& num){
  string palabra;
  palabra = vectorToString(numero, signo);
  BigInteger ans(palabra);
  ans.quotient(num);
  return ans;
}

BigInteger BigInteger::operator%(BigInteger& num){
  string palabra;
  palabra = vectorToString(numero, signo);
  BigInteger ans(palabra);
  ans.remainder(num);
  return ans;
}

bool BigInteger::operator==(BigInteger &num){
  int i = numero.size()-1;
  bool ans = true;
  if(num.signo != signo)
    ans = false;
  else{
    if(numero.size() != num.numero.size())
      ans = false;
    else{
      while(i >= 0 && ans){
        if(numero[i] != num.numero[i])
          ans = false;
        i--;
      }
    }
  }
  return ans;
}

bool BigInteger::operator<(BigInteger &num){
  int i = numero.size()-1;
  bool ans = true, flag = true;
  if(signo == false && num.signo == true)
    ans = true;
  else if(signo == false && num.signo == false){
    if(numero.size() < num.numero.size())
      ans = false;
    else if(numero.size() > num.numero.size())
      ans = true;
    else{
      while(i >= 0 && flag){
        if(numero[i] < num.numero[i]){
          ans = false;
          flag = false;
        }
        else if(numero[i] > num.numero[i]){
          ans = true;
          flag = false;
        }
        i--;
      }
    }
  }
  else if(signo == true && num.signo == true){
    i = numero.size()-1;
    if(numero.size() < num.numero.size())
      ans = true;
    else if(numero.size() > num.numero.size()){
      ans = false;
    }
    else{
      while(i >= 0 && flag){
        if(numero[i] > num.numero[i]){
          ans = false;
          flag = false;
        }
        else if(numero[i] < num.numero[i]){
          ans = true;
          flag = false;
        }
        i--;
      }
    }
  }
  else{
    ans = false;
  }
  return ans;
}

bool BigInteger::operator<=(BigInteger& num){
  bool ans = false;
  string word;
  word = vectorToString(numero, signo);
  BigInteger aux(word);
  if(aux < num || aux == num)
    ans = true;
  return ans;
}