#include <stdlib.h>
#include "pile.h"

MultiPile* criaPilha(int n)
{
    MultiPile *p = malloc(sizeof(MultiPile));
    p->tamVet = n;
    p->topo2 = n;
    p->topo1 = -1;
    p->v = malloc(n * sizeof(Element));
    return p;
}

void destroiPilha(MultiPile **p)
{
    free((*p)->v);
    free(*p);
    *p = NULL;
}

int empilha(MultiPile *p, Element e, int s)
{
    if(cheia(p))
        return 1;
    if(s){
        p->topo1++;
        (p->v)[p->topo1] = e;
    }else{
        p->topo2--;
        (p->v)[p->topo2] = e;
    }
    return 0;
}

int vazia(MultiPile *p)
{
    return p->topo1 == -1 && p->topo2 == p->tamVet;
}

int cheia(MultiPile *p)
{
    return p->topo1 >= p->topo2;
}

Element desempilha(MultiPile *p, int s)
{
    if (s && p->topo1 >= 0)
    {
        p->topo1--;
        return (p->v)[p->topo1 + 1];
    }
    if (!s && p->topo2 <= p->tamVet)
    {
        p->topo2++;
        return (p->v)[p->topo2 - 1];
    }
    Element error;
    return error;
}

void reinicia(MultiPile *p)
{
    p->topo1 = -1;
    p->topo2 = p->tamVet;
}

Element top(MultiPile *p , int s)
{
    if (s && p->topo1 >= 0)
        return (p->v)[p->topo1];
    
    if (!s && p->topo2 <= p->tamVet)
        return (p->v)[p->topo2];
    
    Element error;
    return error;
}

int numElements(MultiPile *p){
    return (p->topo1+1)+(p->tamVet-p->topo2);
}