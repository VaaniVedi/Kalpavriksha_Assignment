#include <stdio.h>
#define MAX_SIZE 100

struct Queue
{
    int arr[MAX_SIZE];
    int front, rear, size;
};

struct Stack
{
    struct Queue Q;
    int size;
};

int isEmptyQueue(struct Queue *q)
{
    if (q->front == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX_SIZE - 1)
    {
        printf("Queue overflow!\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->size++;
    q->arr[q->rear] = value;
}

void dequeue(struct Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue underflow!\n");
        return;
    }
    int data = q->arr[q->front];
    q->size--;
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
}

int front(struct Queue *q)
{
    return q->arr[q->front];
}

void push(struct Stack *stack)
{
    int value;
    printf("Enter the value which you want to push to the stack:\n");
    scanf("%d", &value);
    stack->size++;
    enqueue(&stack->Q, value);
    for (int i = 0; i < (stack->Q.size) - 1; i++)
    {
        enqueue(&stack->Q, front(&stack->Q));
        dequeue(&stack->Q);
    }
}

int peek(struct Stack *stack)
{
    if (isEmptyQueue(&stack->Q))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return front(&stack->Q);
}

void pop(struct Stack *stack)
{

    if (isEmptyQueue(&stack->Q))
    {
        printf("Stack underflow!\n");
        return;
    }
    stack->size--;
    printf("The removed value is %d.\n", peek(stack));
    dequeue(&stack->Q);
}

int size(struct Stack stack)
{
    return stack.size;
}

void isEmpty(struct Stack stack)
{
    if (size(stack) == 0)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack is not empty.\n");
}

int main()
{
    struct Stack stack;
    stack.Q.front = -1;
    stack.Q.rear = -1;
    stack.Q.size = 0;
    stack.size = 0;

    int choice;
    while (1)
    {
        printf("\nStack Operations are:\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Size\n6. Exit\nChoose the operation you want to perform:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(&stack);
            break;

        case 2:
            pop(&stack);
            break;

        case 3:
            printf("The value of top of the stack is %d.\n", peek(&stack));
            break;

        case 4:
            isEmpty(stack);
            break;

        case 5:
            printf("The size of the stack is %d.\n", size(stack));
            break;

        case 6:
            printf("The program is exiting...");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
            break;
        }
    }
    return 0;
}

