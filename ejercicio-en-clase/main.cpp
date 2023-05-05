#include "queue.h"
#include <iostream>

int main(){
	queue cola;
	cola.enqueue(5);
	cola.enqueue(4);
	cola.enqueue(2);
	cola.enqueue(1);
	cola.enqueue(7);
	int i = cola.front();
	printf("%d\n", i);
	cola.dequeue();
	i = cola.front();
	printf("%d\n", i);
	cola.dequeue();
	i = cola.front();
	printf("%d\n", i);
	cola.dequeue();
	i = cola.front();
	printf("%d\n", i);
	if(cola.empty())
		cout << "Cola vacia" << endl;
	else
		cout << "Cola con datos" << endl;
	cola.dequeue();
	i = cola.front();
	printf("%d\n", i);
	cola.dequeue();
	if(cola.empty())
		cout << "Cola vacia" << endl;
	else
		cout << "Cola con datos" << endl;
	return 0;
}