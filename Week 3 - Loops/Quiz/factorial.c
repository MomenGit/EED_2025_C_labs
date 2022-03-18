#include <stdio.h>

int main()
{
    int n, factorial = 1;
    printf("Enter a number:\n");
    scanf("%d", &n);
    printf("%d! = ");
    /*
    ** starts with n which is the number entered by user
    ** then each loop multiplies n to the last value of the factorial then decrements n by 1
    */
    for (; n >= 1; n--)
    {
        factorial *= n;
    }
    printf("%d \n", factorial);
    return 0;
}