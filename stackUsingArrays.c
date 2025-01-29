#include <stdio.h>
#define MAX_SIZE 100

struct stack
{
    int arr[MAX_SIZE];
    int indexOfStack;
};

void push(struct stack *myStack)
{
    if (myStack->indexOfStack >= MAX_SIZE)
    {
        printf("Stack Overflow!\n");
        return;
    }
    int value;
    printf("Enter the value that you want to push in the stack:\n");
    scanf("%d", &value);
    myStack->arr[(myStack->indexOfStack)] = value;
    myStack->indexOfStack++;
}

void pop(struct stack *myStack)
{
    if (myStack->indexOfStack <= 0)
    {
        printf("Stack Underflow!\n");
        return;
    }
    int popValue = myStack->arr[(myStack->indexOfStack) - 1];
    myStack->indexOfStack--;
    printf("The value that was removed is %d\n", popValue);
}

void peek(struct stack myStack)
{
    if (myStack.indexOfStack == 0)
    {
        printf("The top of the stack is empty.\n");
        return;
    }
    printf("The top of the stack is %d\n", myStack.arr[myStack.indexOfStack - 1]);
}

void isEmpty(struct stack myStack)
{
    if (myStack.indexOfStack == 0)
    {
        printf("The stack is empty.\n");
        return;
    }
    printf("The stack is not empty.\n");
}

int main()
{
    struct stack myStack;
    myStack.indexOfStack = 0;
    int choice;
    while (1)
    {
        printf("\nStack Operations are:\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Size\n6. Exit\nChoose the operation you want to perform:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(&myStack);
            break;

        case 2:
            pop(&myStack);
            break;

        case 3:
            peek(myStack);
            break;

        case 4:
            isEmpty(myStack);
            break;

        case 5:
            printf("The size of stack is %d.\n", myStack.indexOfStack);
            break;

        case 6:
            printf("The program is exiting...");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
            break;
        }
    }
}

