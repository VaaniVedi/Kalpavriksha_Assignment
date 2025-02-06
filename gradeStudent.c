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

// node* create(char str[]){
//     node* head = NULL;
//     node* tail = NULL;
//     node* newNode = NULL;
//     char* tok= strtok(str,",");
//     while(tok!=NULL){
//         char* name = strtok(tok," ");
//         char* grade = strtok(NULL," ");
//         if (name == NULL || grade == NULL) {
//             tok = strtok(NULL, ",");
//             continue;
//         }
//         newNode = (node*)malloc(sizeof(node));
//         newNode->next = NULL;
//         strcpy(newNode->stName,name);

//         if(strcmp(grade,"A")==0) newNode->grade = A;
//         else if (strcmp(grade,"B")==0) newNode->grade = B;
//         else if (strcmp(grade,"C")==0) newNode->grade = C;
//         else if (strcmp(grade,"D")==0) newNode->grade = D;
//         else if (strcmp(grade,"E")==0) newNode->grade = E;

//         if(head==NULL){
//             head= newNode;
//             tail = newNode;
//         }
//         else{
//             tail->next = newNode;
//             tail = tail->next;
//         }

//         tok = strtok(NULL,",");
//     }
//     return head;
// }

node *create(int tot)
{
    node *head = NULL;
    node *tail = NULL;
    node *newNode = NULL;
    int index = 1;
    while (index <= tot)
    {
        newNode = (node *)malloc(sizeof(node));
        newNode->next = NULL;
        char grade[2];
        scanf("%s %s", newNode->stName, grade);

        if (strcmp(grade, "A") == 0)
            newNode->grade = A;
        else if (strcmp(grade, "B") == 0)
            newNode->grade = B;
        else if (strcmp(grade, "C") == 0)
            newNode->grade = C;
        else if (strcmp(grade, "D") == 0)
            newNode->grade = D;
        else if (strcmp(grade, "E") == 0)
            newNode->grade = E;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        index++;
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
    int totElements;
    scanf("%d", &totElements);
    node *head = create(totElements);
    head = bubbleSort(head);
    display(head);
    return 0;
}

