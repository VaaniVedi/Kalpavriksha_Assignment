#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void isEmpty(struct node **myStack)
{
    if (*myStack == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack is not empty\n");
}

void push(struct node **myStack)
{
    int value;
    printf("Enter the value that you want to push:\n");
    scanf("%d", &value);
    struct node *newNode = createNode(value);
    if (*myStack == NULL)
    {
        *myStack = newNode;
        return;
    }
    newNode->next = *myStack;
    *myStack = newNode;
}

void pop(struct node **myStack)
{
    if (*myStack == NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Removed value: %d\n", (*myStack)->data);
    struct node *temp = *myStack;
    if (*myStack == NULL)
    {
        return;
    }
    *myStack = (*myStack)->next;
    free(temp);
}

void peek(struct node **myStack)
{
    if (*myStack != NULL)
    {
        printf("The value at the top is %d\n", (*myStack)->data);
        return;
    }
    else
    {
        printf("The stack is empty so top is -1.\n");
    }
}

void size(struct node **myStack)
{
    if (*myStack == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }
    struct node *temp = *myStack;
    int sizeOfStack = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        sizeOfStack++;
    }
    printf("The size of stack is %d\n", sizeOfStack);
}

void freeMem(struct node **myStack)
{
    struct node *temp;
    while (*myStack != NULL)
    {
        temp = *myStack;
        *myStack = (*myStack)->next;
        free(temp);
    }
    printf("Stack memory freed successfully.\n");
}

int main()
{
    struct node *myStack = NULL;
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
            peek(&myStack);
            break;

        case 4:
            isEmpty(&myStack);
            break;

        case 5:
            size(&myStack);
            break;

        case 6:
            printf("The program is exiting...\n");
            freeMem(&myStack);
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
            break;
        }
    }
}

