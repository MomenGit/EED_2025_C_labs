#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int **binaryGeneration(int, int, int **);
int **grayGeneration(int, int, int **);

int main()
{
    int bits, combinations;
    printf("Enter number of bits: ");
    scanf("%d", &bits);
    combinations = powf(2, bits);
    int **grayCode = grayGeneration(bits, combinations, grayCode);

    for (int i = 0; i < combinations; i++)
    {
        for (int j = 0; j < bits; j++)
            printf("%d", *(*(grayCode + i) + j));
        printf("\n");
    }
    return 0;
}

int **binaryGeneration(int bits, int combinations, int **binaryCodes)
{
    int number;
    binaryCodes = (int **)calloc(combinations, sizeof(int *));
    for (int i = 0; i < combinations; i++)
    {
        number = i;
        *(binaryCodes + i) = (int *)calloc(bits, 4);
        for (int j = bits - 1; j >= 0; j--)
        {
            *(*(binaryCodes + i) + j) = number % 2;
            number /= 2;
        }
    }
    return binaryCodes;
}
int **grayGeneration(int bits, int combinations, int **grayCode)
{
    int **binaryCode = binaryGeneration(bits, combinations, binaryCode);
    grayCode = (int **)calloc(combinations, sizeof(int **));
    for (int i = 0; i < combinations; i++)
    {
        *(grayCode + i) = (int *)calloc(bits, 4);
        for (int j = 0; j < bits; j++)
            *(*(grayCode + i) + j) = (!j) ? (int)*(*(binaryCode + i) + j) : (int)*(*(binaryCode + i) + j) ^ (int)*(*(binaryCode + i) + j - 1);
    }
    return grayCode;
}