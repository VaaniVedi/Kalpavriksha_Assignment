#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *end = NULL;

void isEmpty()
{
    if (start == NULL && end == NULL)
    {
        printf("The queue is empty");
    }
    else
    {
        printf("The queue is not empty");
    }
}

void enqueue()
{
    int value;
    printf("Enter the value which you want to enqueue:\n");
    scanf("%d", &value);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (start == NULL)
    {
        start = end = newNode;
    }
    else
    {
        end->next = newNode;
        end = newNode;
    }
}

void dequeue()
{
    if (start == NULL)
    {
        printf("The queue is empty");
        return;
    }
    struct node *temp = start;
    printf("Dequeued element is: %d\n", temp->data);
    start = start->next;
    if (start == NULL)
    {
        end = NULL;
    }
    free(temp);
}

void peek()
{
    if (start == NULL && end == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Front element of queue is %d.\n", start->data);
    }
}

void size()
{
    if (start == NULL && end == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        struct node *temp;
        temp = start;
        int sizeOfQueue = 0;
        while (temp)
        {
            sizeOfQueue++;
            temp = temp->next;
        }
        printf("The size of queue is %d.\n", sizeOfQueue);
    }
}

void freeMem()
{
    struct node *temp;
    while (start != NULL)
    {
        temp = start;
        start = start->next;
        free(temp);
    }
    printf("Queue memory freed successfully.\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nQueue Operations are:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. Size\n6. Exit\nChoose the operation you want to perform:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            isEmpty();
            break;

        case 5:
            size();
            break;

        case 6:
            printf("The program is exiting...\n");
            freeMem();
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
            break;
        }
    }
}

