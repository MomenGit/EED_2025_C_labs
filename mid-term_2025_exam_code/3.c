#include <stdio.h>

void main()
{
    char *initialized = "a";
    char *null_pointer = NULL;
    char *uninitialized;
    printf("-%s\n-%s\n-%s\n", initialized, null_pointer, uninitialized);
}