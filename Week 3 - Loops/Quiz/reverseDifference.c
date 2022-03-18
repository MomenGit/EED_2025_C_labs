#include <stdio.h>
#include <math.h>

int main()
{
    int number, reversed = 0, digits;
    do
    {
        printf("Enter number of digits:\n");
        scanf("%d", &digits);
    } while (digits < 1);
    do
    {
        printf("Enter a %d number:\n", digits);
        scanf("%d", &number);
    } while (number >= powf(10, digits - 2) && number <= powf(10, digits - 1));

    for (int i = 0; i < digits; i++)
    {
        reversed += (number / (int)powf(10, i) % 10) * powf(10, digits - i - 1);
    }
    if ((number / (int)powf(10, 0) % 10) * powf(10, digits - 1) == 0)
    {
        reversed *= 10;
    }

    printf("Reversed: %d\n", reversed);
    printf("Difference = %d\n", reversed, number, reversed - number);
}