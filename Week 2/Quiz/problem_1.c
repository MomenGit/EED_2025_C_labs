#include <stdio.h>
#include <math.h>

void main(void)
{
    float a, b, c;
    printf("Enter the sides' lengths respectively a b c\n");
    scanf("%f %f %f", &a, &b, &c);
    /* Check that the entered lengths aren't zeros */
    if (!(a == 0 || b == 0 || c == 0))
    {

        /* Check that the sum of any two lengths is bigger than the third length */
        if (a + b > c && a + c > b && b + c > a)
        {
            printf("These sides could represent a triangle\n");
            /*
            ** Check if the square of any side length is equal to the sum of the squares of the other two sides' lengths
            ** Then this is a right-angled triangle
            */
            if (powf(a, 2) == powf(b, 2) + powf(c, 2) || powf(b, 2) == powf(a, 2) + powf(c, 2) || powf(c, 2) == powf(a, 2) + powf(b, 2))
            {
                printf("It is a right-angled triangle\n");
            }
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