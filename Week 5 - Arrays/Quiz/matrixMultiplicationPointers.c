#include <stdio.h>

/* Matrix Muliplication function prototype */
void matrixMultiplication(int *, int *, int, int, int);

int main()
{
    int firstRows, firstColumnsSecondRows, secondColumns;
    /* First Matrix Initialization */
    printf("Enter rows and columns of first matrix:\n");
    scanf("%d %d", &firstRows, &firstColumnsSecondRows);
    int matrixOne[firstRows][firstColumnsSecondRows];
    printf("Fill in the elements of the first matrix:\n");
    for (int i = 0; i < firstRows; i++)
    {
        for (int j = 0; j < firstColumnsSecondRows; j++)
        {
            printf("[%d][%d]:", i, j);
            scanf("%d", &matrixOne[i][j]);
        }
    }

    /* Second Matrix Initialization */
    printf("Enter number of columns of second matrix:\n");
    scanf("%d", &secondColumns);
    int matrixTwo[firstColumnsSecondRows][secondColumns];
    printf("Fill in the elements of the second matrix:\n");
    for (int i = 0; i < firstColumnsSecondRows; i++)
    {
        for (int j = 0; j < secondColumns; j++)
        {
            printf("[%d][%d]:", i, j);
            scanf("%d", &matrixTwo[i][j]);
        }
    }

    /* Matrix Muliplication function call */
    matrixMultiplication(*matrixOne, *matrixTwo, firstRows, firstColumnsSecondRows, secondColumns);
    return 0;
}
void matrixMultiplication(int *firstMatrix, int *secondMatrix, int firstRowsNum, int commonColumnsRowsNum, int secondColumnsNum)
{
    int element = 0;
    // loop firstrows
    for (int i = 0; i < firstRowsNum; i++)
    {
        // j is the
        for (int j = 0; j < secondColumnsNum; j++)
        {
            // k is the common column of first matrix and row of second matrix
            for (int k = 0; k < commonColumnsRowsNum; k++)
            {
                element += *(firstMatrix + k + i * firstRowsNum) * *(secondMatrix + j + k * secondColumnsNum);
            }
            printf("%d ", element);
            element = 0;
        }
        printf("\n");
    }
}