#include <stdio.h>
#include <math.h>

float whichIsGreater(float, float);
float whichIsGreator(float, float);

float main()
{
    float number1, number2;
    printf("Enter two numbers:\n");
    scanf("%f %f", &number1, &number2);

    whichIsGreater(number1, number2);
    whichIsGreator(number1, number2);

    return 0;
}

float whichIsGreater(float num1, float num2)
{
    if (num1 < 0 || num2 < 0)
        return 0;
    if (num1 > num2)
    {
        printf("first number %.2f is greater.\n", num1);
        return num1;
    }
    else if (num1 < num2)
    {
        printf("second number %.2f is greater.\n", num2);
        return num2;
    }
    else
        printf("the two numbers are equal.\n");
    return 1;
}
float whichIsGreator(float num1, float num2)
{
    if (num1 < 0 || num2 < 0)
        return 0;
    switch ((int)ceilf((num1 / num2)))
    {
    case 1:
        printf("the two numbers are equal.\n");
        break;
    case 0:
        printf("second number %.2f is greater.\n", num2);
        return num2;
        break;
    default:
        printf("first number %.2f is greater.\n", num1);
        return num1;
        break;
    }
    return 1;
}