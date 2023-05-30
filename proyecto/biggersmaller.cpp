#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class BigInteger{
	private:

		/************
		* ATRIBUTOS *
		************/
		bool signo;
		vector<int> numero;

		/*********************************
		* OPERACIONES AUXILIARES INTERNAS*
		**********************************/

		// Operacion que devuelve un string con el contenido del vector en el orden del numero

		string vectorToString(vector<int> &numero, bool signo);

		// Operacion que elimina los ceros que se añaden en otras operaciones 

		void delZero(vector<int> &numero);
		
		// Operacion que determina si el primer vector de un BigInteger es mayor o menor al segundo vector sin verificar signos
		
		bool Minor(vector<int> &numero, vector<int> &num);
		
		// Operacion que determina si el primer vector de un BigInteger es igual al segundo vector sin verificar signos
		
		bool Equal(vector<int> &numero, vector<int> &num);
		
		// Operacion que realiza la suma de 2 vectores sin verificar signos
		
		void sum(vector<int> &numero, vector<int> &num);
		
		// Operacion que realiza la resta de 2 vectores sin verificar signos
		
		void subtraction(vector<int> &numero, vector<int> &num);
		
		// Operacion que realiza la resta de 2 vectores al revés sin verificar signos
		
		void subtraction2(vector<int> &numero, vector<int> &num);

		// Operacion que suma un vector de enteros un numero de veces

		void multiplication(vector<int> &ans, vector<int> &aux, int &times);

	public:
	
	/********************
	*   CONSTRUCTORAS   *
	********************/
	BigInteger(); // Listo
	BigInteger(const string &cad); // Listo
	BigInteger(const BigInteger &num); // Listo

	/********************
	*   MODIFICADORAS   *
	********************/
	void add(BigInteger &num);
	void product(BigInteger &num);
	void substract(BigInteger &num);
	void quotient(BigInteger num);
	void remainder(BigInteger &num); 
	void pow(const int &num);

	/*******************
	*   ANALIZADORAS   *
	*******************/
	static BigInteger sumarListaValores(list<BigInteger> &lista); // Listo
	static BigInteger MultiplicarListaValores(list<BigInteger> &lista); // Listo
	string toString(); // Listo

	/*******************************
	*   SOBRECARGA DE OPERADORES   *
	*******************************/
	BigInteger operator+(BigInteger& num); // Listo
	BigInteger operator-(BigInteger& num); // Listo
	BigInteger operator*(BigInteger& num); // Listo
	BigInteger operator/(BigInteger& num); // Mañana
	BigInteger operator%(BigInteger& num); // Mañana
	bool operator==(BigInteger& num); // Listo
	bool operator<(BigInteger& num); // Listo
	bool operator<=(BigInteger& num); // Listo

};

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

  /*******************************
  *   SOBRECARGA DE OPERADORES   *
  *******************************/

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

void biggerOrSmaller(BigInteger &a, string &b1, BigInteger &c, string &d1){
	if(b1.size() > d1.size()){
		while(b1.size() != d1.size())
			d1.push_back('0');
	}
	else if(b1.size() < d1.size()){
		while(b1.size() != d1.size())
			b1.push_back('0');
	}
	BigInteger b(b1);
	BigInteger d(d1);
	if(a == c && b == d)
 		cout << "Same" << endl;
	else if(a < c)
		cout << "Smaller" << endl;
	else if(a == c && b < d)
		cout << "Smaller" << endl;
	else
		cout << "Bigger" << endl;
}

void lecturaImpresionDatos(){
	string numero, a1, b1, c1, d1;
	int count = 1, cases = 1;
	while(getline(cin, numero)){
		printf("Case %d: ", cases);
		for(int i = 0; i < numero.size(); i++){
			if(numero[i] != ' ' && numero[i] != '.'){
				if(count == 1)
					a1.push_back(numero[i]);
				else if(count == 2)
					b1.push_back(numero[i]);
				else if(count == 3)
					c1.push_back(numero[i]);
				else if(count == 4)
					d1.push_back(numero[i]);
			}
			else
				count++;
		}
		BigInteger a(a1);
		BigInteger c(c1);
		biggerOrSmaller(a, b1, c, d1);
		count = 1;
		a1 = "";
		b1 = "";
		c1 = "";
		d1 = "";
		cases++;
	}
}

int main(){
	lecturaImpresionDatos();
	return 0;
}