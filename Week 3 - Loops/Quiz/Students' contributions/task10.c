#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%i", &n);
    printf("Sum of numbers from 1 to %i is %i.\n", n, n * (n + 1) / 2);
}