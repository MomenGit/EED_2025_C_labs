#include <stdio.h>

int gCD(int, int);

int main()
{
    int num1, num2;
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);
    printf("%d\n", gCD(num1, num2));
    return 0;
}

int gCD(int dividend, int divisor)
{
    if (divisor > dividend)
        dividend ^= divisor ^= dividend ^= divisor;
    if (dividend % divisor == 0)
        return divisor;

    gCD(divisor, dividend % divisor);
}