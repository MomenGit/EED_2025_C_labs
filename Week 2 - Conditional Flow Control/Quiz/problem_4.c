#include <stdio.h>

void main(void)
{
    int number, firstDigits, secondDigits, thirdDigits;
    char char1, char2, char3;
input:
    printf("A=97, B=98 & C=99\nEnter a 6 digit number to print its ABC code:\n");
    scanf("%d", &number);

    /* Check that the entered number is a six digit number */
    if (!(number >= 100000 && number <= 1000000))
    {
        goto input;
    }

    /* Distribute the 6 digit number across three variables each of 2 digits only */
    /* If input is 979899 then 979899 / 10000 = 97 */
    firstDigits = number / 10000;
    /* If input is 979899 then 979899 / 100 = 9798 and 9798 % 100 = 98 */
    secondDigits = number / 100 % 100;
    /* If input is 979899 then 979899 % 100 = 99 */
    thirdDigits = number % 100;

    /* Check that the entered digits are within the table from 97 to 99 if not goto input */
    if (!(firstDigits >= 97 && firstDigits <= 99) || !(secondDigits >= 97 && secondDigits <= 99) || !(thirdDigits >= 97 && thirdDigits <= 99))
    {
        printf("\nYour code is wrong and out of range\n\n");
        goto input;
    }
    /* If the first two digits equals 97 return A, else if 98 return B, else if 99 return C or else return null character */
    char1 = (firstDigits == 97) ? 'A' : (firstDigits == 98) ? 'B'
                                    : (firstDigits == 99)   ? 'C'
                                                            : '\0';
    /* If the second two digits equals 97 return A, else if 98 return B, else if 99 return C or else return null character */
    char2 = (secondDigits == 97) ? 'A' : (secondDigits == 98) ? 'B'
                                     : (secondDigits == 99)   ? 'C'
                                                              : '\0';
    /* If the third two digits equals 97 return A, else if 98 return B, else if 99 return C or else return null character */
    char3 = (thirdDigits == 97) ? 'A' : (thirdDigits == 98) ? 'B'
                                    : (thirdDigits == 99)   ? 'C'
                                                            : '\0';

    printf("**%c%c%c**\n", char1, char2, char3);
}