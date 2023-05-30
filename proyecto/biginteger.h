#include <list>
#include <vector>
#include <string>
#include <iostream>

#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H

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
	BigInteger();
	BigInteger(const string &cad);
	BigInteger(const BigInteger &num);

	/********************
	*   MODIFICADORAS   *
	********************/
	void add(BigInteger &num);
	void product(BigInteger &num);
	void substract(BigInteger &num);
	void quotient(BigInteger &num);
	void remainder(BigInteger &num);
	void pow(const int &num);

	/*******************
	*   ANALIZADORAS   *
	*******************/
	static BigInteger sumarListaValores(list<BigInteger> &lista);
	static BigInteger multiplicarListaValores(list<BigInteger> &lista);
	string toString();

	/*******************************
	*   SOBRECARGA DE OPERADORES   *
	*******************************/
	BigInteger operator+(BigInteger& num);
	BigInteger operator-(BigInteger& num);
	BigInteger operator*(BigInteger& num);
	BigInteger operator/(BigInteger& num);
	BigInteger operator%(BigInteger& num);
	bool operator==(BigInteger& num);
	bool operator<(BigInteger& num);
	bool operator<=(BigInteger& num);

};

#endif