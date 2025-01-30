#include <stdio.h>
#define MAX_SIZE 100

struct queue
{
    int arr[MAX_SIZE];
    int currentSize;
    int start;
    int end;
};

void enqueue(struct queue *Queue)
{
    if (Queue->currentSize == MAX_SIZE)
    {
        printf("Queue is full!\n");
        return;
    }
    int value;
    printf("Enter the value to enqueue: ");
    scanf("%d", &value);
    Queue->arr[Queue->end] = value;
    Queue->end = (Queue->end + 1) % MAX_SIZE;
    Queue->currentSize++;
}

void dequeue(struct queue *Queue)
{
    if(Queue->currentSize == 0){
        printf("Queue is empty!\n");
        return;
    }
    printf("The value removed is %d.\n", Queue->arr[(Queue->start)]);
    Queue->start = (Queue->start+1) %MAX_SIZE;
    Queue->currentSize--;
}

void peek(struct queue Queue)
{
    if (Queue.currentSize == 0)
    {
        printf("The top of the queue is empty.\n");
        return;
    }
    printf("The top of the queue is %d\n", Queue.arr[(Queue.start)]);
}

void isEmpty(struct queue Queue)
{
    if(Queue.currentSize == 0){
        printf("The queue is empty.\n");
        return;
    }
    printf("The queue is not empty.\n");
}

int main()
{
    struct queue Queue;
    Queue.currentSize = 0;
    Queue.start = 0;
    Queue.end = 0;

    int choice;
    while (1)
    {
        printf("\nQueue Operations are:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. Size\n6. Exit\nChoose the operation you want to perform:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&Queue);
            break;

        case 2:
            dequeue(&Queue);
            break;

        case 3:
            peek(Queue);
            break;

        case 4:
            isEmpty(Queue);
            break;

        case 5:
            printf("The current size of queue is %d.\n",Queue.currentSize);
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
