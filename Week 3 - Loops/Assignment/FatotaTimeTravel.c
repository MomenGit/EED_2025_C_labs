#include <stdio.h>

void main(void)
{
    int age = 21, plannedYear, survivedYears = 0;
    float money;

    printf("Please enter the amount of money Fatota has:\n");
    /* Make sure the user enters a year more than or equal 1700 */
    scanf("%f", &money);
    do
    {
        printf("Please enter the year, which he planned to stay until:\n");
        scanf("%d", &plannedYear);
    } while (plannedYear < 1700);
    /* convert money into dollars */
    money = money / 2;
    /* Get the number of years spent without year 0 AKA 1700 EX: 1705 - 1700 = 5 */
    plannedYear -= 1700;
    /*
    ** Loop over years, each year his age increases by one
    ** if it was an even year decrease money by 1000
    ** else if it was an odd year decrease money by (1000 + 50 * age)
    */
    for (int i = 0; i <= plannedYear; i++)
    {
        age++;
        if (i % 2 == 0)
        {
            money -= 1000;
        }
        else
        {
            money -= (1000 + 50 * age);
        }
        if (money >= 0)
            survivedYears++;
        else
            break;
    }
    if (money >= 0)
    {
        printf("Yes, it will be enough and will have %d$ remaining.\n", money);
    }
    else
    {
        printf("No, it won't be enough. He could just stay until %d\n", 1700 + survivedYears - 1);
    }
}