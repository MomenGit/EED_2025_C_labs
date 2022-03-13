#include <stdio.h>

int main(void)
{
    /* A char could be explicitly casted to a number type ex: int, float or double */
    char input;

    printf("Enter a character:\n");
    scanf("%c", &input);
    if (input > 127)
    {
        printf("Not in ASCII codes\n");
        return 1;
    }

    printf("Classifcation in ASCII codes: ");
    /* Check which range does the entered character belongs to using the ... operator in a switch statement */
    switch (input)
    {
    case 48 ... 57:
        printf("digit\n");
        break;
    case 65 ... 90:
        printf("Upper-case letter\n");
        break;
    case 97 ... 122:
        printf("Lower-case letter\n");
        break;
    /*
    ** We made sure before that the entered character is smaller than or equal 127 (check the if statement above).
    ** Then in case that it doesn't belong to any of the above cases, then it is a special symbol.
    */
    default:
        printf("Special Symbols\n");
        break;
    }
    return 0;
}