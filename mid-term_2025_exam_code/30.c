#include <stdio.h>

int main()
{
    int a[10];
    printf("size of array: %d\n", sizeof(a));
    printf("size of array element: %d\n", sizeof(a[0]));
    printf("length of array: %d\n", sizeof(a) / sizeof(a[0]));
    return 0;
}