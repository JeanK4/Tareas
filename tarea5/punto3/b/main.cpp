#include "lista.h"
#include <iostream>

int main(){
	Lista l;
	l.insListaOrdenada(1);
	l.insListaOrdenada(4);
	for(int i = 1; i <= l.longLista();i++){
		cout << l.infoLista(i) << endl;
	}
	return 0;
}