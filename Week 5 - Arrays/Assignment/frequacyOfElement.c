#include <stdio.h>

int frequencyIn2DArray(int *, int, int, int);
int main()
{
    int rows, columns, element;
    printf("Enter rows and columns respectively\n");
    scanf("%d %d", &rows, &columns);
    /* 2D array intialization */
    int multiDimArray[rows][columns];
    /* Fill the 2D array */
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &multiDimArray[i][j]);
        }
    }
    /* Choose the element to count which its frequency to be counted */
    printf("Enter the element you want to check its frequency:\n");
    scanf("%d", &element);

    printf("The element appeared in the array %d times\n", frequencyIn2DArray(*multiDimArray, rows, columns, element));
    return 0;
}
int frequencyIn2DArray(int *array, int rows, int columns, int element)
{
    int counter = 0;
    /* loop over the rows of the 2D array */
    for (int i = 0; i < rows; i++)
    {
        /* loop over the columns of the 2D array */
        for (int j = 0; j < columns; j++)
        {
            /*
            ** array is the address of the first element in the 2D array
            ** by adding (i * rows) we access the first element of each rows
            ** and by adding j which is counter of the columns we access the elements in different columns
            */
            if (element == *(array + i * rows + j))
                counter++;
        }
    }
}