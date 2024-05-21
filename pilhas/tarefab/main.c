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
        if((c=='>' || c == ' ') && flag){ 
            flag = 0;
            if(!strcmp(s,"br") || !strcmp(s,"!DOCTYPE") || !strcmp(s,"input") || !strcmp(s,"img") || !strcmp(s,"frame")){
                c = fgetc(f);
                s = realloc(s, sizeof(char));
                i = 0;
                continue;
            }  
            if(s[0]=='/')
                if(strcmp(s+1,topStr(p))){
                   printf("Recebeu <%s>, esperava </%s>\n", s, topStr(p));
                   break; 
                }else{
                    desempilhaStr(p);
                    c = fgetc(f);
                    s = realloc(s, sizeof(char));
                    i = 0;
                    continue;
                }
            
            char *tmp = malloc((i+1)*sizeof(char));
            memcpy(tmp,s,i+1);
            emplaceStr(tmp,p);
            s = realloc(s, sizeof(char));
            i=0;
        }

        if(flag){
            i++;
            s = realloc(s,(i+1)*sizeof(char));
            s[i-1] = c;
            s[i] = '\0';
            if( !strcmp( s, "!--") ) {
            	flag = 0;
                while ( c != '>' ) {
                    c = fgetc(f);
                }
                s = realloc( s, sizeof(char) );
                s = 0;
                i=0;
            }
            else if( !strcmp( s, "--") ) {
            	flag = 0;
                while ( c != '>' ) {
                    c = fgetc(f);
                }
                s = realloc( s, sizeof(char) );
                s = 0;
                i=0;
            }
        }
        if(c=='<') 
            flag = 1;
        c = fgetc(f);
    }while(c != EOF);
    
    if(!empty(p))
        printf("Pilha invalida!\n");
    
    while (!empty(p)){
        printf("%s",topStr(p));
        desempilhaStr(p);
    }
    freePile(&p);
    fclose(f);
    
    
    return 0;
}