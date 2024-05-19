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
    if(p->capacity<=p->position)
        return 1;
    p->container[p->position];
    p->position++;
    return 0;
}

char* topStr(Pile *p){
    return p->container[p->position];
}

char* desempilhaStr(Pile *p){
    if(p->position<=-1)
        return NULL;
    char* v = p->container[p->position];
    p->position--;
    return v;
}

void freePile(Pile **p){
    free((*p)->container);
    free(*p);
    *p = NULL;
}
