#include <stdlib.h>
#include "pile.h"

MultiPile CriaPilha(int n){
    MultiPile pilha;
    pilha.tamVet = n;
    pilha.topo2 = n;
    pilha.topo1 = -1;
    pilha.v = malloc(n*sizeof(Element));
}



void destroiPilha(MultiPile *p){
    free(p->v);
    p->v = NULL;
    free(p);
    p = NULL;
}


