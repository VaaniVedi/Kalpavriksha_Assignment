#include <stdio.h>
#include <string.h>
#define MAX_SIZE 20

typedef struct
{
    char docName[100];
    int page;
} job;

typedef struct
{
    job jobQueue[MAX_SIZE];
    int start;
    int end;
    int size;
} print;

int isFound(print *printJob, char *target)
{
    int foundAt = -1;
    for (int index = printJob->start; index <= printJob->end; index++)
    {
        if (strcmp(target, printJob->jobQueue[index].docName) == 0)
        {
            foundAt = index;
        }
    }
    return foundAt;
}

void addJob(print *printJob)
{
    if (printJob->size == MAX_SIZE + 1)
    {
        printf("Queue is full. Try later...\n");
        return;
    }
    printf("Enter document name:\n");
    char name[100];
    scanf("%s", name);

    int isValid = isFound(printJob, name);
    if (isValid == -1)
    {
        if (printJob->start == -1 && printJob->end == -1)
        {
            printJob->start = 0;
            printJob->end = 0;
            scanf("%d", &printJob->jobQueue[printJob->end].page);
            strcpy(printJob->jobQueue[printJob->end].docName, name);
        }
        else
        {
            printJob->end++;
            scanf("%d", &printJob->jobQueue[printJob->end].page);
            strcpy(printJob->jobQueue[printJob->end].docName, name);
        }
    }
    else
    {
        printf("Job name is duplicate! Try again with a different name\n");
    }
}

void viewJob(print *printJob)
{
    if (printJob->start == -1 && printJob->end == -1)
    {
        printf("No jobs currently!\n");
    }
    else
    {
        int index = printJob->start;
        while (index <= printJob->end)
        {
            printf("\nDocument Name:%s\nPage Nos.: %d\n", printJob->jobQueue[index].docName, printJob->jobQueue[index].page);
            index++;
        }
        printf("\n");
    }
}

void editJob(print *printJob)
{
    if (printJob->start == -1 && printJob->end == -1)
    {
        printf("Queue empty!...\n");
        return;
    }
    char target[MAX_SIZE], update[MAX_SIZE];
    int updatePage;
    printf("Enter the job you want to edit:\nEnter the name of job:\t");
    scanf("%s", target);
    int location = isFound(printJob, target);
    if (location == -1)
    {
        printf("Job is not present in the queue.\n");
    }
    else
    {
        printf("\nEnter the name of updated job:\n");
        scanf("%s", printJob->jobQueue[location].docName);
        printf("Enter the pages of updated job:\n");
        scanf("%d", &printJob->jobQueue[location].page);
    }
}

void processJob(print *printJob)
{
    if (printJob->start == -1 && printJob->end == -1)
    {
        printf("Nothing to process! Queue empty!...\n");
        return;
    }
    char processedDocname[MAX_SIZE];
    strcpy(processedDocname, printJob->jobQueue[printJob->start].docName);
    int page = printJob->jobQueue[printJob->start].page;
    printf("\nProcessing-\ndocName: %s\npageNo: %d\n", processedDocname, page);
    if (printJob->start == printJob->end)
    {
        printJob->start = -1;
        printJob->end = -1;
    }
    else
    {
        printJob->start++;
    }
}

void cancelJob(print *printJob)
{
    if (printJob->start == -1 && printJob->end == -1)
    {
        printf("No jobs currently!\n");
        return;
    }

    char target[MAX_SIZE];
    printf("Enter the job you want to cancel:\nEnter the name of job:\t");
    scanf("%s", target);
    int location = isFound(printJob, target);
    if (location == -1)
    {
        printf("Entered job is not present.\n");
    }
    else
    {
        printJob->end--;
        if (printJob->end < printJob->start)
        {
            printJob->start = -1;
            printJob->end = -1;
        }
        printf("Job deleted!...\n\n");
    }
}

int main()
{
    int choice;
    print printJob;
    printJob.start = -1;
    printJob.end = -1;
    printJob.size = 0;
    while (1)
    {
        printf("\n1.  Add a Print Job \n2. View Pending Jobs \n3. Edit a Job \n4. Process a Job\n5. Cancel a Job\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addJob(&printJob);
            break;
        case 2:
            viewJob(&printJob);
            break;
        case 3:
            editJob(&printJob);
            break;
        case 4:
            processJob(&printJob);
            break;
        case 5:
            cancelJob(&printJob);
            break;
        case 6:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid Choice!\nTry Again!...\n");
        }
    }
}

