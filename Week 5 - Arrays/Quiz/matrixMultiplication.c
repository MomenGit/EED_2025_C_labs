#include <stdio.h>

int firstRows, firstColumnsSecondRows, secondColumns;

/* Matrix Muliplication function prototype */
void matrixMultiplication(int firstMatrix[][firstColumnsSecondRows], int secondMatrix[][secondColumns]);

int main()
{
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
    matrixMultiplication(matrixOne, matrixTwo);
    return 0;
}
void matrixMultiplication(int firstMatrix[][firstColumnsSecondRows], int secondMatrix[][secondColumns])
{
    // loop firstrows
    for (int i = 0; i < firstRows; i++)
    {
        int element = 0;
        // loop firstColumns and secondRows
        for (int k = 0; k < secondColumns; k++)
        {
            // loop firstColumns and secondRows
            for (int j = 0; j < firstColumnsSecondRows; j++)
            {
                element += firstMatrix[i][j] * secondMatrix[j][k];
            }
            printf("%d ", element);
            element = 0;
        }
        printf("\n");
    }
}