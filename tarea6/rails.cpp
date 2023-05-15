/*
Autor: Jean Karlo Buitrago Orozco
Codigo: 8972318
*/

#include <stack>
#include <vector>
#include <iostream>

using namespace std;

/*Operación solucionProblema

Información: Esta operación recibe como parametro un vector, una pila y un entero por referencia y 
determina si numeros ascendentes pueden ser organizados de la forma en que estan en el vector mediante
el uso de pilas, ya que solo puede salir un numero si esta en el top de esta.

Complejidad: La complejidad del algoritmo que resuelve el problema es el mejor y peor de los casos O(n) 
siendo  n el numero de trenes que van a ser usados en la ejecución del caso ya que el orden requerido 
es el  orden de entrada de los datos (de menor a mayor) y en el peor de los casos sigue siendo lineal
ya que se recorreria la pila una vez sin afectar la complejidad. */

void solucionProblema(vector<int> &vec, stack<int> &pila, int &numero){
	int i = 0, j = 1;
	bool flag = true, flag1 = true;
	while(flag){
		if(i < numero && j <= numero){
			if(!pila.empty() && pila.top() == vec[i]){
				pila.pop();
				i++;
			}
			else if(vec[i] != j){
				pila.push(j);
				j++;
			}
			else if(vec[i] == j){
				i++;
				j++;
			}
		}
		else{
			if(!pila.empty()){
				if(pila.top() == vec[i]){
					pila.pop();
					i++;
				}
				else{
					flag = false;
					flag1 = false;
				}
			}
			else
				flag = false;
		}	
	}
	if(flag1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	i = 0;
	j = 1;
	flag = true;
	flag1 = true;
}

void lecturaDatos(){
	int numero, numeros;
	stack<int> pila;
	vector<int> vec;
	scanf("%d", &numero);
	while(numero != 0){
		scanf("%d", &numeros); 
		while(numeros != 0){
			vec.push_back(numeros);
			for(int i = 1; i < numero; i++){
				scanf("%d", &numeros);
				vec.push_back(numeros);
			}
			solucionProblema(vec, pila, numero);
			scanf("%d", &numeros); 
		vec.clear();
		while(!pila.empty())
			pila.pop();
		}
		cout << endl;
		scanf("%d", &numero);
	}
}	

int main(){
	lecturaDatos();
	return 0;
}
