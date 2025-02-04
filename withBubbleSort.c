#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    char condition[50];
    struct node *next;
} node;

int priority(char str[50]){
    if (strcmp(str, "serious") == 0) {
        return 2;
    }
    if (strcmp(str, "stable") == 0) {
        return 1;
    }
    return 3;
}

void swapNum(int* first, int* second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

void swapStr(char first[], char second[]){
    char temp[50];
    strcpy(temp, first);
    strcpy(first, second);
    strcpy(second, temp);
}

void **sortLL(node **head){
    node *i, *j;
    for( i = *head; i->next != NULL; i = i->next){
        for( j = i -> next; j!= NULL; j= j->next ){
            if(priority(i->condition) < priority(j->condition)){
                swapNum(&i->data, &j->data);
                swapStr(i->condition,j->condition);
            }
        }
    }
}

node *createLL(int n)
{
    int i = 0;
    node *head = NULL;
    node *temp = NULL;
    node *p = NULL;
    for (int i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));
        printf("Enter the data for node number %d:", i + 1);
        scanf("%d", &(temp->data));
        printf("Enter the condition for node number %d:", i + 1);
        scanf("%s",(temp->condition));
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp; 
        }
        else
        {
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
}

void displayLL(node * head){
    node * p = head;
    while(p){
        printf("%d %s->",p->data,p->condition);
        p=p->next;
    }
    printf("NULL");
}

int main()
{
    int n = 0;
    node *head = NULL;
    printf("\nHow many nodes: ");
    scanf("%d", &n);
    head = createLL(n);
    sortLL(&head);
    displayLL(head);
    return 0;
}
