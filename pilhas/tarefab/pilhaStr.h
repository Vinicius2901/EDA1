
// Define uma pilha ciclica de strings
typedef struct pilhaStr{
    int capacity, position;
    char **container;
} Pile;

Pile* criaPilha(int n);

int emplaceStr(char *s, Pile *p);

char* topStr(Pile *p);

char* desempilhaStr(Pile *p);

