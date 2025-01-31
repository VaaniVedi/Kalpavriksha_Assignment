#include <stdio.h>
#define MAX_SIZE 100

struct Stack
{
    int arr[MAX_SIZE];
    int indexOfStack;
};

struct Queue
{
    struct Stack myStack;
    int front;
};

int isEmpty(struct Stack *myStack)
{
    if (myStack->indexOfStack == 0)
    {
        return 1;
    }
    return 0;
}

int top(struct Stack *myStack)
{
    if (isEmpty(myStack))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return myStack->arr[myStack->indexOfStack - 1];
}

void push(struct Stack *myStack, int value)
{
    if (myStack->indexOfStack >= MAX_SIZE)
    {
        printf("Queue Overflow!\n");
        return;
    }
    myStack->arr[(myStack->indexOfStack)] = value;
    myStack->indexOfStack++;
}

int pop(struct Stack *myStack)
{
    if (myStack->indexOfStack <= 0)
    {
        printf("Queue Underflow!\n");
        return 0;
    }
    int popValue = top(myStack);
    myStack->indexOfStack--;

    if (isEmpty(myStack))
    {
        return popValue;
    }

    int item = pop(myStack);
    push(myStack, popValue);
    return item;
}

void enqueue(struct Queue *queue)
{
    int value;
    printf("Enter the value which you want to enqueue to the queue:\n");
    scanf("%d", &value);
    if (queue->myStack.indexOfStack == 0)
    {
        queue->front = value;
    }
    push(&queue->myStack, value);
}

void dequeue(struct Queue *queue)
{
    int removedValue = pop(&queue->myStack);
    printf("The popped value is %d\n", removedValue);
    if (!isEmpty(&queue->myStack))
    {
        queue->front = queue->myStack.arr[0]; 
    }
}

int peek(struct Queue *queue)
{
    if (isEmpty(&queue->myStack))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    printf("The front of the queue is %d\n", queue->front);
    return queue->front;
}

int size(struct Queue queue)
{
    return queue.myStack.indexOfStack;
}

void isEmptyQueue(struct Queue queue)
{
    if (size(queue) == 0)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue is not empty.\n");
}

int main()
{
    struct Queue queue;
    queue.myStack.indexOfStack = 0;
    queue.front = 0;
    int choice;
    while (1)
    {
        printf("\nQueue Operations are:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. Size\n6. Exit\nChoose the operation you want to perform:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&queue);
            break;

        case 2:
            dequeue(&queue);
            break;

        case 3:
            peek(&queue);
            break;

        case 4:
            isEmptyQueue(queue);
            break;

        case 5:
            printf("The size of the queue is %d.\n", size(queue));
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

