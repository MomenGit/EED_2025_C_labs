#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%i", &n);
    printf("Number divisible by 5 or 7 are:\n");
    for (int i = 5, j = 7; i <= n || j <= n;)
    {
        if (i < j)
        {
            printf("%i ", i);
            i += 5;
        }
        else if (j < i)
        {
            printf("%i ", j);
            j += 7;
        }
        else
        {
            printf("%i ", i);
            i += 5, j += 7;
        }
    }
}