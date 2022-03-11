#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("Enter your character: ");
    scanf("%c", &c);
    if (c >= 65 && c <= 90)
        printf("upper-case letter\n");
    else if (c >= 97 && c <= 122)
        printf("lower-case letter\n");
    else if (c >= 48 && c <= 57)
        printf("digit\n");
    else
        printf("special symbol\n");
}
