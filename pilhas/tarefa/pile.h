typedef union element
{
    int a;
    float b;
} Element;

typedef struct MultiPile{
    int topo1,topo2, tamVet;
    Element *v;
} MultiPile;

void destroiPilha( MultiPile *p );