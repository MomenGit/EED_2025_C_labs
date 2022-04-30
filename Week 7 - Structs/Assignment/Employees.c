#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    int salary;
    short hoursOfWorkDay;
} Employee;

Employee initEmployee();
void salaryInc(Employee *, int);
Employee *promoteSalaries(Employee[], int);
void printEmployee(Employee employee);
char *readLine(int);

int main()
{
    int size;
    printf("What is the number of your employees?\n");
    scanf("%d", &size);
    Employee employees[size];
    printf("Please fill their data:\n\n");
    for (int i = 0; i < size; i++)
    {
        employees[i] = initEmployee();
    }
    promoteSalaries(employees, size);
    for (int i = 0; i < size; i++)
    {
        printEmployee(employees[i]);
    }
    return 0;
}

Employee initEmployee()
{
    Employee newEmployee;
    printf("\nEnter employee data:\n");
    printf("Name:\n");
    newEmployee.name = readLine(30);
    printf("Salary: ");
    scanf("%d", &newEmployee.salary);
    printf("Hours of work per day: ");
    do
    {
        scanf("%d", &newEmployee.hoursOfWorkDay);
    } while (newEmployee.hoursOfWorkDay > 14);
    return newEmployee;
}
Employee *promoteSalaries(Employee employees[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (employees[i].hoursOfWorkDay >= 8)
            switch (employees[i].hoursOfWorkDay)
            {
            case 8 ... 9:
                salaryInc(&employees[i], 50);
                break;
            case 10 ... 11:
                salaryInc(&employees[i], 100);
                break;
            default:
                salaryInc(&employees[i], 150);
                break;
            }
    }
    return employees;
}
void salaryInc(Employee *employee, int increase)
{
    employee->salary += increase;
}
void printEmployee(Employee employee)
{
    printf("\n\t%s\nSalary: %d\tHours/Day: %d\n", employee.name, employee.salary, employee.hoursOfWorkDay);
}
char *readLine(int maxSize)
{
    char buffer[maxSize];
    scanf(" %[^\n]", buffer);
    char *string = (char *)malloc(strlen(buffer) + 1);
    strcpy(string, buffer);
    return string;
}