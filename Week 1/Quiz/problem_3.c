#include <stdio.h>
/*
#define PI 3.14
*/
void main(void)
{
    const float PI = 3.14;
    float radius, height;

    printf("Enter properties of cylinder respectively radius height:\n");
    scanf("%f %f", &radius, &height);
    /* prints the volume of cylinder as volume = pi x r^2 x h */
    printf("The volume of cylinder = %.2f\n", PI * radius * radius * height);

    /* prints the surface area of cylinder as surface area = (pi x r^2 x 2) + (2 x pi x r x h)
    ** where pi x r^2 x 2 is the area of the two circles of cylinder
    ** where 2 x pi x r x h is the lateral area of the cylinder
    */
    printf("The surface area of cylinder = %.2f\n", (PI * radius * radius * 2) + (2 * PI * radius * height));

    /* prints the surface area of cylinder without top cover as it equals (pi x r^2) + (2 x pi x r x h)*/
    printf("The surface area of cylinder without a top cover = %.2f\n", (PI * radius * radius) + (2 * PI * radius * height));
}