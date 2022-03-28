#include <stdio.h>
#include <math.h>

int isArmstrongNumber(int number);
int main()
{
    int input;
    /* Check if the input number is between the range of digits */

    printf("Enter a number:\n");
    scanf("%d", &input);

    printf((isArmstrongNumber(input)) ? "It is an Armstrong number.\n" : "Not an Armstrong number.\n");

    return 0;
}
int isArmstrongNumber(int number)
{
    int armStrong = 0, numberOfDigits = (int)log10f(number *= (number < 0) ? -1 : 1) + 1;
    for (int i = 0; i < numberOfDigits; i++)
        armStrong += powf((number / (int)powf(10, i) % 10), numberOfDigits);

    if (armStrong == number)
        return 1;
    else
        return 0;
}