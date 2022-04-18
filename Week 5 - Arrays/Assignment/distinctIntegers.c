#include <stdio.h>

int main()
{
    int range, arraySum = 0;
    printf("Given range (1 to N)\nEnter the range of numbers N:\n");
    scanf("%d", &range);

    int distinctInts[range - 1];
    for (int i = 0; i < range - 1; i++)
    {
        distinctInts[i] = '\0';
    }

    for (int i = 0; i < range - 1; i++)
    {
        printf("[%d]:", i);
        scanf("%d", &distinctInts[i]);
        if (distinctInts[i] < 1 || distinctInts[i] > range)
        {
            printf("The entered number is out of range enter another number\n");
            i--;
        }

        for (int j = 0; j < range - 1; j++)
        {
            if (distinctInts[i] == distinctInts[j] && i != j)
            {
                printf("You have entered this number before enter another number\n");
                i--;
                break;
            }
        }
    }

    printf("The entered array is:\t");
    for (int i = 0; i < range - 1; i++)
    {
        printf("%d ", distinctInts[i]);
    }

    for (int j = 0; j < range - 1; j++)
    {
        arraySum += distinctInts[j];
    }
    printf("\nThe missing number is: %d\n", (range * (range + 1) / 2) - arraySum);
    return 0;
}