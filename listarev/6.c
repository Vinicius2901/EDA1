#include <stdio.h>

//      #include -> importa diversos códigos(bibliotecas) a partir de um header.
//      #define -> define o "valor" de uma palavra para a compilação.
//      #undef -> tira o valor da palavra definida.
//      #ifdef -> equivale ao if defined( identificador ), que compila o que está dentro do if se o identificador for verdadeiro.
//      #ifndef -> equivale ao if !defined( identificador ), que compila o que está dentro do if se o identificador for falso.
//      #if, #else, #elif -> compõem blocos de if else, caso o identificador seja diferente de 0.
//      #endif -> fecha o bloco do if.

//Struct do meio da estrutura
typedef struct nodo {
    int x;
    struct nodo *link;
} Nodo;

//Struct de inicio da estrutura
typedef struct descritor {
    int tamanho;
    Nodo *inicio;
} Descritor;

//Contador ate nulo
int cont1( struct nodo *nodo ) {
    int cont = 0;
    struct nodo *p = nodo;
    struct nodo *aux = p;
    while( aux != NULL ) {
        aux = aux->link;
        cont++;
    }    free( p->link );

    return cont;
}

//Contador ate voltar no inicio
int cont2( struct nodo *nodo ) {
    int cont = 0;
    struct nodo *p = nodo;
    struct nodo *aux = p;
    int first = 1;
    while( first || aux != p ) {
        aux = aux->link;
        first = 0;
        cont++;
    }

    return cont;
}

//Contador volta nele mesmo
int cont3( struct nodo *nodo ) {
    int cont = 0;
    struct nodo *p = nodo;
    struct nodo *aux = p;
    int first = 1;
    while( first || aux != aux->link ) {
        aux = aux->link;
        first = 0;
        cont++;
    }

    return cont;
}

int reinicia( Descritor *p ) {
    if( p-> tamanho == 0 )
        return 0;

    Nodo *nodo_atual = p->inicio;
    Nodo *aux = p->inicio->link;

    while( aux != NULL ) {
        aux = nodo_atual->link;
        free( nodo_atual );
        nodo_atual = aux;
    }

    p->tamanho = 0;
    p->inicio = NULL;
    return 1;
}

int insere( Descritor *p, Nodo *novo, int pos ) {
    int i;
    Nodo *aux = NULL;
    if( pos > p->tamanho || pos < 1 || p->inicio == NULL )
        return 0;
    if( pos == 1 ) {
        novo->link = p->inicio;
        p->inicio = novo;
    }
    aux = p->inicio;
    for( i = 1; i < pos-1; i++ )
        aux = aux->link;
    novo->link = aux->link;
    aux->link = novo;
    (p->tamanho)++;

    return 1;
}
