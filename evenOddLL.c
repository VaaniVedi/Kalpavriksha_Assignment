#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertAtBegin(struct node **start, int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = *start;
    *start = temp;
}

void insert(struct node **start, int item)
{
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = NULL;
    if (start == NULL)
    {
        *start = newNode;
    }
    else
    {
        temp = *start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void viewList(struct node *start)
{
    struct node *temp;
    temp = start;
    printf("\nThe current state of Linked List is:\n");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
}

void rearrange(struct node **start)
{
    int odd[50];
    int even[50];
    struct node *temp = *start;
    int eveIndex = 0, oddIndex = 0;
    while (temp)
    {
        int nodeData = temp->data;
        if (nodeData % 2 == 0)
        {
            even[eveIndex++] = nodeData;
        }
        else
        {
            odd[oddIndex++] = nodeData;
        }
        temp = temp->next;
    }
    temp = *start;

    while (temp)
    {
        for (int index = 0; index < eveIndex; index++)
        {
            temp->data = even[index];
            temp = temp->next;
        }
        for (int index = 0; index < oddIndex; index++)
        {
            temp->data = odd[index];
            temp = temp->next;
        }
    }
}

int main()
{
    struct node *start = NULL;
    int nodes;
    printf("Enter the total number of nodes:\n");
    scanf("%d", &nodes);
    printf("Enter the elements:\n");
    int item;
    scanf("%d", &item);
    insertAtBegin(&start, item);
    int count = 1;
    while (count < nodes)
    {
        int value;
        scanf("%d", &value);
        insert(&start, value);
        count++;
    }
    rearrange(&start);
    viewList(start);
}

