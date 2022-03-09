#include <stdio.h>
void main(void)
{
    float point1x, point1y, point2x, point2y;

    printf("Enter the two points in the given order point1_x point1_y point2_x point2_y:\n");
    scanf("%f %f %f %f", &point1x, &point1y, &point2x, &point2y);

    /* Calculates the slope m of the straight line connecting the two points P1 & P2
    ** Slope of straight line m = (Y2-Y1) / (X2-X1)
    */
    float m = (point2y - point1y) / (point2x - point1x);

    /* Calculates the interseption c of the straight line with the y-axis
    ** By substituting with a given point in the line equation as c = y - mx
    */
    float c = point1y - m * point1x;
    printf("The line equation: y = %.2fx + %.2f\n", m, c);

    /**/
    printf("The mid-point = (%.2f,%.2f)\n", (point1x + point2x) / 2, (point1y + point2y) / 2);
}