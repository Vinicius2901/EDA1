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

int empilhai(MultiPile *p, int e );

int empilhaf( MultiPile *p, float e );

int cheia( MultiPile *p );

int vazia( MultiPile *p);