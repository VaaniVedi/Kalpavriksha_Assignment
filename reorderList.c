#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void insert(int item)
{
    struct node *n, *temp;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = item;
    n->next = NULL;
    if (start == NULL)
    {
        start = n;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void viewList()
{
    struct node *temp = start;
    printf("\nThe current state of Linked List is:\n");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
}

void rearrange()
{
    if (!start || !start->next || !start->next->next){
        return;
    }

    struct node *slow = start, *fast = start;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct node *prev = NULL, *cur = slow->next, *Next;
    while (cur)
    {
        Next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = Next;
    }
    slow->next = NULL;

    struct node *A = start, *B = prev;
    while (A!=NULL && B!=NULL)
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
    int n;
    printf("Enter the total number of nodes:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    int count = 0;
    while (count < n)
    {
        int value;
        scanf("%d", &value);
        insert(value);
        count++;
    }
    rearrange();
    viewList(start);
}
