#include <stdio.h>

int main(void)
{
    int *p=NULL, **pp=NULL, x = 321, y=101;
    p = &x;
    pp=&p;
    *p= -3;
    y=**pp;
    printf("p: %p \npp: %p \n&x: %p \n&p: %p\n", p, pp, &x, &p);
}