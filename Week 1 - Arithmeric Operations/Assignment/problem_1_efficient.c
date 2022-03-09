#include <stdio.h>

int main()
{
    int input;
    printf("Enter a 5 digit number:\n");
    scanf("%d", &input);
    /*
    ** This solution depends on the division by the weight of the digit
    ** and the remainder by weight of 10
    ** Ex: 12345 / 10^3 we get 12 and 12 % 10 we get 2 which is the digit of the weight 10^3, and so on
    */
    printf("%d%d%d%d%d", input % 10, input / 10 % 10, input / 100 % 10, input / 1000 % 10, input / 10000 % 10);
    return 0;
}