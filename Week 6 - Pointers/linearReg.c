#include <stdio.h>
#include <stdlib.h>

float *vector(int);
float slope(float *, float *, int);
float intercept(float *, float *, float, int);
char *regEquation(float *, float *, int);
float summation(float *v, int size);
float sampleMean(float *v, int size);

int main()
{
    int size;
    float *vec1, *vec2;
    printf("Enter size of vectors:\n");
    scanf("%d", &size);
    printf("Enter elements of the first vector:\n");
    vec1 = vector(size);
    printf("Enter elements of the second vector:\n");
    vec2 = vector(size);
    char *equation = regEquation(vec1, vec2, size);
    printf("The line equation:\n%s\n", equation);
    return 0;
}
float *vector(int size)
{
    float *vec = (float *)calloc(size, sizeof(float));
    for (int i = 0; i < size; i++)
    {
        printf("[%d]=", i);
        scanf("%f", (vec + i));
        printf("\n");
    }
    return vec;
}
char *regEquation(float *v1, float *v2, int size)
{

    float b = slope(v1, v2, size);
    char *equation = (char *)malloc(19);
    sprintf(equation, "y = %.1fx + (%.1f)", b, intercept(v1, v2, b, size));
    return equation;
}
float slope(float *v1, float *v2, int size)
{
    float sumV1 = summation(v1, size), sumV2 = summation(v2, size), sumV1V2 = 0, sumV1Squared = 0;
    for (int i = 0; i < size; i++)
    {
        sumV1Squared += *(v1 + i) * *(v1 + i);
        sumV1V2 += *(v2 + i) * *(v1 + i);
    }
    return (size * sumV1V2 - sumV1 * sumV2) / (size * sumV1Squared - sumV1 * sumV1);
}
float intercept(float *v1, float *v2, float slope, int size)
{
    return sampleMean(v2, size) - slope * sampleMean(v1, size);
}
float sampleMean(float *v, int size)
{
    return summation(v, size) / size;
}
float summation(float *v, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(v + i);
    }
    return sum;
}