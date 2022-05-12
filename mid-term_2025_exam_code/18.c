#include <stdio.h>

void swap(int *num1, int *num2)
{
    *num1 ^= *num2 ^= *num1 ^= *num2;
    // int temp = *num1;
    // *num1 = *num2;
    // *num2 = temp;
}

int main()
{
    int array[] = {3, 5, 1, 4, 6, 2};
    int done = 0;
    int i;
    while (done == 0)
    {
        done = 1;
        for (i = 0; i <= 4; i++)
        {
            if (array[i] < array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
                done = 0;
            }
        }
        for (i = 5; i >= 1; i--)
        {
            if (array[i] > array[i - 1])
            {
                swap(&array[i], &array[i - 1]);
                done = 0;
            }
        }
    }
    printf("%d", array[3]);
}