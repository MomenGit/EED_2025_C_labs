#include <stdio.h>
#include <math.h>

void main(void)
{
    float radius, centerX, centerY, pointX, pointY;
    printf("Input the radius of the circle and its center coordinates respectively radius X Y\n");
    scanf("%f %f %f", &radius, &centerX, &centerY);
input:
    printf("Input the coordinates of your point respectively X Y\n");
    scanf("%f %f", &pointX, &pointY);

    /*
    ** Calculate the magnitude (AKA length) of the line joining the entered point and the center point
    ** The magnitude is calculated by the equation: squareRootOf( (x2-x1)^2 + (y2-y1)^2 )
    ** If the magnitude of the line is smaller than or equal to the radius of the circle
    ** then the point lies within the circle
    ** else if it is greater than the radius then the point lies outside of the circle
    */
    double length = sqrt(pow(pointX - centerX, 2) + pow(pointY - centerY, 2));
    if (length < radius)
    {
        printf("Point lies within the circle\n");
    }
    else
    {
        printf("Point lies outside the circle, input another point\n");
        /* In case the point is outside goto the input line to enter another point and repeat the process */
        goto input;
    }
}