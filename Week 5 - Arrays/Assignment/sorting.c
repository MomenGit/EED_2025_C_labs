#include <stdio.h>
#include <string.h>

void selectionSort(int *, int);
void bubbleSort(int *, int);

int main(void)
{
    int arraySize;
    printf("Enter array size:\n");
    scanf("%d", &arraySize);
    int unsortedArray[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        printf("[%d]: ", i);
        scanf("%d", &unsortedArray[i]);
    }
    printf("\n");

    selectionSort(unsortedArray, arraySize);
    // bubbleSort(unsortedArray, arraySize);

    for (int i = 0; i < arraySize; i++)
    {
        printf("%i  ", unsortedArray[i]);
    }
    printf("\n");

    return 0;
}
void selectionSort(int array[], int size)
{
    int smallest, smallestIndex;
    for (int j = 0; j < size; j++)
    {
        smallest = array[j];
        smallestIndex = j;
        for (int i = j + 1; i < size; i++)
        {
            if (array[i] < array[j] && array[i] < smallest)
            {
                smallest = array[i];
                smallestIndex = i;
            }
        }
        array[smallestIndex] = array[j];
        array[j] = smallest;
    }
}
void bubbleSort(int array[], int size)
{
    int sorted = 1;
    for (int j = 0; j < size; j++)
    {
        sorted = 1;
        for (int i = 0; i < size - j - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                array[i] ^= array[i + 1] ^= array[i] ^= array[i + 1];
                sorted = 0;
            }
        }
        if (sorted)
            break;
    }
}