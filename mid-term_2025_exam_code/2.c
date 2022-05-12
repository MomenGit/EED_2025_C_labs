#include <stdio.h>

void main()
{
    char *a[10] = {"hi", "hello", "how"};
    int i = 0;
    for (i = 0; i < 10; i++)
        printf("%s", a[i]);
}