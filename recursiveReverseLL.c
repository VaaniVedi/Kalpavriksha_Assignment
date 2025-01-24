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
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertHead(struct node **start, int value)
{
    struct node *newNode = createNode(value);
    newNode->data = value;
    newNode->next = *start;
    *start = newNode;
}

void insertLast(struct node **start, int value)
{
    struct node *newNode = createNode(value);
    newNode->next = NULL;
    struct node *tail;
    tail = *start;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = newNode;
}

struct node * reverseRecursive(struct node *start){
    if(start == NULL || start->next == NULL){
        return start;
    }

    struct node * reversedList = reverseRecursive(start -> next);
    struct node * front = start ->next;
    front -> next = start;
    start -> next = NULL;
    return reversedList;
}

void printLL(struct node * start){
    struct node * temp;
    temp = start;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



int main()
{
    int nodes,value;
    printf("Enter the total nodes:\n");
    scanf("%d", &nodes);
    struct node *start = NULL;
    printf("Enter the values:\n");
    scanf("%d", &value);
    insertHead(&start, value);
    for (int count = 1; count < nodes; count++)
    {
        scanf("%d", &value);
        insertLast(&start, value);
    }
    printLL(start);
    start = reverseRecursive(start);
    printLL(start);
    return 0;
}

