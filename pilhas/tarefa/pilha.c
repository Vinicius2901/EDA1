#include <stdlib.h>
#include "pile.h"

typedef struct MultiPile{
    int topo1,topo2, tamVet;
    int v[];
} MultiPile;

typedef struct Pile{
    
} Pile;

MultiPile CriaPilha(int n, void *p){
    MultiPile pilha;
    pilha.tamVet = n;
    pilha.topo2 = n;
    pilha.topo1 = -1;
    pilha.v = malloc(sizeof );
}
