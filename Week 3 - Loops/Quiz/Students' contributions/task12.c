#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    unsigned long long int product = 1;
    printf("Enter n: ");
    scanf("%i", &n);
    for (int i = 2; i <= n; product *= i, i += 2)
        ;
    printf("Product of even numbers from 1 to %i is %llu.\n", n, product);
}