#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sum = 0;
    printf("Enter n: ");
    scanf("%i", &n);
    for (int i = 1; i <= n; sum += i, i += 2)
        ;
    printf("Sum of odd numbers from 1 to %i is %i.\n", n, sum);
}