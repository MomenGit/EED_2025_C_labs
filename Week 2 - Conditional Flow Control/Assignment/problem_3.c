#include <stdio.h>
void main(void)
{
    int messageCode;
    printf("Leave your message:\n");
    scanf("%d", &messageCode);
    switch (messageCode)
    {
    case 0:
        printf("The enemies are about to attack.\n");
        break;
    case 1:
        printf("The enemies are summoning new forces.\n");
        break;
    case 2:
        printf("The enemies are withdrawing their forces.\n");
        break;
    }
}