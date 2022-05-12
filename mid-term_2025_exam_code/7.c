#include <stdio.h>

void main()
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d", i);
        /* The keyword continue is used to come out of a loop only for that iteration */
        if (i < 3)
            continue;
        /* The keyword break is used to come out of the whole loop */
        else
            break;
    }
}