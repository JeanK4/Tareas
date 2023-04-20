#include "lista.h"
#include <iostream>

int contarOcurrencias(Lista& l, int v){
    int j, ans = 0;
    for(j = 1; j <= l.longLista(); j++){
        if(l.infoLista(j) == v)
            ans++;
    }
    return ans;
}

Lista obtenerMenores(Lista& l, int v){
    Lista ans;
    int j;
    for(j = 1; j <= l.longLista(); j++){
        if(l.infoLista(j) < v)
            ans.anxLista(l.infoLista(j));
    }
    return ans;
}
