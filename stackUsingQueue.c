#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct Queue
{
    int arr[MAX_SIZE];
    int front, rear, size;
};

struct Stack
{
    struct Queue Q;
};

int isEmptyQueue(struct Queue *q)
{
    return q->size == 0;
}

int isFullQueue(struct Queue *q)
{
    return q->size == MAX_SIZE;
}

void enqueue(struct Queue *q, int value)
{
    if (isFullQueue(q))
    {
        printf("Queue overflow!\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->arr[q->rear] = value;
    q->size++;
}

void dequeue(struct Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue underflow!\n");
        return;
    }
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    if (q->size == 0)
    {
        q->front = q->rear = -1;
    }
}

int front(struct Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->front];
}

void push(struct Stack *stack)
{
    if (isFullQueue(&stack->Q))
    {
        printf("Stack overflow!");
        return;
    }

    int value;
    printf("Enter the value which you want to push to the stack:\n");
    scanf("%d", &value);

    enqueue(&stack->Q, value);
    int originalSize = stack->Q.size - 1;

    for (int i = 0; i < originalSize; i++)
    {
        int temp = front(&stack->Q);
        dequeue(&stack->Q);
        enqueue(&stack->Q, temp);
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

    printf("The removed value is %d.\n", peek(stack));
    dequeue(&stack->Q);
}

int size(struct Stack stack)
{
    return stack.Q.size;
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

