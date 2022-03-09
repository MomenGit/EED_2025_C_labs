#include <stdio.h>

void main(void)
{
    int grade;
    printf("Input your grade:\n");
    scanf("%d", &grade);
    /*
    ** using the ... means in range of
    ** so (90 ... 100) is equivalent to (x >= 90 && x <= 100)
    ** learn more from here: https://www.geeksforgeeks.org/using-range-switch-case-cc/
    */
    switch (grade)
    {
    case 90 ... 100:
        printf("Grade A\n");
        break;
    case 80 ... 89:
        printf("Grade B\n");
        break;
    case 70 ... 79:
        printf("Grade C\n");
        break;
    case 60 ... 69:
        printf("Grade D\n");
        break;
    default:
        printf("Grade F\n");
        break;
    }
}