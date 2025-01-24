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
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = NULL;
    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
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

void createCycle(){
    printf("From which node do you want the cycle to start: \nEnter 0 if you want no cycle\n");
    int cycleAt;
    scanf("%d", &cycleAt);
    if(cycleAt!=0){
        struct node *cycleEnd = start;
        struct node *cycleStart = start;
        int index = 1;
        while (cycleEnd->next != NULL)
        {
            cycleEnd = cycleEnd->next;
        }
        while (cycleStart->next != NULL && index < cycleAt)
        {
            cycleStart = cycleStart->next;
            index++;
        }
        if (cycleStart != NULL)
        {
            cycleEnd->next = cycleStart;
        }
    }
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
    int nodes;
    printf("Enter total number of nodes:\n");
    scanf("%d", &nodes);
    printf("Enter elements:\n");
    int count = 0;
    while (count < nodes)
    {
        int value;
        scanf("%d", &value);
        insert(value);
        count++;
    }
    createCycle();

    

    rearrange();
    viewList(start);
}

