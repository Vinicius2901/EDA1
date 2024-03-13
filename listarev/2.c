#include <stdio.h>
#include <stdlib.h>

typedef struct teste {
    int inteiro;
    float real;
    char nome[10];
} informacao;

/*int main()
{
    informacao *p, x = { 321, 2.39, "Silva" };
    p = &x; //(struct teste *) malloc(sizeof(struct teste));
    if( p )
        printf("valores da struct X: %i %f %s\n", p->inteiro, p->real, p->nome );
    else
        printf("o ponteiro esta anulado\n");

    return 0;
}*/

int main()
{
    int a=10, vet[ ]={1,2,3,4,5}, *p=NULL;
    float b=35.75;
    informacao y = {31, 2.35, "Wilson"};
    void *ptr; // Declaracao de um ponteiro para um tipo genérico (void)
    ptr=&a; // Atribuindo o endereço de um inteiro.
    printf("a = %d \n", * ( (int*) ptr) );
    ptr=&b; // Atribuindo o endereço de um float.
    printf("b = %f \n",*( (float*) ptr) );
    ptr= &y;
    printf("nome= %s, idade = %i \n\n", ((informacao*) ptr)->nome,((informacao*) ptr)->inteiro);
    printf("\n\n Acessando um vetor por aritmetica de ponteiro void\n");
    ptr=vet;
    for (int i =0;i<6;i++,ptr++)
    printf("vet[%i] = %i \n", i, *( (int*) ptr) );
    return 0;
}