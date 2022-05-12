#include <stdio.h>

int main()
{
    int X = 40;
    {
        int X = 20;
        printf("%d ", X);
    }
    printf("%d\n", X);
    return 0;
}