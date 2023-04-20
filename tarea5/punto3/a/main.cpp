#include "lista.h"
#include <iostream>

void insertarEnListaOrdenada(Lista& l, int v){
	bool flag = false;
	int j = 0;
	if(l.vaciaLista() == true){
		l.anxLista(v);
	}
	else{
		while(j <= l.longLista()-1 && flag == false){
			if(v == l.infoLista(j)){
				l.insLista(v, j);
				flag = true;
			}
			else if(v > l.infoLista(j) && v < l.infoLista(j+1)){
				l.insLista(v, j+1);
				flag = true;
			}
			j++;
		}
		if(v >= l.infoLista(l.longLista()))
			l.anxLista(v);
	}
}
/*
int main(){
	Lista l;
	l.anxLista(1);
	l.anxLista(2);
	l.anxLista(3);
	l.anxLista(4);
	l.anxLista(5);
	l.anxLista(6);
	cout << "Lista antes del cambio" << endl;
	for(int i = 1; i <= l.longLista(); i++)
		cout << l.infoLista(i) << endl;
	insertarEnListaOrdenada(l, 5);
	cout << "Lista despues del cambio" << endl;
	for(int i = 1; i <= l.longLista(); i++)
		cout << l.infoLista(i) << endl;
	return 0;
}
*/