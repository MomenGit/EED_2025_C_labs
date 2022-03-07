#include <stdio.h>

int unsignedIntPowf(int base, int power);
int main()
{
    int input, digitsNum;
    /* Check if the input number of digits is bigger than one */
    do
    {
        printf("Enter number of digits:\n");
        scanf("%d", &digitsNum);
    } while (!(digitsNum >= 1));

    /* Check if the input number is between the range of digits */
    do
    {
        printf("Enter a %d digit number:\n", digitsNum);
        scanf("%d", &input);
    } while (!(input >= unsignedIntPowf(10, digitsNum - 1) && input < unsignedIntPowf(10, digitsNum)));

    printf("The reversed number is: ");
    /*
    ** Each loop divide the input by the weight of the digit to be printed
    ** and then the remainder by weight of 10
    ** Ex: 12345 / 10^3 we get 12 and 12 % 10 we get 2 which is the digit of the weight 10^3, and so on
    */
    for (int i = 0; i < digitsNum; i++)
    {

        printf("%d", input / unsignedIntPowf(10, i) % 10);
    }
    printf("\n");
    return 0;
}

int unsignedIntPowf(int base, int power)
{
    int powered = 1;
    /* If the power was negative convert it to positve by (x -1)*/
    if (power < 0)
    {
        power *= -1;
    }
    /* Multiply the powered by the base by n times where n equals the power */
    for (int i = 1; i <= power; i++)
    {
        powered *= base;
    }
    return powered;
}