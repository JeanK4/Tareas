#include <map>
#include <list>
#include <utility>
#include <iostream>

using namespace std;

void solucionProblema(map<int, int> &mapa, list<pair<int, int>> &lista, int &i, int &c){
	int numero, tmp;
	char instruccion;
	pair<int, int> dato;
	for(int k = 0; k < c; k++){ 
		cin >> instruccion;
		if(instruccion == 'N'){ 
			if(mapa.at(lista.front().first) == lista.front().second){
				dato = lista.front();
				lista.push_back(dato);
				cout << lista.front().first << endl;
				lista.pop_front();
			}
			else{
				lista.pop_front();
				cout << lista.front().first << endl;
			}
		}
		else{
			scanf("%d", &numero);
			if(numero > i){
				mapa[numero] = 0;
				lista.push_front(make_pair(numero, 0));
			}
			else{
				mapa[numero] += 1;
				tmp = lista.front().second + 1;
				lista.push_front(make_pair(numero, tmp));
			}
		}
	}
}

void lecturaDatos(){
	int p, c, caso = 0;
	map<int, int> mapa;
	list<pair<int, int>> lista;
	scanf("%d %d", &p, &c);
	int i = (p < c) ? p : c;
	while(p != 0 && c != 0){
		caso++;
		cout << "Case " << caso << ":" << endl;
		for(int j = 1; j <= i; j++){
			lista.push_back(make_pair(j, 0));
			mapa[j] = 0;
		}
		solucionProblema(mapa, lista, i, c);
		lista.clear();
		mapa.clear();
		scanf("%d %d", &p, &c);
	}
}

int main(){
	lecturaDatos();
	return 0;
}
