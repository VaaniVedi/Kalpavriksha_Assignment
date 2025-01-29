#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10

struct record
{
    int id;
    char condition[MAX_SIZE];
    struct record *next;
};

struct record *create(int id, char arr[])
{
    struct record *newNode = (struct record *)malloc(sizeof(struct record));
    newNode->id = id;
    strcpy(newNode->condition, arr);
    newNode->next = NULL;
    return newNode;
}

int priority(char *arr)
{
    if (strcmp(arr, "Critical") == 0)
    {
        return 1;
    }
    else if (strcmp(arr, "Serious") == 0)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

void insertNode(struct record **head, int id, char arr[])
{
    struct record *newNode = create(id, arr);
    if (*head == NULL || priority(arr) < priority((*head)->condition))
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct record *temp = *head;
    while (temp->next != NULL && priority(temp->next->condition) <= priority(arr))
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void printEle(struct record *head)
{
    printf("The sorted list of patients based on severity priority order.\n");
    while (head != NULL)
    {
        printf("%d %s\n", head->id, head->condition);
        head = head->next;
    }
}

int main()
{
    int totalElements, id;
    char severity[MAX_SIZE];
    struct record *head = NULL;
    printf("Enter number of patients: \n");
    scanf("%d", &totalElements);
    for (int index = 0; index < totalElements; index++)
    {
        scanf("%d %s", &id, severity);
        insertNode(&head, id, severity);
    }
    printEle(head);
    return 0;
}

 
