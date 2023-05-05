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
	BigInteger operator==(BigInteger& num);
	BigInteger operator<(BigInteger& num);
	BigInteger operator<=(BigInteger& num);

};

#endif