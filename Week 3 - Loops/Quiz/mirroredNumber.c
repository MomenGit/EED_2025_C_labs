#include <stdio.h>
#include <math.h>

int main()
{
    int number, digits, isMirrored = 0;
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

    for (int i = 0; i < digits / 2; i++)
    {
        if ((number / (int)powf(10, i) % 10) == (number / (int)powf(10, digits - i - 1) % 10))
        {
            isMirrored = 1;
        }
        else
        {
            isMirrored = 0;
        }
    }
    if (isMirrored)
        printf("Number is mirrored\n");
    else
        printf("Number is not mirrored\n");
}