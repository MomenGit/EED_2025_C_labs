#include <stdio.h>

int main()
{
    int *p = (int *)0x4000;
    int *x = p + 4;
    double x_coord = *(double *)(p + 4);
    return 0;
}