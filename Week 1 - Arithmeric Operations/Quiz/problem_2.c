#include <stdio.h>

void main(void)
{
    float a, b, c, d, e;

    printf("A 4th order equation aX^4 + bX^3 + cX^2 + dX^1 + e\nEnter the coeffcients in the given order a b c d e to differentiate the equation:\n");
    scanf("%f %f %f %f %f", &a, &b, &c, &d, &e);
    /* Given aX^4 by differentiation we get 4 x aX^3 and so on */
    printf("The differentiated version is: %.2fX^3 + %.2fX^2 + %.2fX + %.2f\n", a * 4, b * 3, c * 2, d);
}