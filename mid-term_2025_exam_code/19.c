#include <stdio.h>

int main()
{
    int i = 512, counter = 0;
    /* binary representation of i is 1000000000
    ** which is pow(2,9) and it is a 10 digits binart number
    ** each loop the i shifted left by 1 digit till it becomes 0 after 10 loops
    */
    for (; i; i >>= 1)
        printf("hello %d\n", ++counter);
    return 0;
}