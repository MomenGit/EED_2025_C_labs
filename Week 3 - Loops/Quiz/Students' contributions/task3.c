#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y = 0;
    printf("Enter your number: ");
    scanf("%i", &x);
    for (int i = 0; i <= (int)log10(x); i++)
    {
        y *= 10;
        y += (x / (int)pow(10, i)) % 10;
    }
    printf("%i - %i = %i\n", y, x, y - x);
}