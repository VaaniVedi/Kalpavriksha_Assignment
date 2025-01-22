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

struct node *loopDetect()
{
    struct node *slow = start, *fast = start;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            slow = start;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

void rearrange()
{
    struct node *loopAt = loopDetect();
    if (loopAt == NULL)
    {
        printf("There is no loop\n");
        return;
    }

    struct node *temp = loopAt;
    while (temp->next != loopAt)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    int n;
    printf("Enter total number of nodes:\n");
    scanf("%d", &n);
    printf("Enter elements:\n");
    int count = 0;
    while (count < n)
    {
        int value;
        scanf("%d", &value);
        insert(value);
        count++;
    }

    printf("From which node do you want the cycle to start: \nEnter 0 if you want no cycle\n");
    int cyc;
    scanf("%d", &cyc);
    if(cyc!=0){
        struct node *cycleEnd = start;
        struct node *cycleStart = start;
        int index = 1;
        while (cycleEnd->next != NULL)
        {
            cycleEnd = cycleEnd->next;
        }
        while (cycleStart->next != NULL && index < cyc)
        {
            cycleStart = cycleStart->next;
            index++;
        }
        if (cycleStart != NULL)
        {
            cycleEnd->next = cycleStart;
        }
    }

    rearrange();
    viewList(start);
}
