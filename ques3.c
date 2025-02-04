//Stack using queues

#include <stdio.h>
#define MAX_SIZE 100

struct Queue
{
    int arr[MAX_SIZE];
    int front, rear;
};

struct Stack
{
    struct Queue Q1, Q2;
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
    q->arr[q->rear] = value;
}

void dequeue(struct Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue underflow!\n");
    }
    int data = q->arr[q->front];
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
    enqueue(&stack->Q2, value);
    while (!isEmptyQueue(&stack->Q1))
    {
        enqueue(&stack->Q2, front(&stack->Q1));
        dequeue(&stack->Q1);
    }

    struct Queue temp = stack->Q1;
    stack->Q1 = stack->Q2;
    stack->Q2 = temp;
}

void pop(struct Stack *stack)
{

    if (isEmptyQueue(&stack->Q1))
    {
        printf("Stack underflow!\n");
        return;
    }
    stack->size--;
    dequeue(&stack->Q1);
}

int peek(struct Stack *stack)
{
    if (isEmptyQueue(&stack->Q1))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return front(&stack->Q1);
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
    stack.Q1.front = -1;
    stack.Q1.rear = -1;
    stack.Q2.front = -1;
    stack.Q2.rear = -1;
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

