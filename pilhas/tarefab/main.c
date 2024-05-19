#include "pilhaStr.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *f = fopen("test.html","rt");

    if(f==NULL){
        printf("Falha em abrir arquivo\n");
        return 0;
    }
    char c = '\0';
    char *s = malloc(sizeof(char));
    int i = 0, flag = 0;
    do{
        if(c=='>'){
            flag = 0;
            printf("%s", s);
            free(s);
            s = malloc(sizeof(char));
            // TODO -> guardar string.
        }
        if(flag){
            s[i] = c;
            i++;
            s = realloc(s,(i+1)*sizeof(char));
        }
        if(c=='<')
            flag = 1;
        c = fgetc(f);
    }while(c != EOF);
    
    
    
    return 0;
}