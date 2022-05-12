#include <stdio.h>

void main()
{
    int x = 10000;
    double y = 56;
    int *p = &x;
    double *q = &y;
    printf("p and q are %d and %d", sizeof(p), sizeof(q));
}