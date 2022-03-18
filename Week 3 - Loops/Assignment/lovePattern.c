#include <stdio.h>

int main()
{
    int rows;

    do
    {
        printf("Enter number of rows bigger than 1:\n");
        scanf("%d", &rows);
    } while (rows < 2);

    /* Top part loop */
    for (int i = 0; i <= rows; i++)
    {
        /* Left side dots loop */
        for (int j = 0; j < rows - i; j++)
        {
            printf(".");
        }
        /* Left side slashes */
        printf("//");
        /* If i not equal rows means it is not the line which contains love word */
        if (i != rows)
        {
            /*
            ** prints number of dashes equals (rows + i) * 2 - 1 EX: if rows = 3,
            ** the first line would contain (3 + 0) * 2 - 1 = 5 dashes
            ** and so on by increasing i the dashes increase each line
            */
            for (int j = 0; j < (rows + i) * 2 - 1; j++)
            {
                printf("_");
            }
        }
        else
        {
            /*
            ** Loops twice, the first loop prints left side dashes and then love word
            ** the second loop prints right side dashes only
            */
            for (short j = 0; j < 2; j++)
            {
                for (int k = 0; k < rows * 2 - 3; k++)
                {
                    printf("_");
                }
                if (j == 0)
                    printf("LOVE!");
            }
        }
        /* Right side slashes */
        printf("\\\\");
        /* Right side dots loop */
        for (int j = 0; j < rows - i; j++)
        {
            printf(".");
        }
        printf("\n");
    }
    /* Bottom part loop */
    for (int i = rows; i > 0; i--)
    {
        /* Left side dots loop */
        for (int j = 0; j < rows - i; j++)
        {
            printf(".");
        }
        /* Left side dashes */
        printf("\\\\");
        /*
        ** prints number of dashes equals (rows + i) * 2 - 1 EX: if rows = 3,
        ** the first line would contain (3 + 0) * 2 - 1 = 5 dashes
        ** and so on by increasing i the dashes increase each line
        */
        for (int j = 0; j < (rows + i) * 2 - 1; j++)
        {
            printf("_");
        }
        /* Right side dashes */
        printf("//");
        /* Right side dots loop */
        for (int j = 0; j < rows - i; j++)
        {
            printf(".");
        }
        printf("\n");
    }
    return 0;
}