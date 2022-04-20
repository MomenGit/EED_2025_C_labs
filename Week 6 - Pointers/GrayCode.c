#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binaryGrayConversion(int gray);
void GrayCode(int *GrayCodesArr, int bits);
void printGrayDigits(int *GrayCodesArr, int bits);


int main()
{
    int bits = 0;
    printf("Enter number of bits: ");
    scanf("%d", &bits);
    int *GrayCodes = (int*)malloc(sizeof(int) * (int)pow(2, bits));
    GrayCode(GrayCodes, bits);
    
    printGrayDigits(GrayCodes, bits);
    printf("\n");
    free(GrayCodes);
    return 0;
}

int binaryGrayConversion(int gray) {
   if (!gray)
      return 0;
   int a = gray % 10;
   int b = (gray / 10) % 10;
   if ((a && !b) || (!a && b))
      return (1 + 10 * binaryGrayConversion(gray / 10));
   return (10 * binaryGrayConversion(gray / 10));
}

void GrayCode(int *GrayCodesArr, int bits)
{
    int i = 0;
    for(i = 0; i < (int)pow(2, bits); i++)
    {
        *(GrayCodesArr + i) = 0;
    }

    for(i = 0; i < (int)pow(2, bits); i++)
    {
        int dec = i;
        int rem, j = 1;

        while (j!=0)
        {
            rem = dec % 2;
            dec /= 2;
            *(GrayCodesArr + i) += rem * j;
            j *= 10;
        }
    }

    for(i = 0; i < (int)pow(2, bits); i++)
    {
        *(GrayCodesArr + i) = binaryGrayConversion(*(GrayCodesArr + i));
        //printf("%04d\n", GrayCodesArr[i]);
    }
}

void printGrayDigits(int *GrayCodesArr, int bits)
{
    int i = 0;
    for(i = 0; i < (int)pow(2, bits); i++)
    {
        //printf("here and i= %d\n", i);
        int bitString[bits];
        int digits = bits;
        int bitCounter = 0;
        int j = 0;
        int r = 0;
        while (digits != 0) {
            //printf("here and bits= %d\n", bits);
            r = *(GrayCodesArr + i) % 10;
            bitString[bitCounter] = r;
            bitCounter++;
            *(GrayCodesArr + i) = *(GrayCodesArr + i) / 10;
            digits--;
        }
        for (j = bitCounter - 1; j > -1; j--) {
            printf("%d ", bitString[j]);
        }
        printf("\n");
    }
}