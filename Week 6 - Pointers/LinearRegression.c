#include <stdio.h>

void input_vector(float *vect, int size);
float find_average(float *vect, int size);
float calc_y_intercept(float y_mean, float x_mean, float b);
float calc_slope(float *vect_x, float *vect_y, int size);

int main()
{
    int n = 0;
    printf("Enter vector size: ");
    scanf("%d", &n);
    float vect_x[n];
    float vect_y[n];
    printf("Enter vector X: ");
    input_vector(vect_x, n);
    printf("Enter vector Y: ");
    input_vector(vect_y, n);

    float x_mean = find_average(vect_x, n);
    float y_mean = find_average(vect_y, n);
    float b = calc_slope(vect_x, vect_y, n);
    float a = calc_y_intercept(y_mean, x_mean, b);
    
    printf("Y = %.2f + %.2fX\n", a, b);
    return 0;
}

void input_vector(float *vect, int size)
{
    
    int i = 0;
    for(i = 0; i < size; i++)
    {
        scanf("%f", (vect+i));
    }
}

float find_average(float *vect, int size)
{
    int i = 0;
    float sum = 0;
    float average = 0;
    
    for(i = 0; i < size; i++)
    {
        sum+=vect[i];
    }
    
    average = sum / size;
    
    return average;
}

float calc_slope(float *vect_x, float *vect_y, int size)
{
    float sigma_yx = 0;
    float sigma_x2 = 0;
    float sigma_x = 0;
    float sigma_y = 0;
    float b = 0;
    int i = 0;
    
    for(i = 0; i < size; i++)
    {
        sigma_yx += (vect_x[i] * vect_y[i]);
        sigma_x2 += (vect_x[i] * vect_x[i]);
        sigma_x += (vect_x[i]);
        sigma_y += (vect_y[i]);
    }
    
    b = ((size * sigma_yx) - (sigma_x * sigma_y))/((size * sigma_x2) - (sigma_x * sigma_x));
    
    return b;
}

float calc_y_intercept(float y_mean, float x_mean, float b)
{
    float a = y_mean - (b * x_mean);
    
    return a;
}