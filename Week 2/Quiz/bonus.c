#include <stdio.h>

int main(void)
{
    int y1, m1, d1, h1, isPM1, y2, m2, d2, h2, isPM2, firstDate, secondDate;

    printf("Enter two dates to compare which is earlier:\t\"Hint: enter 0 for AM and 1 for PM\"\n");

    printf("Input first date Y M D H AM\\PM:\n");
    scanf("%d %d %d %d %d", &y1, &m1, &d1, &h1, &isPM1);

    printf("Input second date Y M D H AM\\PM:\n");
    scanf("%d %d %d %d %d", &y2, &m2, &d2, &h2, &isPM2);

    /* Check if the entered years' values are bigger than 1*/
    if (y1 < 1 || y2 < 1)
    {
        printf("Error: Input a valid year number\n");
        return 1;
    }
    /* Check if the entered months' values are between 1 and 12 */
    if (!(m1 >= 1 && m1 <= 12) && !(m2 >= 1 && m2 <= 12))
    {
        printf("Error: Input a valid month number\n");
        return 1;
    }
    /*
    ** Check if the entered days' values are between 1 and 31
    ** We could also check if the month was 2 AKA February
    ** then check that the days are between 1 and 28 days
    ** but let's not go this far
    ** You could try it though
    */
    if (!(d1 >= 1 && d1 <= 31) && !(d2 >= 1 && d2 <= 31))
    {
        printf("Error: Input a valid day number\n");
        return 1;
    }
    /* Check if the entered times of hours' values are between 1 and 12 */
    if (!(h1 >= 1 && h1 <= 12) && !(h2 >= 1 && h2 <= 12))
    {
        printf("Error: Input a valid hour number\n");
        return 1;
    }
    /*
    ** Check if the input of isPM for AM/PM is more than or equal to 1 (true) then it is PM
    ** then add 12 to the time to make it 24H format
    */
    if (isPM1 >= 1)
        h1 += 12;
    if (isPM2 >= 1)
        h2 += 12;
    /*
    ** Add all the values of the date to each other
    ** We gave a weight to each part of the date according to its priority and impact
    ** the year has the most significant impact so it has the highest weight
    ** for example: first date = (Year)2022*10000 + (Month)3*1000 + (Day)5*100 + (Hour AM) 5
    */
    firstDate = y1 * 10000 + m1 * 1000 + d1 * 100 + h1;
    secondDate = y2 * 10000 + m2 * 1000 + d2 * 100 + h2;
    /* If the summation of the first date is smaller than that of the second date then it is earlier and so on*/
    if (firstDate < secondDate)
    {
        printf("**first date is earlier**\n");
    }
    else if (firstDate == secondDate)
    {
        printf("**the two dates are the same**\n");
    }
    else
    {
        printf("**second date is earlier**\n");
    }
    return 0;
}