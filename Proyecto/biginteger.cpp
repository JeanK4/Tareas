#include <string>
#include <vector>
#include "biginteger.h"

using namespace std;

BigInteger::BigInteger(string &cad){
	for(int i = 0; i < cad.length(); i++)
		numero.push_back(cad[i]-'0');
}

BigInteger::BigInteger(BigInteger &num){
  numero = num.numero;
} 

void BigInteger::printBI(){
	for(int i = 0; i < numero.size(); i++)
		cout << numero[i];
  cout << endl;
}

void BigInteger::add(BigInteger &num){
  int i;
  if(numero.size() >= num.numero.size()){
    i = numero.size()-1;
    while(numero.size() !=  num.numero.size()){
      num.numero.insert(num.numero.begin(), 0);
    }
  }
  else{
    i = num.numero.size()-1;
    while(numero.size() !=  num.numero.size()){
      numero.insert(numero.begin(), 0);
    }
  }
  for(i; i >= 0; i--){
    if(numero[i] + num.numero[i] >= 10){
      if(i == 0){
        numero[i] = (numero[i] + num.numero[i]) % 10;
        numero.insert(numero.begin(), 1);
      }
      else{
        numero[i-1] += 1;
        numero[i] = (numero[i] + num.numero[i]) % 10;
      }
    }
    else
      numero[i] += num.numero[i];
  }
}

/*void BigInteger::product(BigInteger &num){

}*/

void substract(BigInteger &num){
  
}

string BigInteger::toString(){
  string ans = "";
  for(int i = 0; i < numero.size(); i++)
    ans.push_back(numero[i]+'0');
  return ans;
}