#include <stdio.h>
#include <string.h>
#define size 500

typedef struct
{
    char stack[size][size];
    int indexOfTop;
} site;

void addWebsite(site *mySite)
{
    char site[size];
    printf("Enter url:\n");
    scanf("%s", site);
    if (mySite->indexOfTop == size - 1)
    {
        printf("Stack overflow!!\n");
        return;
    }
    mySite->indexOfTop++;
    strcpy(mySite->stack[mySite->indexOfTop], site);
}

void viewHistory(site *mySite)
{
    if (mySite->indexOfTop == -1)
    {
        printf("Nothing to show!\n");
    }
    else
    {
        for (int index = 0; index <= mySite->indexOfTop; index++)
        {
            printf("%s\n", mySite->stack[index]);
        }
    }
}

void editHistory(site *mySite)
{
    char toFind[500];
    char changeTo[500];
    int location = -1;
    printf("Enter the site you want to modify:\n");
    scanf("%s", &toFind);
    for (int index = 0; index <= mySite->indexOfTop; index++)
    {
        if (strcmp(toFind, mySite->stack[index]) == 0)
        {
            location = index;
            break;
        }
    }
    if (location != -1)
    {
        printf("Enter the change:\n");
        scanf("%s", changeTo);
        strcpy(mySite->stack[location], changeTo);
    }
    else
    {
        printf("Does not exist! Try something else.\n");
    }
}

void removeHistory(site *mySite)
{
    if (mySite->indexOfTop == -1)
    {
        printf("Nothing here! Underflow.\n");
    }
    printf("Removed site is %s\n", mySite->stack[mySite->indexOfTop]);
    mySite->indexOfTop--;
}

void clearHistory(site *mySite)
{
    if (mySite->indexOfTop == -1)
    {
        printf("History is cleared already\n");
    }
    else
    {
        mySite->indexOfTop = -1;
        printf("History cleared.\n");
    }
}

void viewMostRecent(site *mySite)
{
    printf("The most recently visited site is\n%s\n", mySite->stack[mySite->indexOfTop]);
}

int main()
{
    site mySite;
    mySite.indexOfTop = -1;
    int choice;
    while (1)
    {
        printf("\n1. Add a website \n2. View History \n3. Edit a URL \n4. Remove a recent website\n5. Clear all URLs\n6. View most recent URL\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addWebsite(&mySite);
            break;
        case 2:
            viewHistory(&mySite);
            break;
        case 3:
            editHistory(&mySite);
            break;
        case 4:
            removeHistory(&mySite);
            break;
        case 5:
            clearHistory(&mySite);
            break;
        case 6:
            viewMostRecent(&mySite);
            break;
        case 7:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice!!\n");
        }
    }
}

