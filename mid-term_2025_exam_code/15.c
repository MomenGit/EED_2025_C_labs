#include <stdio.h>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        switch (i)
        {
        case 0:
            i += 3;
        case 1:
            i += 2;
        case 5:
            i += 3;
        default:
            i += 2;
            break;
        }
        printf("%d ", i);
    }
    return 0;
}