#include "pile.h"
#include <stdio.h>

int main(){
    int n = 5;
    MultiPile *p = criaPilha(n);
    Element tmp;
    tmp.a = 1;
    empilha(p,tmp,1);
    tmp.b = 3.14;
    empilha(p,tmp,0);
    tmp.a = 4;
    empilha(p,tmp,1);
    
    printf("Ttl elements:%i\n", numElements(p));

    printf("%i\n",desempilha(p,1).a);
    printf("%i\n",top(p,1).a);
    printf("%f\n",top(p,0).b);

    printf("newTtl: %i\n", numElements(p));
    destroiPilha(&p);
    if(p==NULL)
        printf("P is NULL\n");

    return 0;
}

