#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

void insert(int item){
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

void rearrange(){
    int odd[50];
    int even[50];
    struct node * temp  = start;
    int eveIndex = 0, oddIndex = 0;
    while(temp){
        int test = temp->data;
        if(test%2==0){
            even[eveIndex++] = test;
        }
        else{
            odd[oddIndex++] = test;
        }
        temp = temp->next;
    }
    temp = start;

    while(temp){
       for(int i=0;i<eveIndex;i++){
        temp->data = even[i];
        temp = temp->next;
       }
       for(int i=0;i<oddIndex;i++){
        temp->data = odd[i];
        temp = temp->next;
       }
    }

}

int main(){
    int n;
    printf("Enter the total number of nodes:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    int count = 0;
    while(count<n){
        int value;
        scanf("%d",&value);
        insert(value);
        count++;
    }
    rearrange();
    viewList(start);
}
