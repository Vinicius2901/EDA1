typedef union element
{
    int a;
    float b;
} Element;

typedef struct MultiPile{
    int topo1,topo2, tamVet;
    Element *v;
} MultiPile;

MultiPile criaPilha( int n );

void destroiPilha( MultiPile *p );

int empilha(MultiPile *p, Element e, int s);

int cheia( MultiPile *p );

int vazia( MultiPile *p);