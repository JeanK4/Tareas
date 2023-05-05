#include "queue.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

queue::queue(){
}

void queue::enqueue(int n){
	cola.push_back(n);
}

void queue::dequeue(){
	int menor = 9999;
	for(int i = 0; i < cola.size(); i++){
		if(cola[i] < menor)
			menor = cola[i];
	}
	vector<int>::iterator it = find(cola.begin(), cola.end(), menor);
	cola.erase(it);
}

int queue::front(){
	int menor = 9999;
	for(int i = 0; i < cola.size(); i++){
		if(cola[i] < menor)
			menor = cola[i];
	}
	return menor;
}

bool queue::empty(){
	return cola.empty();
}