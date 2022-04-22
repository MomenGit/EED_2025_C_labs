#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int **grayCodeGenerate(int **grayCode, int bits);
int *generateBinaryBits(int *, int n, int bits);

int main()
{
    int bits, combinations, **grayCode;
    printf("Enter number of bits: ");
    scanf("%d", &bits);
    combinations = powf(2, bits);
    grayCode = grayCodeGenerate(grayCode, bits);
    for (int i = 0; i < combinations; i++)
    {
        for (int j = 0; j < bits; j++)
        {
            printf("%d", *(*(grayCode + i) + j));
        }
        printf("\n");
    }

    return 0;
}
int **grayCodeGenerate(int **grayCode, int bits)
{
    int combinations = powf(2, bits);
    grayCode = (int **)calloc(combinations, sizeof(int *));
    for (int i = 0; i < combinations; i++)
    {
        *(grayCode + i) = generateBinaryBits(*(grayCode + i), i ^ (i >> 1), bits);
    }
    return grayCode;
}
int *generateBinaryBits(int *binary, int n, int bits)
{
    binary = (int *)calloc(bits, 4);
    for (int i = bits - 1; i >= 0; i--)
    {
        *(binary + i) = n % 2;
        n /= 2;
    }
    return binary;
}