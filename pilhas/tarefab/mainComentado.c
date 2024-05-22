#include "pilhaStr.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main( int argc, char *argv[] ){
    //----------- Analise dos parametros da main --------------------------
    // if (argc < 2) {         // Analisa se foi fornecido o arquivo como segundo parâmetro da main.
    //     fprintf(stderr, "[ E ]: Forneca o caminho completo do arquivo por meio do parametro. \n"); // Mensagem de erro.
    //     exit(EXIT_FAILURE); // Tem 1 como saída.
    // }

    //----------- Leitura de arquivo, criação da pilha, inicialização das variáveis. ------------------------

    FILE *f = fopen("test.html","rt");  // Abertura do arquivo.

    Pile *p = criaPilha(1); // Criação da pilha em que entrarão as strings.
    if(f==NULL){            // Verificação de falha na abertura do arquivo
        printf("Falha em abrir arquivo\n"); // Mensagem de falha.
        return 0;           // Encerra o programa.
    }
    char c = '\0';          // Inicialização do caracter auxiliar.
    char *s = malloc(1*sizeof(char)); // Alocação de memória da string que será analisada.
    s[0] = '\0';            // Inicialização da String para evitar "lixo" de memória.
    int i = 0, flag = 0;    // Contador para acessar o índice da string e booleano que indica quando a string está sendo formada.

    //------------ Funcionamento do código ----------------------------

    do{ // Loop feito até o fim do arquivo.

        // Verificação para fazer o registro da string.

        if((c=='>' || c == ' ') && flag){     
            flag = 0;                         // Declaração do booleano como 0, pois a string não está sendo formada.

            // Excessões que não são alocadas na pilha.

            if(!strcmp(s,"br") || !strcmp(s,"!DOCTYPE") || !strcmp(s,"input") || !strcmp(s,"img") || !strcmp(s,"frame")){ 
                c = fgetc(f);                 // 'c' passa a ser um caracter a frente no arquivo.
                s = realloc(s, sizeof(char)); // Realocação da memória da string reiniciá-la.
                i = 0;                        // Indice da string = 0.
                continue;
            }  

            // Verificação do fechamento de tag html.

            if(s[0]=='/')                     
                if(strcmp(s+1,topStr(p))){    // Verificação se a string após a barra é igual a string da última tag colocada na pilha.
                   printf("Recebeu <%s>, esperava </%s>\n", s, topStr(p)); // Se não for, ele indica o que recebeu e o que era esperado pelo programa.
                   break; 
                }else{
                    desempilhaStr(p);         // Se for igual, a tag é retirada da pilha.
                    c = fgetc(f);             // 'c' passa a ser um caracter a frente no arquivo.
                s = realloc(s, sizeof(char)); // Realocação da memória da string reiniciá-la.
                i = 0;                        // Indice da string = 0.
                    continue;
                }
            
            // Tratamento das tags de abertura.

            char *tmp = malloc((i+1)*sizeof(char)); // Alocação de string temporária.
            memcpy(tmp,s,i+1);                      // Copiando a string atual para a string temporária.
            emplaceStr(tmp,p);                      // Coloca a string atual na pilha (a abertura da tag atual).
            s = realloc(s, sizeof(char));           // Realocação da memória da string reiniciá-la.
            i = 0;                                  // Indice da string = 0.
        }

        // Verificação se a string está sendo formatada.

        if(flag){
            i++;                               // Incremento do índice da string.
            s = realloc(s,(i+1)*sizeof(char)); // Realocação de memória para um a mais que o índice sempre, para ter espaço para o '/0'.
            s[i-1] = c;                        // O penúltimo caracter da string é o caracter atual do arquivo.
            s[i] = '\0';                       // O último caracter da string é o fechamento da String.

            // // Tratamento da tag de comentário.

            // // Verificação se a string atual é igual ao início da tag de comentário ou ao fim
            // if( !strcmp( s, "!--") || !strcmp( s, "--") ) {
            // 	flag = 0;                       // A string deixa de ser formatada.
            //     while ( c != '>' ) {
            //         c = fgetc(f);               // Caracter é pulado até chegar no fechamento da tag de comentário ou de alguma tag dentro.
            //     }
            //     c = fgetc(f);                   // 'c' passa a ser um caracter a frente no arquivo.
            //     s = realloc(s, sizeof(char));   // Realocação da memória da string reiniciá-la.
            //     i = 0;                          // Indice da string = 0.
            // }
        }
        
        // Verificação de quando a string deve começar a ser formatada.

        if(c=='<') 
            flag = 1; // Booleano passa a ser 1

        c = fgetc(f); // Passa o caracter para o próximo.
    }while(c != EOF); // Explicado na linha do 'do'


    //--------------- Final ------------------

    // Verificação se a pilha é válida
    if(!empty(p))
        printf("Pilha invalida!\n");
    
    while (!empty(p)){
        desempilhaStr(p);
    }
    freePile(&p);
    fclose(f);
    
    
    return 0;
}