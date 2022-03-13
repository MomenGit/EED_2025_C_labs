#include <stdio.h>
#include <stdlib.h>

int main()
{
    int code;
    printf("Enter the code: ");
    scanf("%i", &code);
    switch (code)
    {
    case 0:
        printf("Decoded Message: The enemies are about to attack.");
        break;
    case 1:
        printf("Decoded Message: The enemies are summoning new forces.");
        break;
    case 2:
        printf("Decoded Message: The enemies are withdrawing their forces.");
        break;
    }
}
