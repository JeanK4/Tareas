#include <list>
#include <vector>
#include <string>
#include <iostream>

#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H

using namespace std;

class BigInteger{
	private:
		vector<int> numero;
		
	public:
	
	/********************
	*   CONSTRUCTORAS   *
	********************/
	BigInteger(string &cad);
	BigInteger(BigInteger &num);

	/********************
	*   MODIFICADORAS   *
	********************/
	void add(BigInteger &num);
	void product(BigInteger &num);
	void substract(BigInteger &num);
	void quotient(BigInteger &num);
	void remainder(BigInteger &num);
	void pow(BigInteger &num);

	/*******************
	*   ANALIZADORAS   *
	*******************/
	BigInteger sumarListaValores(list<BigInteger> &list);
	BigInteger MultiplicarListaValores(list<BigInteger> &list);
	void printBI();
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