#include <stdio.h>

#define MAX 100

typedef struct customer
{
    char name[MAX];
    int account;
    float balance;
} t_Customer;

void get_customers(t_Customer customers[], int n);
void print_customers_to_limit(t_Customer customers[], int n, int limit);
void add_balance(t_Customer customers[], int n, int limit);
void print_customers_above_limit(t_Customer customers[], int n, int limit);

int main(void)
{
    int n = 0;
    do
    {
        printf("Enter number of customers (more than 10): ");
        scanf("%d", &n);
    } while (n <= 10);
    t_Customer customers[n];
    get_customers(customers, n);
    print_customers_to_limit(customers, n, 200);
    add_balance(customers, n, 1000);
    print_customers_above_limit(customers, n, 1000);

    return 0;
}

void get_customers(t_Customer customers[], int n)
{
    int i = 0;
    printf("\nEnter customers data: \n");
    for(i = 0; i < n; i++)
    {
        scanf("%*c");
        printf("Name: ");
        scanf("%[^\n]s%*c", &customers[i].name);
        printf("Account number: ");
        scanf("%d", &customers[i].account);
        printf("Balance: ");
        scanf("%f", &customers[i].balance);
        printf("--------------------------------------------------\n");
    }
}

void print_customers_to_limit(t_Customer customers[], int n, int limit)
{
    int i = 0;
    printf("\nCustomers having less than %d\n", limit);
    for(i = 0; i < n; i++)
    {
        if(customers[i].balance < limit)
        {
            printf("Name: %s\n", customers[i].name);
            printf("Account number: %d\n", customers[i].account);
            printf("Balance: %.2f$\n", customers[i].balance);
            printf("--------------------------------------------------\n");
        }
    }
}

void add_balance(t_Customer customers[], int n, int limit)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        if(customers[i].balance > limit)
        {
            customers[i].balance += 100;
        }
    }
}

void print_customers_above_limit(t_Customer customers[], int n, int limit)
{
    int i = 0;
    printf("\nCustomers having more than %d\n", limit);
    for(i = 0; i < n; i++)
    {
        if(customers[i].balance > limit)
        {
            printf("Name: %s\n", customers[i].name);
            printf("Account number: %d\n", customers[i].account);
            printf("Balance: %.2f$\n", customers[i].balance);
            printf("--------------------------------------------------\n");
        }
    }
}