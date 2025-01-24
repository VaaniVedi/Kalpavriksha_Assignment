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

void reorder(struct node **start)
{
    if (!start || !(*start)->next || !(*start)->next->next)
    {
        return;
    }
    struct node *slow = *start, *fast = *start;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct node *prev = NULL, *currentNode = slow->next, *Next;
    while (currentNode)
    {
        Next = currentNode->next;
        currentNode->next = prev;
        prev = currentNode;
        currentNode = Next;
    }
    slow->next = NULL;

    struct node *A = *start, *B = prev;
    while (A != NULL && B != NULL)
    {
        struct node *next1 = A->next;
        struct node *next2 = B->next;

        A->next = B;
        B->next = next1;

        A = next1;
        B = next2;
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
    reorder(&start);
    viewList(start);
}

