#include <string>
#include <iostream>
#include "biginteger.h"

using namespace std;

int main(){
	string numero = "26364637717263638283";
	BigInteger num(numero);
	BigInteger num1(num);
	num.printBI();
	num1.printBI();
	string numero1 = "2727166162737372661283";
	BigInteger num2(numero1);
	num.add(num2);
	num.printBI();
	string hola = num.toString();
	cout << hola << endl;
	return 0;
}