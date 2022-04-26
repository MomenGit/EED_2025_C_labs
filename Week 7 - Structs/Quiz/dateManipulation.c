#include <stdio.h>

typedef struct
{
    short order;
    short days;
    char *nameAbb;
} Month;

typedef struct
{
    int year;
    short day;
    Month month;

} Date;

Date setDate(Month months[]);
void AddDays(Date *date, short days, Month months[]);
void printDate(Date date);

int main()
{
    Month months[12] = {{1, 31, "Jan"}, {2, 28, "Feb"}, {3, 31, "Mar"}, {4, 30, "April"}, {5, 31, "May"}, {6, 30, "Jun"}, {7, 31, "July"}, {8, 31, "Aug"}, {9, 30, "Sep"}, {10, 31, "Oct"}, {11, 30, "Nov"}, {12, 31, "Dec"}};
    Date date = setDate(months);
    AddDays(&date, 45, months);
    printDate(date);
    return 0;
}

Date setDate(Month months[])
{
    Date date;
    do
    {
        printf("Enter a date:\n");
        scanf("%d %d %d", &date.day, &date.month.order, &date.year);
    } while (!((date.month.order >= 1 && date.month.order <= 12) && date.year >= 0 && (date.day >= 0 && date.day <= months[date.month.order - 1].days)));
    return date;
}
void AddDays(Date *date, short days, Month months[])
{
    int i = 0;
    int isFinished = (date->day + days);
    while ((isFinished -= months[(date->month.order - 1 + i) % 12].days) > 0)
    {
        i++;
    }

    date->year += (date->month.order - 1 + i) / 12;
    date->day = isFinished + months[(date->month.order - 1 + i) % 12].days;
    date->month = months[(date->month.order - 1 + i) % 12];
}
void printDate(Date date)
{
    printf("%d.%s.%d\n", date.day, date.month.nameAbb, date.year);
}