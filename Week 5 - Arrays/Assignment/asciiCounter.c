#include <stdio.h>
#include <string.h>

#define size 100

void countAscii(char *);
int main()
{
    char sentence[size];
    countAscii(sentence);
    return 0;
}

void countAscii(char *sentence)
{
    int alphas = 0, digits = 0, specialChars = 0;
    printf("Type a sentence:\n");
    scanf("%[^\n]s", sentence);
    for (int i = strlen(sentence); i >= 0; i--)
    {
        switch (sentence[i])
        {
        case 48 ... 57:
            digits++;
            break;
        case 65 ... 90:
        case 97 ... 122:
            alphas++;
            break;
        /*
        ** We made sure before that the entered character is smaller than or equal 127 (check the if statement above).
        ** Then in case that it doesn't belong to any of the above cases, then it is a special symbol.
        */
        default:
            specialChars++;
            break;
        }
    }
    /* As the end condition for the loop was the null character so it wasn't counted we need to increment by 1 to count it*/
    printf("Number of alpha = %d\nNumber of digits = %d\nNumber of special char = %d\n", alphas, digits, specialChars);
}