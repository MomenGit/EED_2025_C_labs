#include <stdio.h>
#include <stdlib.h>
void main()
{
    int *p = (int *)0x1000;
    printf("%x\n", p + 5);
}