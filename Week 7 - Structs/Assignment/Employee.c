#include <stdio.h>

#define MAX 100

typedef struct employee
{
    char name[MAX];
    float salary;
    int hours;
} t_Employee;

void get_employees(t_Employee employees[], int n);
void get_salary(t_Employee employees[], int n, int min_hrs, int mid_hrs, int max_hrs);
void print_employees(t_Employee employees[], int n);

int main(void)
{
    int n = 10;
    int min_hrs = 8;
    int mid_hrs = 10;
    int max_hrs = 12;
    t_Employee employees[n];
    get_employees(employees, n);
    get_salary(employees, n, min_hrs, mid_hrs, max_hrs);
    print_employees(employees, n);

    return 0;
}

void get_employees(t_Employee employees[], int n)
{
    int i = 0;
    printf("\nEnter employees data: \n");
    for(i = 0; i < n; i++)
    {
        printf("Name: ");
        scanf("%[^\n]s%*c", &employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        printf("Hours of work per day: ");
        scanf("%d", &employees[i].hours);
        printf("--------------------------------------------------\n");
        scanf("%[^\n]s%*c");
        scanf("%*c");
    }
}

void get_salary(t_Employee employees[], int n, int min_hrs, int mid_hrs, int max_hrs)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        employees[i].salary = (employees[i].hours >= 12) ? (employees[i].salary + 150) : ((employees[i].hours >= 10) ? (employees[i].salary + 100) : ((employees[i].hours >= 8) ? (employees[i].salary + 50) : employees[i].salary));
    }
}

void print_employees(t_Employee employees[], int n)
{
    int i = 0;
    printf("\nEmployees Data\n");
    printf("--------------------------------------------\n");
    for(i = 0; i < n; i++)
    {
        printf("Name: %s\n", employees[i].name);
        printf("Salary: %.2f$\n", employees[i].salary);
        printf("Hours per day: %d\n", employees[i].hours);
        printf("--------------------------------------------\n");
    }
}