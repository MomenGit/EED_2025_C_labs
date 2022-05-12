#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr; // *p = 1
    ++*p;         // *p = 2
    p += 2;       // *p = 3 (The third element in the array)
    printf("%d", *p);
    return 0;
}