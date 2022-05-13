#include <stdio.h>
#include <stdlib.h>
void main()
{
    int *p = (int *)malloc(sizeof(int *));
    *p = 1000;
    printf("%x\n", p + 5);
    printf("%d\n", p + 5);
}