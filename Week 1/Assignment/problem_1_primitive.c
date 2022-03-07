#include <stdio.h>

int main()
{
    int input;

    printf("Enter a 5 digit number:\n");
    scanf("%d", &input);

    printf("The reversed number is: ");
    int tenThousands = input / 10000;
    input -= tenThousands * 10000;
    int thousands = input / 1000;
    input -= thousands * 1000;
    int hundreds = input / 100;
    input -= hundreds * 100;
    int tenth = input / 10;
    input -= tenth * 10;
    int unit = input;
    printf("%d%d%d%d%d\n", unit, tenth, hundreds, thousands, tenThousands);
    return 0;
}