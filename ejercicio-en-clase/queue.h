#include <vector>
#include <iostream>

using namespace std;

#ifndef _COLA_H
#define _COLA_H

class queue{
	private:
		vector<int> cola;
	
	public:
	
	/***************
	 * Constructor *
	***************/
	queue();

	/*****************
	 * Modificadoras *
	*****************/
	void enqueue(int n);
	void dequeue();
	
	/****************
	 * Analizadoras *
	****************/
	int front();
	bool empty();

};

#endif
