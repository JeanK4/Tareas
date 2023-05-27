#include <list>
#include <stack>
#include <iostream>

using namespace std;

void eliminarPosicionesPila(stack<int> &pil, list<int> &l){
	list<int> pila;
	list<int>::iterator it;
	list<int>::iterator it2;
	while(!pil.empty()){
		pila.push_front(pil.top());
		pil.pop();
	}
	int count = 0;
	it2 = l.begin();
	for(it = pila.begin(); it != pila.end(); it++){
		if(*it2 != count)
			pil.push(*it);
		else
			it2++;
		count++;
	}
}

int main(){
	/********************
	*  Main de punto 1  *
	********************/
	/*stack<int> pil;
	list<int> l;
	l.push_back(0);
	l.push_back(3);
	pil.push(1);
	pil.push(2);
	pil.push(3);
	pil.push(4);
	pil.push(5);
	stack<int> pil1 = pil;
	while(!pil1.empty()){
		cout << pil1.top() << endl;
		pil1.pop();
	}
	eliminarPosicionesPila(pil, l);
	while(!pil.empty()){
		cout << pil.top() << endl;
		pil.pop();
	}*/
	return 0;
}