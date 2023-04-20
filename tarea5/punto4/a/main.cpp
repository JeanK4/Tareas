#include "lista.h"
#include <iostream>

void concatenarListas(Lista& l1, Lista& l2){
	int i;
	for(i = 1; i <= l2.longLista(); i++){
		l1.anxLista(l2.infoLista(i));	
	}
}

/*
int main(){
	Lista l1, l2;
	l1.anxLista(1);
	l1.anxLista(2);
	l1.anxLista(3);
	l1.anxLista(4);
	l1.anxLista(5);
	l1.anxLista(6);
	l2.anxLista(10);
	l2.anxLista(11);
	l2.anxLista(12);
	l2.anxLista(13);
	cout << "Lista antes de añadir la otra" << endl;
 	for(int i = 1; i <= l1.longLista(); i++)
		cout << l1.infoLista(i) << endl;
	concatenarListas(l1,l2);
	cout << "Lista despues de añadir la otra" << endl;
 	for(int i = 1; i <= l1.longLista(); i++)
		cout << l1.infoLista(i) << endl;
	return 0;
}
*/