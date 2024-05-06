#include <stdlib.h>
#include "pile.h"

MultiPile criaPilha(int n){
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

int empilhai(MultiPile *p, int e ) {
    if(cheia(p))
        return 1;
    p->topo1++;
    Element tmp;
    tmp.a = e;
    p->v[p->topo1] = tmp;
    return 0;
}

int empilhaf( MultiPile *p, float e ){
    if( cheia(p) ) 
        return 1;
    p->topo2--;
    Element tmp;
    tmp.b = e;
    p->v[p->topo2] = tmp;
    return 0;
}

int vazia( MultiPile *p){
    return p->topo1 == -1 && p->topo2 == p->tamVet;
}

int cheia( MultiPile *p ) {
    return p->topo1 >= p->topo2;
}


Element desempilha(MultiPile *p, int s){
    if(s==0 && p->topo1>=0){
        p->topo1--;
        return p->v[p->topo1+1];
    }
    if(s==1 && p->topo2<=p->tamVet){
        p->topo2++;
        return p->v[p->topo2-1];
    }
    Element error;
    return error;
}



