#include "pilhaStr.h"
#include <stdlib.h>

Pile *criaPilha(int n){
    if(n<1)
        return NULL;
    Pile *p = malloc(sizeof(Pile));
    p->container = malloc(n*sizeof(char*));
    p->capacity = n;
    p->position = -1;
    return p;
}

int emplaceStr(char *s, Pile *p){
    int val = 0;
    if(p->capacity<=p->position+1){
        p->container = realloc(p->container, 2*((p->capacity)*sizeof(char*)));
        p->capacity = 2*(p->capacity);
        val = 1;
    }
    p->position++;
    p->container[p->position] = s;
    return val;
}

char* topStr(Pile *p){
    return p->container[p->position];
}

void desempilhaStr(Pile *p){
    free(p->container[p->position]);
    p->position--;
}

void freePile(Pile **p){
    free((*p)->container);
    free(*p);
    *p = NULL;
}


int empty(Pile *p){
    return p->position==-1;
}