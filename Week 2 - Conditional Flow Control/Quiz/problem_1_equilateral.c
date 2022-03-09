#include <stdio.h>

void main(void)
{
    float a, b, c;
    printf("Enter the sides' lengths of the triangle respectively a b c:\n");
    scanf("%f %f %f", &a, &b, &c);

    /* Check that the entered lengths aren't zeros */
    if (!(a == 0 || b == 0 || c == 0))
    {
        /* Check that the sum of any two lengths is bigger than the third length */
        if (a + b > c && a + c > b && b + c > a)
        {
            printf("These sides could represent a triangle\n");
            /*
             ** Check that a equals b and c, then b euqals c also and a = b = c
             ** then these side represent an equilateral triangle
             */
            (a == b && a == c) ? printf("**It is an equilateral triangle**\n") : printf("But it is not an equilateral triangle\n");
        }
        else
        {
            printf("These sides couldn't represent a triangle\n");
        }
    }
    else
    {
        printf("Please input valid lengths\n");
    }
}