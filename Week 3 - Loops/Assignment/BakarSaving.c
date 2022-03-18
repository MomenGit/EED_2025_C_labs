#include <stdio.h>

int main()
{
    int age, savedMoney = 0, housePrice, suitPrice = 0;

    printf("Enter Bakar's age:\n");
    scanf("%d", &age);
    printf("Enter the price of Rashida's new house:\n");
    scanf("%d", &housePrice);
    /*
    ** Looping on odd birthdays to calculate the saved money from money gifts
    ** subtracing the 5% Hasouna takes each odd year from the total saved money
    ** example: On Bakar's third birthday saved money is equal to (50 + 50 * (3+1)/2) * 0.95
    ** where 50 is the last saved money and 50 * (3+1)/2 is the new add value and by multiplying with 0.95
    ** the 5% Hasouna took is subtracted
    */
    for (int i = 1; i <= age; i += 2)
    {
        savedMoney = (savedMoney + 50 * ((i + 1) / 2)) * 0.95;
    }
    /*
    ** Looping on even birthdays to add the sold suits prices to the saved money
    ** Hasouna didn't take any money from the suits savings
    */
    for (int i = 2; i <= age; i += 2)
    {
        printf("Enter the price of Bakar's %d birthday suit:\n", i);
        scanf("%d", &suitPrice);
        savedMoney += suitPrice;
    }

    printf("The total amount of saved money is %d\n", savedMoney);
    if (savedMoney >= housePrice)
    {
        printf("It will be enough to buy the house\n");
    }
    else
    {
        printf("It won't be enough to buy the house\n");
    }
}