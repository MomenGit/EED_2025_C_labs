#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%i", &n);
    for (int i = 0; i <= (int)log10(n); i++)
    {
        int y = (n / (int)pow(10, i)) % 10;
        printf("%i is %sdivisible by %i\n", n, n % y ? "not " : "", y);
    }
}