/*
Autor: Jean Karlo Buitrago Orozco
Codigo: 8972318
*/

#include <list>
#include <string>
#include <iostream>

using namespace std;

/*Operacion solucionProblema

Información: Recibe una lista y una cadena por referencia y recorre la cadena dañada
para posteriormente dejar una lista de caracteres con la cadena ordenada.

Complejidad: La complejidad de esta operacion es O(n) siendo n el tamaño de la cadena
ya que las operaciones de insertar en una lista es O(1) y se hacen n veces. */

void solucionProblema(list<char> &solution, string &text){
	list<char>::iterator it = solution.begin();
	/* Recorrido cadena */
	for(int i = 0; i < text.size(); i++){
		if(text[i] != '[' && text[i] != ']')
			solution.insert(it, text[i]);
		else if(text[i] == ']')
			it = solution.end();
		else if(text[i] == '[')
			it = solution.begin();
	}	
}

void lecturaDatosImpresion(){
	string text;
	list<char> solution;
	while(getline(cin, text)){
		solucionProblema(solution, text);
		/* Impresion */
		list<char>::iterator i;
		for(i = solution.begin(); i != solution.end(); i++){ 
        	cout << *i;
		}
    	cout << endl;
		solution.clear();
	}
}

int main(){
	lecturaDatosImpresion();
	return 0;
}	