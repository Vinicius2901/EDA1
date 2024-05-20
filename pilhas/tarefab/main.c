#include "pilhaStr.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *f = fopen("test.html","rt");
    Pile *p = criaPilha(1);
    if(f==NULL){
        printf("Falha em abrir arquivo\n");
        return 0;
    }
    char c = '\0';
    char *s = malloc(1*sizeof(char));
    s[0] = '\0';
    int i = 0, flag = 0;
    do{
        if(c=='>'){ 
            flag = 0;
            printf("%s\n", s);
            char *tmp = malloc((i+1)*sizeof(char));
            memcpy(tmp,s,i+1);
            emplaceStr(tmp,p);
            s = realloc(s, sizeof(char));
            i=0;
            // TODO -> guardar string.
        }

        if(flag){
            i++;
            s = realloc(s,(i+1)*sizeof(char));
            s[i-1] = c;
            s[i] = '\0';
        }
        if(c=='<')
            flag = 1;
        c = fgetc(f);
    }while(c != EOF);
    
    while (!empty(p))
    {
        printf("%s\n",topStr(p));
        desempilhaStr(p);
    }
    
    
    return 0;
}