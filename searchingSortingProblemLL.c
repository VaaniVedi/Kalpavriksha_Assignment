#include <stdlib.h>
#include <stdio.h>
struct node
{
    int item;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->item = data;
    newNode->next = NULL;
    return newNode;
}

void insert(int data, struct node **head)
{
    struct node *newNode = createNode(data);
    newNode->item = data;
    newNode->next = NULL;
    if ((*head) == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct node *tail = *head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

void printLL(struct node *head)
{
    struct node *temp = head;
    while (temp)
    {
        printf("%d -> ", temp->item);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node *mergeSortedLists(struct node *list1, struct node *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    if (list1->item < list2->item)
    {
        list1->next = mergeSortedLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeSortedLists(list1, list2->next);
        return list2;
    }
}

struct node *getMiddle(struct node *head)
{
    if (!head || !head->next)
        return head;
    struct node *slow = head, *fast = head, *prev = NULL;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev)
        prev->next = NULL;
    return slow;
}

struct node *sortLL(struct node *head)
{
    if (!head || !head->next)
        return head;
    struct node *middle = getMiddle(head);
    struct node *left = sortLL(head);
    struct node *right = sortLL(middle);
    return mergeSortedLists(left, right);
}

struct node *identifyUnique(struct node *head)
{
    int map[1000] = {0};
    struct node *temp = head;
    while (temp)
    {
        if (temp->item >= 0 && temp->item <= 1000)
        {
            map[temp->item]++;
        }
        temp = temp->next;
    }
    struct node *newHead = NULL;
    temp = head;
    while (temp)
    {
        if (map[temp->item] == 1)
        {
            insert(temp->item, &newHead);
        }
        temp = temp->next;
    }
    return newHead;
}

int main()
{
    int totElements;
    printf("Enter the total elements in linked list:\n");
    scanf("%d", &totElements);
    if(totElements)
    struct node *head = NULL;
    printf("Enter the value that is greater than 0 and less than 1000\n");
    for (int index = 0; index < totElements; index++)
    {
        int item;
        do
        {
            scanf("%d", &item);
            if (item < 0 || item > 1000)
            {
                printf("Invalid input! Please enter a value between 9 and 1000.\n");
            }
        } while (item < 0 || item > 1000);
        insert(item, &head);
    }
    printLL(head);
    struct node *newHead = identifyUnique(head);
    newHead = sortLL(newHead);
    printLL(newHead);
    return 0;
}

