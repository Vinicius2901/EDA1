#include "pile.h"
#include <stdio.h>

int main(){
    int n = 5;
    MultiPile *p = criaPilha(n);
    if(vazia(p, 1))
        printf("vazia\n");
    else
        printf("tem algo\n");

    if(vazia(p, 0))
        printf("vazia\n");
    else
        printf("tem algo\n");
        
    Element tmp;
    tmp.a = 1;
    empilha(p,tmp,1);
    tmp.b = 3.14;
    empilha(p,tmp,0);
    tmp.a = 4;
    empilha(p,tmp,1);
    
    printf("Ttl elements:%i\n", numElements(p,1));

    printf("%i\n",desempilha(p,1).a);
    printf("%i\n",top(p,1).a);
    printf("%f\n",top(p,0).b);

    printf("newTtl: %i\n", numElements(p,1));
    
    reinicia(p, 1);
    if(vazia(p, 1))
        printf("vazia\n");
    else
        printf("tem algo\n");

    if(vazia(p, 0))
        printf("vazia\n");
    else
        printf("tem algo\n");

    
    destroiPilha(&p);
    if(p==NULL)
        printf("P is NULL\n");
    return 0;
}

