#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int *ptr1 = arr;
    int *ptr2 = arr + 5;
    // char *x = (char *)ptr2;
    // char *y = (char *)ptr1;
    // long int z = x - y;
    // int *q = x - y;
    // int *c = ptr2 - ptr1;
    // int *w = ptr2 - y;
    printf("%d,", (ptr2 - ptr1));
    printf("%d", (char *)ptr2 - (char *)ptr1);
}