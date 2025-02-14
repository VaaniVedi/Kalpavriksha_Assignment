#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
typedef struct node
{
    char word[SIZE];
    int key;
    struct node *next;
} node;

int arr[26];

void insertArr(int *arr,char *str){
    
    for(int i = 0; i < 26; i++){
        arr[i] = 0;
    }
    for(int i = 0; str[i] != '\0'; i++){
        arr[str[i] - 'a']++;
    }
}

int matches(int curr[], int prev[]){
    for(int i = 0; i<26; i++){
        if(curr[i]!=prev[i]){
            return 0;
        }
    }
    return 1;
}

int matching(char *str, node **hashTable){
    int curr[26];
    insertArr(curr,str);
    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i])
        {
            node *temp = hashTable[i];
            while (temp)
            {
                int prev[26];
                insertArr(prev,temp->word);
                int val = matches(curr,prev);
                if(val == 1){
                    return i;
                }
                temp = temp->next;
            }
        }
    }
    return -1;
}

int hashFunc(node **hashTable, char *str)
{
    int res = matching(str, hashTable);
    if(res == -1){
        int sum = 0;
        for(int i  =0; i<strlen(str); i++){
            sum= sum+ str[i] - '0';
        }
        return (sum % SIZE);
    } 
    else return res;
}

void insert(node **hashTable, int key, char *str)
{
    int index = hashFunc(hashTable, str);
    node *newNode = (node *)malloc(sizeof(node));
    newNode->key = key;
    strcpy(newNode->word, str);
    newNode->next = NULL;
    if (hashTable[index] == NULL)
    {
        hashTable[index] = newNode;
    }
    else
    {
        node *temp = hashTable[index];
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }    
}

void printAnagrams(node *hashTable[])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i])
        {
            printf("Anagram Group:");
            node *temp = hashTable[i];
            while (temp)
            {
                printf(" %s", temp->word);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

int main()
{
    int n, len;
    scanf("%d",&n);
    node *hashTable[SIZE] = {NULL};
    char str[SIZE];
    for(int i =0; i<n; i++){
        printf("Enter the string:\n");
        scanf("%s",str);
        len = strlen(str);
        insert(hashTable, len, str);
    }
    printAnagrams(hashTable);
    return 0;
}
