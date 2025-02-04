#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(int n)
{
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newNode = NULL;
    for (int i = 0; i < n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

void print(struct node *head)
{
    struct node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

struct node *finkK(struct node *head, int k)
{
    struct node *temp;
    int kCopy = k;
    while (temp != NULL && k > 0)
    {
        if (temp->next != NULL)
            temp = temp->next;
        else
            return NULL;
        kCopy--;
    }
    return temp;
}

struct node *reverse(struct node *head, struct node *tail)
{
    struct node *newLLhead = NULL;
    struct node *temp = head;
    while (temp != tail)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    while (head != NULL)
    {
        struct node *newLL = (struct node *)malloc(sizeof(struct node));
        if (newLLhead == NULL)
        {
            newLL->data = head->data;
            newLL->next = NULL;
            newLLhead = newLL;
            head = head->next;
        }
        else
        {
            newLL->data = head->data;
            newLL->next = newLLhead;
            newLLhead = newLL;
            head = head->next;
        }
    }
    return newLLhead;
}

struct node *reverseK(struct node *head, int k)
{
    struct node *kthNode;
    struct node *temp = head;
    // struct node *headP = head;
    struct node *ans = (struct node *)malloc(sizeof(struct node));
    ans->data = -1;

    while (temp->next != NULL)
    {
        kthNode = finkK(temp, k);
        if (kthNode == NULL)
        {
            break;
        }
        ans = reverse(head, kthNode);
        if (kthNode->next)
        {
            temp = kthNode->next;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int totElements;
    printf("Enter total nodes:\n");
    scanf("%d", &totElements);
    struct node *head = NULL;
    int k;
    scanf("%d", &k);

    head = create(totElements);
    print(head);
    struct node *newHead;
    // newHead = reverse(head);
    newHead = reverseK(head, k);
    print(newHead);

    return 0;
}
