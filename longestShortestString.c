#include <stdio.h>
#include <string.h>

void longestWord(char *inputString, char stringTokens[][100], int arrIndex)
{
    int maxLen = 0;
    for (int index = 0; index < arrIndex; index++)
    {
        int tempLength = strlen(stringTokens[index]);
        if (tempLength > maxLen)
        {
            maxLen = tempLength;
        }
    }
    printf("The longest word(s) are:\n");
    for (int index = 0; index < arrIndex; index++)
    {
        int tempLength = strlen(stringTokens[index]);
        if (tempLength == maxLen)
        {
            printf("%s\n", stringTokens[index]);
        }
    }
}

void shortestWord(char *inputString, char stringTokens[][100], int arrIndex)
{
    int minLen = 101;
    for (int index = 0; index < arrIndex; index++)
    {
        int tempLength = strlen(stringTokens[index]);
        if (tempLength < minLen)
        {
            minLen = tempLength;
        }
    }
    printf("The shortest word(s) are:\n");
    for (int index = 0; index < arrIndex; index++)
    {
        int tempLength = strlen(stringTokens[index]);
        if (tempLength == minLen)
        {
            printf("%s\n", stringTokens[index]);
        }
    }
}

int main()
{
    char inputString[1000];
    char stringTokens[100][100];
    printf("Enter the string:\n");
    fgets(inputString, 1000, stdin);
    inputString[strcspn(inputString, "\n")] = '\0';
    char *token = strtok(inputString, " ");
    int arrIndex = 0;
    while (token != NULL)
    {
        if (strlen(token) > 0)
        {
            strcpy(stringTokens[arrIndex], token);
            arrIndex++;
        }
        token = strtok(NULL, " ");
    }
    longestWord(inputString, stringTokens, arrIndex);
    shortestWord(inputString, stringTokens, arrIndex);
    return 0;
}
