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

int priority(char *severity)
{
    int priority = 3;
    if (strcmp(severity, "Critical") == 0)
        priority = 1;
    if (strcmp(severity, "Serious") == 0)
        priority = 2;
    return priority;
}

struct record *findMid(struct record *head)
{
    struct record *slow = head;
    struct record *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int compareNodes(struct record *left, struct record *right)
{
    int leftPriority = priority(left->condition);
    int rightPriority = priority(right->condition);

    if (leftPriority < rightPriority)
        return 1;
    if (leftPriority == rightPriority && left->id < right->id)
        return 1;

    return 0;
}

struct record *merge(struct record *left, struct record *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    struct record *newHead = NULL;
    if (compareNodes(left, right))
    {
        newHead = left;
        left = left->next;
    }
    else
    {
        newHead = right;
        right = right->next;
    }

    struct record *current = newHead;
    while (left != NULL && right != NULL)
    {
        if (compareNodes(left, right))
        {
            current->next = left;
            left = left->next;
        }
        else
        {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    if (left != NULL)
        current->next = left;
    if (right != NULL)
        current->next = right;

    return newHead;
}

struct record *mergeSort(struct record *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct record *mid = findMid(head);
    struct record *right = mid->next;
    mid->next = NULL;

    return merge(mergeSort(head), mergeSort(right));
}

void insertNode(struct record **head, struct record **tail, int id, char arr[])
{
    struct record *newNode = create(id, arr);
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void printPatients(struct record *head)
{

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
    struct record *head = NULL, *tail = NULL;
    printf("Enter number of patients: \n");
    scanf("%d", &totalElements);
    for (int index = 0; index < totalElements; index++)
    {
        scanf("%d %s", &id, severity);
        insertNode(&head, &tail, id, severity);
    }
    printf("The original list of patients based on severity priority order.\n");
    printPatients(head);

    head = mergeSort(head);

    printf("\nThe sorted list of patients based on severity priority order.\n");
    printPatients(head);
    return 0;
}

