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
    }
    if (temp == NULL)
    {
        printf("\nInvalid Operation\n");
        free(p);
        return;
    }
    if (temp->next == NULL && position == 2)
    {

        insertAtLast(value);
        free(p);
        return;
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
    int index = 0;
    printf("1 x: Add x to the end. (x: is any number and pos: position)\n");
    printf("2 x: Add x at the beginning.\n3 pos x: Add x at position pos (1-indexed).\n");
    printf("4: Display all elements.\n5 pos x: Update the element at position pos to x.\n6: Delete the first element.\n");
    printf("7: Delete the last element.\n8 pos: Delete the element at position pos (1-indexed).\n");
    while (index < totalOperations)
    {
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
        {
            int value;
            scanf("%d", &value);
            insertAtLast(value);
            break;
        }
        case 2:
        {
            int value;
            scanf("%d", &value);
            insertAtBegin(value);
            break;
        }
        case 3:
        {
            int value, position;
            scanf("%d %d", &position, &value);
            insertAtPosition(position, value);
            break;
        }
        case 4:
        {
            viewList();
            break;
        }
        case 5:
        {
            int value, position;
            scanf("%d %d", &position, &value);
            updateList(position, value);
            break;
        }
        case 6:
        {
            deleteFirst();
            break;
        }
        case 7:
        {
            deleteEnd();
            break;
        }
        case 8:
        {
            int position;
            scanf("%d", &position);
            deleteAtPosition(position);
            break;
        }
        default:
        {
            printf("Invalid Operation");
            break;
        }
        }
        index++;
    }

    return 0;
}

