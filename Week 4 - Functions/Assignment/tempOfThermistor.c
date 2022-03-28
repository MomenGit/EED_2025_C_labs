#include <stdio.h>

int temperatureCalc(float resistance, float *temperature);
float temperature;

int main()
{
    float resistance;
    printf("Enter a valid resistance value:\n");
    scanf("%f", &resistance);

    if (temperatureCalc(resistance, &temperature))
        printf("Temperature = %.2f\n", temperature);
    else
        printf("Invalid range, please enter a valid resistance value between 973 Ohm and 10 kOhm.\n");

    return 0;
}

int temperatureCalc(float resistance, float *temperature)
{
    if (resistance <= 10000 && resistance >= 973)
        *temperature = (resistance - 13009) / -120.36;
    else
        return 0;
    return 1;
}