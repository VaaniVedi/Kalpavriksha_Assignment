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
    if (strcmp(severity, "Critical") == 0) return 1;
    if (strcmp(severity, "Serious") == 0) return 2;
    return 3; 
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

struct record *merge(struct record *left, struct record *right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    struct record *newHead = NULL;
    if ((priority(left->condition) < priority(right->condition) || (priority(left->condition) == priority(right->condition) && left->id < right->id)))
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
        if (priority(left->condition) < priority(right->condition) || (priority(left->condition) == priority(right->condition) && left->id < right->id)) 
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

    if (left != NULL) current->next = left;
    if (right != NULL) current->next = right;
    
    return newHead;
}

struct record *mergeSort(struct record *head)
{
    if (head == NULL || head->next == NULL) return head;
    struct record *mid = findMid(head);
    struct record *left = head;
    struct record *right = mid->next;
    mid->next = NULL;
    left = mergeSort(left);
    right = mergeSort(right);
    struct record *result = merge(left, right);
    return result;
}

void insertNode(struct record **head, int id, char arr[])
{
    struct record *newNode = create(id, arr);
    if (*head == NULL )
    {
        *head = newNode;
    }
    else{
        struct record* temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;  
    }
}

void printEle(struct record *head)
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
    struct record *head = NULL;
    printf("Enter number of patients: \n");
    scanf("%d", &totalElements);
    for (int index = 0; index < totalElements; index++)
    {
        scanf("%d %s", &id, severity);
        insertNode(&head, id, severity);
    }
    printf("The original list of patients based on severity priority order.\n");
    printEle(head);
    
    head = mergeSort(head);
    
    printf("\nThe sorted list of patients based on severity priority order.\n");
    printEle(head);
    return 0;
}

