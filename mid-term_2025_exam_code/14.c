#include <stdio.h>

int main()
{
    int i;
    int sum = 1;
    for (i = 1; i <= 5; i++)
        ;
    {
        sum = sum * i;
    }
    printf("%d", sum);
    return 0;
}