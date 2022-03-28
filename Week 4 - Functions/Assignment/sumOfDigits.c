#include <stdio.h>
#include <math.h>

int sumOfDigits(int, int);

int main()
{
    int input, digitsNum, sum = 0;

    /* Check if the input number is between the range of digits */
    printf("Enter a number:\n");
    scanf("%d", &input);

    printf("%d\n", sumOfDigits(input, 0));
    return 0;
}

int sumOfDigits(int number, int sum)
{
    if (!number)
        return sum;
    sum += (number / (int)powf(10, (int)log10f(number)) % 10);
    number -= (number / (int)powf(10, (int)log10f(number)) % 10) * powf(10, (int)log10f(number));
    sumOfDigits(number, sum);
}