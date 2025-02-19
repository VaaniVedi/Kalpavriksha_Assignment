#include <stdio.h>
#include <stdlib.h>
#define transaction 10000

typedef struct user
{
    int transactionID;
    int userID;
    float amount;
    int timeStamp;
    struct user *next;
} user;

int hashFunc(int uID)
{
    return uID % transaction;
}

int detect(user *curr, user *checker)
{
    return (curr != checker && curr->transactionID == checker->transactionID && curr->amount == checker->amount && abs(curr->timeStamp - checker->timeStamp) <= 60);
}

void deleteInvalidTransactions(user **users)
{
    for (int i = 0; i < transaction; i++)
    {
        user *curr = users[i];

        while (curr != NULL)
        {
            user *checker = users[i];
            user *checkerPrev = NULL;

            while (checker != NULL)
            {
                if (detect(curr, checker))
                {

                    if (checkerPrev == NULL)
                    {
                        users[i] = checker->next;
                    }
                    else
                    {
                        checkerPrev->next = checker->next;
                    }

                    user *toDelete = checker;
                    checker = checker->next;
                }
                else
                {
                    checkerPrev = checker;
                    checker = checker->next;
                }
            }
            curr = curr->next;
        }
    }
}

void insert(user **users, int uID)
{
    int index = hashFunc(uID);
    user *newNode = (user *)malloc(sizeof(user));
    newNode->userID = uID;
    printf("\nEnter the transaction ID: ");
    scanf("%d", &newNode->transactionID);
    printf("\nEnter the amount: ");
    scanf("%f", &newNode->amount);
    printf("\nEnter the time in seconds: ");
    scanf("%d", &newNode->timeStamp);
    newNode->next = NULL;

    if (users[index] == NULL)
    {
        users[index] = newNode;
    }
    else
    {
        user *temp = users[index];
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void print(user **users)
{
    for (int i = 0; i < transaction; i++)
    {
        if (users[i])
        {
            user *temp = users[i];
            while (temp)
            {
                printf("user_ID: %d\ttransaction_ID: %d\tamount: %.2f\ttimeStamp: %d\n", temp->userID, temp->transactionID, temp->amount, temp->timeStamp);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

int main()
{
    int n, uID;
    scanf("%d", &n);
    user *users[transaction] = {NULL};

    for (int i = 0; i < n; i++)
    {
        printf("Enter the details for %d trransaction:\n", i + 1);
        printf("Enter user ID: ");
        scanf("%d", &uID);
        insert(users, uID);
    }
    printf("\nBefore Deletion:\n");
    print(users);

    deleteInvalidTransactions(users);

    printf("\nAfter Deletion:\n");
    print(users);

    return 0;
}
