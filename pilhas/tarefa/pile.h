
typedef union element
{
    int a;
    float b;
} Element;

typedef struct MultiPile{
    int topo1,topo2, tamVet;
    Element *v;
} MultiPile;

MultiPile* criaPilha(int n );

void destroiPilha( MultiPile **p );

// s = true -> int, s = false -> float
int empilha(MultiPile *p, Element e, int s);

int cheia( MultiPile *p );

int vazia( MultiPile *p);

int numElements(MultiPile *p);

// s = true -> pilha Int, s = false -> pilha Float
Element top(MultiPile *p , int s);

// s = true -> pilha Int, s = false -> pilha Float
Element desempilha(MultiPile *p, int s);

void reinicia(MultiPile *p);