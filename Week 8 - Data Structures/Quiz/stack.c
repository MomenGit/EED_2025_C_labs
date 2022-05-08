#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node
{
    int data;
    node *ptr;
};

typedef struct
{
    node *lastElement;
    int size;
} Stack;

Stack init_stack(Stack *, int);
void push(Stack *, int);
void pop(Stack *);
node *peek(Stack *);
void display(Stack *);
int is_empty(Stack *);
int get_size(Stack *);

int main()
{
    Stack stack = init_stack(&stack, 0);

    for (int i = 1; i < 10; i++)
    {
        push(&stack, i);
    };
    display(&stack);

    for (int i = 0; i < 10; i++)
    {
        pop(&stack);
    }
    display(&stack);

    if (is_empty(&stack))
        printf("stack is empty\n");
    return 0;
}

/* Initialize a stack */
Stack init_stack(Stack *stack, int value)
{
    stack->lastElement = (node *)malloc(sizeof(node *));
    stack->lastElement->data = value;
    stack->lastElement->ptr = NULL;
    stack->size = 1;
    return *stack;
}

/* Adds an element to the top of the stack */
void push(Stack *stack, int value)
{
    node *nodePtr = malloc(sizeof(node *));
    nodePtr->data = value;
    nodePtr->ptr = stack->lastElement;
    stack->lastElement = nodePtr;
    stack->size += 1;
}

/* Removes the last element (top) of the stack */
void pop(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Underflow:\nThe stack is empty can't pop elements anymore.\n");
        return;
    }
    node *nodePtr = stack->lastElement;
    stack->lastElement = stack->lastElement->ptr;
    free(nodePtr);
    stack->size -= 1;
}

/* Gets the last element (top) of the stack */
node *peek(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Underflow:\nCan't get last element of the stack, it is empty.\n");
        return NULL;
    }

    return stack->lastElement;
}

/* Display (print) all elements of the stack */
void display(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Underflow:\nCan't display stack, it is empty.\n");
        return;
    }
    node *nodePtr = stack->lastElement;
    while (nodePtr != NULL)
    {
        printf("%d\n", nodePtr->data);
        nodePtr = nodePtr->ptr;
    }
}

/* Check whether the stack is empty */
int is_empty(Stack *stack)
{
    if (stack->lastElement == NULL)
        return 1;
    return 0;
}

int get_size(Stack *stack)
{
    printf("Current size of stack: %d\n", stack->size);
    return stack->size;
}