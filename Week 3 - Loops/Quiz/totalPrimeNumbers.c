#include <stdio.h>

int main()
{
    /* isPrime is a boolean */
    int index, counter = 0, isPrime = 1;
    printf("Enter a number:\n");
    scanf("%d", &index);

    for (int i = 2; i <= index; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isPrime = 0;
            }
        }
        if (isPrime)
        {
            printf("%d ", i);
            counter++;
        }
        isPrime = 1;
    }
    printf("\nnumber of prime numbers = %d\n", counter);
    return 0;
}