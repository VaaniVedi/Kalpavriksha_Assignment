// Given a number N, generate all binary numbers from 1 to N using a queue.
// Example Input: 5
// Example Output: 001, 010, 011, 100, 101

#include <stdio.h>
#include <string.h>
#define max_size 20

typedef struct
{
    char str[max_size][max_size];
    int front;
    int rear;
    int size;
} queue;

void enqueue(queue *q, char *newStr)
{
    if (q->size == max_size)
    {
        printf("Overflow!\n");
        return;
    }
    if (q->front == -1 && q->rear == -1)
    {
        q->front = 1;
        q->rear = 1;
        strcpy(q->str[q->rear], newStr);
        q->size++;
    }
    else
    {
        q->rear++;
        strcpy(q->str[q->rear], newStr);
        q->size++;
    }
}

void dequeue(queue *q)
{
    if (q->size == 0)
    {
        printf("Underflow!\n");
    }
    else
    {
        q->front++;
        q->size--;
        if (q->size == 0)
        {
            q->front = -1;
            q->rear = -1;
        }
    }
}

char *front(queue *q)
{
    return q->str[q->front];
}

int main()
{
    queue q;
    q.size = 0;
    q.front = -1;
    q.rear = -1;
    char str1[max_size], str2[max_size];
    int n;
    printf("Enter the value upto which you want to see the iterations:\n");
    scanf("%d", &n);
    if(n>10){
        printf("Can't generate for more that 10 as queue size won't support.\nStill if you want to generate increase the max_size from 20 to a valid value\n");
        return 0;
    }
    enqueue(&q, "1");
    while (n--)
    {
        strcpy(str1, front(&q));
        dequeue(&q);
        printf("%s\n", str1);
        strcpy(str2, str1);
        enqueue(&q, strncat(str1, "0", 1));
        enqueue(&q, strncat(str2, "1", 1));
    }
    return 0;
}

