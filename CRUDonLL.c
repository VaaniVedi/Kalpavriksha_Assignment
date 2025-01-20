#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

void insertAtBegin(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = start;
    start = temp;
}

void insertAtLast(int item)
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

void insertAtPosition(int position, int value)
{
    if (position == 1)
    {
        insertAtBegin(value);
        return;
    }
    struct node *temp, *p;
    p = (struct node *)malloc(sizeof(struct node));
    temp = start;
    while (temp->next != NULL && position - 1 > 1)
    {
        temp = temp->next;
        position--;
        if (temp->next == NULL)
        {
            if (position == 2)
            {
                insertAtLast(value);
                free(p);
                return;
            }
            printf("\nInvalid Operation\n");
            return;
        }
    }

    p->next = temp->next;
    temp->next = p;
    p->data = value;
}

void deleteFirst()
{
    struct node *temp;
    if (start)
    {
        temp = start;
        start = temp->next;
        free(temp);
    }
    return;
}

void deleteEnd()
{
    struct node *temp, *p;
    temp = start;
    while (temp->next != NULL)
    {
        if (temp->next->next == NULL)
        {
            p = temp->next;
            temp->next = NULL;
            free(p);
        }
        else
        {
            temp = temp->next;
        }
    }
}

int sizeOfList()
{
    int count = 1;
    struct node *temp = start;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteAtPosition(int position)
{
    int count = sizeOfList();
    if (position > count)
    {
        printf("\nInvalid Operation\n");
        return;
    }
    if (position == 1)
    {
        deleteFirst();
        return;
    }

    struct node *temp, *p;
    p = (struct node *)malloc(sizeof(struct node));
    temp = start;

    while (temp->next != NULL && position > 1)
    {
        p = temp;
        temp = temp->next;
        position--;
    }

    p->next = temp->next;
    free(temp);
    return;
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

void updateList(int position, int value)
{
    struct node *temp, *p;
    temp = start;
    if (position == 1)
    {
        temp->data = value;
        return;
    }
    while (temp->next != NULL && position > 1)
    {
        temp = temp->next;
        position--;
        if (position == 1)
        {
            temp->data = value;
            return;
        }
    }
    if (position > 1)
    {
        printf("\nInvalid Operation\n");
        return;
    }

    return;
}

int main()
{
    int totalOperations;
    scanf("%d", &totalOperations);
    int operation;
    int position, value;
    while (totalOperations > 0)
    {
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            scanf("%d", &value);
            insertAtLast(value);
            break;
        case 2:
            scanf("%d", &value);
            insertAtBegin(value);
            break;
        case 3:
            scanf("%d %d", &value, &position);
            insertAtPosition(position, value);
            break;
        case 4:
            viewList();
            break;
        case 5:
            scanf("%d %d", &value, &position);
            updateList(position, value);
            break;
        case 6:
            deleteFirst();
            break;
        case 7:
            deleteEnd();
            break;
        case 8:
            scanf("%d", &position);
            deleteAtPosition(position);
            break;
        default:
            printf("Invalid Operation");
            break;
        }
        totalOperations--;
    }

    return 0;
}

