#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct node
{
    int key;
    int value;
    struct node *next;
} node;

int hashFunc(int key)
{
    return key % SIZE;
}

void insert(node **hashTable, int key, int value)
{
    int index = hashFunc(key);
    node *newNode = (node *)malloc(sizeof(node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    if (hashTable[index] = NULL)
    {
        hashTable[index] = newNode;
    }
    else
    {
        node *temp = hashTable[index];
        while (temp)
        {
            if (temp->key == key)
            {
                temp->value = value;
                return;
            }
            temp = temp->next;
        }
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

void search(node *hashTable[], int key)
{
    int index = hashFunc(key);
    node *temp = hashTable[index];
    while (temp)
    {
        if (temp->key == key)
        {
            printf("Value: %d\n", temp->value);
            return;
        }
        temp = temp->next;
    }
    printf("KEy not found!!\n");
}

void delete(node **hashTable, int key)
{
    int index = hashFunc(key);
    node *temp = hashTable[index];
    node *prev = NULL;
    while (temp)
    {
        if (temp->key == key)
        {
            if (prev == NULL)
            {
                hashTable[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("KEy %d deleted.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Not found!\n");
}

void display(node *hashTable[])
{
    printf("Hash Table:\n");
    printf("\nKey | Value\n");

    for (int index = 0; index < SIZE; index++)
    {
        printf(" %d  | ", index);
        node *temp = hashTable[index];
        while (temp)
        {
            printf("(%d, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int choice, key, value;
    node *hashTable[SIZE] = {NULL};

    while (1)
    {
        printf("\n1. Insert \n2. Search \n3. Delete \n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter key value pair: ");
            scanf("%d %d", &key, &value);
            insert(hashTable, key, value);
            break;
        case 2:
            printf("Enter key: ");
            scanf("%d", &key);
            search(hashTable, key);
            break;
        case 3:
            printf("Enter key: ");
            scanf("%d", &key);
            delete (hashTable, key);
            break;
        case 4:
            display(hashTable);
            break;
        case 5:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice!!\n");
        }
    }
}

