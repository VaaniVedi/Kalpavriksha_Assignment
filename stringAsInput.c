#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef enum
{
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5
} Grade;

typedef struct node
{
    char stName[MAX_SIZE];
    Grade grade;
    struct node *next;
} node;

node* create(char str[]){
    node* head = NULL;
    node* tail = NULL;
    char* tok= strtok(str,",");
    while(tok!=NULL){
        char name[MAX_SIZE];
        char grade[2];

        if(sscanf(tok, "%s %s", name, grade)!=2){
            printf("Invalid input format: %s\n", tok);
            tok = strtok(NULL, ",");
            continue;
        }

        node *newNode = (node*)malloc(sizeof(node));
        newNode->next = NULL;
        strcpy(newNode->stName,name);

        if(strcmp(grade,"A")==0) newNode->grade = A;
        else if (strcmp(grade,"B")==0) newNode->grade = B;
        else if (strcmp(grade,"C")==0) newNode->grade = C;
        else if (strcmp(grade,"D")==0) newNode->grade = D;
        else if (strcmp(grade,"E")==0) newNode->grade = E;
        else {
            printf("Invalid grade for %s\n", name);
            free(newNode);
            tok = strtok(NULL, ",");
            continue;
        }

        printf("%s %d",newNode->stName,newNode->grade);
        
        if(head==NULL){
            head= newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
        tok = strtok(NULL,",");
    }
    return head;
}

node *bubbleSort(node *head)
{
    node *temp = head;
    for (node *i = head; i->next != NULL; i = i->next)
    {
        for (node *j = i->next; j != NULL; j = j->next)
        {
            if (i->grade > j->grade)
            {
                char temp[50];
                strcpy(temp, i->stName);
                strcpy(i->stName, j->stName);
                strcpy(j->stName, temp);

                Grade tempGrade;
                tempGrade = i->grade;
                i->grade = j->grade;
                j->grade = tempGrade;
            }
        }
    }
    return head;
}

void display(node *head)
{
    node *temp = head;
    while (temp)
    {
        printf("| %s ", temp->stName);
        switch (temp->grade)
        {
        case A:
            printf("A |\n");
            break;
        case B:
            printf("B |\n");
            break;
        case C:
            printf("C |\n");
            break;
        case D:
            printf("D |\n");
            break;
        case E:
            printf("E |\n");
            break;
        }
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    char str[MAX_SIZE*10];
    fgets(str, MAX_SIZE*10, stdin);
    str[strcspn(str,"\n")] = '\0';
    node* head = create(str);
    head = bubbleSort(head);
    display(head);
    return 0;
}
