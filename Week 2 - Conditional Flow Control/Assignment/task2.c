#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float r, x, y, px, py;
    printf("Enter the circle's radius and center coordinates: ");
    scanf("%f%f%f", &r, &x, &y);
    printf("Enter a point: ");
    while (1)
    {
        scanf("%f%f", &px, &py);
        if (sqrtf(powf(px - x, 2) + powf(py - y, 2)) > r)
        {
            printf("Point is outside the circle. Enter another point: \n");
        }
        else
        {
            printf("Point is inside the circle.\n");
            break;
        }
    }
}
