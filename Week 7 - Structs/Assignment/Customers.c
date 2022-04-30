#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    char *accountNum;
    int balance;
} Customer;

char *readLine(int);
Customer initCustomer();
void printCustomer(Customer *);
void addBalance(Customer *, int);
void massAddBalance(Customer[], int, int);
Customer *queryCustomersBalance(Customer *, Customer[], int, int, int, int *);

int main()
{
    int size, less200Size, more1kSize;
    printf("What is the number of your customers?\n");
    scanf("%d", &size);
    Customer customers[size];
    printf("Please fill their data:\n\n");
    for (int i = 0; i < size; i++)
    {
        customers[i] = initCustomer();
    }

    Customer *poorCustomers = queryCustomersBalance(poorCustomers, customers, size, 200, -1, &less200Size);
    printf("*All customers having less than $200 in their balance*\n");
    for (int i = 0; i < less200Size; i++)
    {
        printCustomer(&poorCustomers[i]);
    }
    free(poorCustomers);

    Customer *richCustomers = queryCustomersBalance(richCustomers, customers, size, 1000, 1, &more1kSize);
    massAddBalance(richCustomers, more1kSize, 100);
    printf("\n*All customers having more than $1000 in their balance after adding $100 to their balances*\n");
    for (int i = 0; i < more1kSize; i++)
    {
        printCustomer(&richCustomers[i]);
    }
    free(richCustomers);
    return 0;
}
/* conditions: 0 (equality), 1 (bigger than) & -1 (smaller than)*/
Customer *queryCustomersBalance(Customer *queried, Customer customers[], int size, int balance, int condition, int *newSize)
{
    queried = (Customer *)malloc(sizeof(Customer *) * size);

    *newSize = 0;
    for (int i = 0; i < size; i++)
    {
        switch (condition)
        {
        case 0:
            if (customers[i].balance != balance && condition == 0)
                break;
        case -1:
            if (customers[i].balance > balance && condition == -1)
                break;
        case 1:
            if (customers[i].balance < balance && condition == 1)
                break;
        default:
            *(queried + *newSize) = customers[i];
            *newSize = *newSize + 1;
            break;
        }
    }
    return queried;
}
void addBalance(Customer *customer, int balance)
{
    customer->balance += balance;
}
void massAddBalance(Customer customers[], int size, int balance)
{
    for (int i = 0; i < size; i++)
    {
        addBalance(&customers[i], balance);
    }
}
Customer initCustomer()
{
    Customer newCustomer;
    printf("Enter new customer data:\n");
    printf("Name:\n");
    newCustomer.name = readLine(30);
    printf("Account number:\n");
    newCustomer.accountNum = readLine(10);
    printf("Balance: ");
    scanf("%d", &newCustomer.balance);
    printf("\n");
    return newCustomer;
}
void printCustomer(Customer *customer)
{
    printf("\n%s\nAccount Number: %s\nBalance: $%d\n", customer->name, customer->accountNum, customer->balance);
}

char *readLine(int maxSize)
{
    char buffer[maxSize];
    scanf(" %[^\n]", buffer);
    char *string = (char *)malloc(strlen(buffer) + 1);
    strcpy(string, buffer);
    return string;
}