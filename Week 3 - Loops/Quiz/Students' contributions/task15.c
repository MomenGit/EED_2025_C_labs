#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    printf("Enter pair of numbers: ");
    scanf("%i %i", &x, &y);
    while(y)
        x = x + y - (y = x), y %= x;
    printf("GCD is %i.", x);
}