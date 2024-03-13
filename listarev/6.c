#include <stdio.h>

struct nodo {
    int x;
    struct nodo *link;
}

//Contador ate nulo
int cont1( struct *nodo ) {
    int cont = 0;
    struct nodo *p = nodo;
    struct nodo *aux = p
    while( aux != NULL ) {
        aux = aux->link;
        cont++;
    }

    return cont;
}

//Contador ate voltar no inicio
int cont2( struct *nodo ) {
    int cont = 0;
    struct nodo *p = nodo;
    struct nodo *aux = p
    int first = 1;
    while( first || aux != p ) {
        aux = aux->link;
        first = 0;
        cont++;
    }

    return cont;
}

//Contador volta nele mesmo
int cont2( struct *nodo ) {
    int cont = 0;
    struct nodo *p = nodo;
    struct nodo *aux = p
    int first = 1;
    while( first || aux != aux->link ) {
        aux = aux->link;
        first = 0;
        cont++;
    }

    return cont;
}