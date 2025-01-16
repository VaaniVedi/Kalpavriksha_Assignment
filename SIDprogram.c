#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STUDENTS 100
#define MAX_ID_LENGTH 20

typedef struct
{
    char id[MAX_ID_LENGTH];
    int badminton;
    int tt;
    int cricket;
} Student;

int findStudentIndex(Student students[], int count, char id[])
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].id, id) == 0)
        {
            return i;
        }
    }
    return -1;
}

void addGameToStudent(Student *student, char game[])
{
    if (strcmp(game, "badminton") == 0)
    {
        student->badminton = 1;
    }
    else if (strcmp(game, "TT") == 0)
    {
        student->tt = 1;
    }
    else if (strcmp(game, "cricket") == 0)
    {
        student->cricket = 1;
    }
}

void printSortedStudents(Student students[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(students[i].id, students[j].id) > 0)
            {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", students[i].id);
    }
}

int main()
{
    int n, count = 0;
    Student students[MAX_STUDENTS];
    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        students[i].badminton = 0;
        students[i].tt = 0;
        students[i].cricket = 0;
    }
    printf("Enter number of records: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        char id[MAX_ID_LENGTH], game[MAX_ID_LENGTH];
        printf("Enter ID and game name: ");
        scanf("%s %s", id, game);

        int index = findStudentIndex(students, count, id);
        if (index == -1)
        {
            strcpy(students[count].id, id);
            addGameToStudent(&students[count], game);
            count++;
        }
        else
        {
            addGameToStudent(&students[index], game);
        }
    }
    printf("\nStudents enrolled in all three games:\n");
    Student allThree[MAX_STUDENTS];
    int allThreeCount = 0;

    for (int i = 0; i < count; i++)
    {
        if (students[i].badminton && students[i].tt && students[i].cricket)
        {
            allThree[allThreeCount++] = students[i];
        }
    }
    printSortedStudents(allThree, allThreeCount);
    printf("\nAll unique students enrolled in at least one game:\n");
    printSortedStudents(students, count);
    return 0;
}

