#include <stdio.h>

int main()
{
    float px, py, qx, qy;
    printf("A program that calculates the reflection of point P across point Q\nto be a 180 degree rotation of point P around point Q\n\nEnter the two points in the given order Px Py Qx Qy:\n");

    scanf("%f %f %f %f", &px, &py, &qx, &qy);
    printf("The reflection of point P across point Q is: (%.2f,%.2f)\n", 2 * qx - px, 2 * qy - py);
    return 0;
}