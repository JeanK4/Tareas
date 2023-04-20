#include "lista.h"

Lista::Lista(){
  act = NULL;
}

void Lista::insListaOrdenada(Elemento v){
  Nodo *nuevo,*tmp;
  nuevo = new Nodo;
  nuevo->dato = v;
  nuevo->sig = NULL;
  int i = 0;
  bool flag = false;
  if(act->sig == NULL){
    nuevo->sig = act;
    act = nuevo;
  }
  else{
    tmp = act;
    while(i <= longLista()-1 && flag == false){
      if(v == tmp->sig->dato){
        nuevo->sig = tmp->sig;
        tmp->sig = nuevo;
        flag = true;
      }
      else if(v > tmp->dato && v < tmp->dato){
        nuevo->sig = tmp;
        tmp = nuevo;
        flag = true;
      }
      tmp = tmp->sig;
      i++;
    }
  }
}

void Lista::elimLista(int pos){
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1)
      act = act->sig;
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
	tmp = tmp->sig;
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
  Nodo* tmp = act;

  for(int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;
}

int Lista::longLista(){
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}
