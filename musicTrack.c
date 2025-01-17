#include <stdio.h>
#include <string.h>

struct track
{
    int id;
    char title[20];
    char artist[20];
    char genre[20];
    float duration;
};

void addTrack(struct track *tracks, int *countOfTracks, int maxTracks)
{
    if (*countOfTracks >= maxTracks)
    {
        printf("Cannot add more. Limit reached.\n");
    }
    else
    {
        struct track musicTrack;
        printf("Enter ID:\n");
        scanf("%d", &musicTrack.id);
        getchar();

        printf("Enter title\n");
        fgets(musicTrack.title, sizeof(musicTrack.title), stdin);
        musicTrack.title[strcspn(musicTrack.title, "\n")] = 0;

        printf("Enter artist\n");
        fgets(musicTrack.artist, sizeof(musicTrack.artist), stdin);
        musicTrack.artist[strcspn(musicTrack.artist, "\n")] = 0;

        printf("Enter genre\n");
        fgets(musicTrack.genre, sizeof(musicTrack.genre), stdin);
        musicTrack.genre[strcspn(musicTrack.genre, "\n")] = 0;

        printf("Enter the duration of song\n");
        scanf("%f", &musicTrack.duration);
        tracks[*countOfTracks] = musicTrack;
        (*countOfTracks)++;

        printf("Music added successfully\n");
    }
}

void deleteTrack(struct track *tracks, int *countOfTracks)
{
    int id, flag = 0;
    printf("Enter the id of music you want to delete\n");
    scanf("%d", &id);
    for (int index = 0; index < *countOfTracks; index++)
    {
        if (tracks[index].id == id)
        {
            for (int indexToI = index; indexToI < *countOfTracks - 1; indexToI++)
            {
                tracks[indexToI] = tracks[indexToI + 1];
            }
            (*countOfTracks)--;
            flag = 1;
            printf("Track deleted successfully\n");
            break;
        }
    }
    if (!flag)
    {
        printf("Track not found with this id\n");
    }
}

void displayTrack(struct track *tracks, int countOfTracks)
{
    if (countOfTracks == 0)
    {
        printf("No track is available to display\n");
    }
    else
    {
        for (int index = 0; index < countOfTracks; index++)
        {
            printf("ID: %d, Title: %s, Artist: %s, Genre: %s, Duration: %.2f\n",
                   tracks[index].id, tracks[index].title, tracks[index].artist, tracks[index].genre, tracks[index].duration);
        }
    }
}

void searchTrack(struct track *tracks, int countOfTracks)
{
    if (countOfTracks == 0)
    {
        printf("No track is available to search\n");
    }
    else
    {
        int id, flag = 0;
        printf("Enter the id of track for search\n");
        scanf("%d", &id);
        for (int index = 0; index < countOfTracks; index++)
        {
            if (tracks[index].id == id)
            {
                printf("ID: %d, Title: %s, Artist: %s, Genre: %s, Duration: %.2f\n",
                       tracks[index].id, tracks[index].title, tracks[index].artist, tracks[index].genre, tracks[index].duration);
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            printf("Track not found with this id\n");
        }
    }
}

void sortTrack(struct track *tracks, int countOfTracks)
{
    struct track temp;
    for (int index = 0; index < countOfTracks; index++)
    {
        for (int indexToI = index + 1; indexToI < countOfTracks; indexToI++)
        {
            if (strcmp(tracks[index].title, tracks[indexToI].title) > 0)
            {
                temp = tracks[index];
                tracks[index] = tracks[indexToI];
                tracks[indexToI] = temp;
            }
        }
    }
    printf("Music tracks successfully sorted by Title.\n");
    displayTrack(tracks, countOfTracks);
}

int main()
{
    int maxTracks = 100;
    struct track tracks[maxTracks];
    int countOfTracks = 0;
    int choice;

    do
    {
        printf("\nSelect option:\n1. Add Track\n2. Delete Track\n3. Display Track\n4. Search Track\n5. Sort Track\n6. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addTrack(tracks, &countOfTracks, maxTracks);
            break;
        case 2:
            deleteTrack(tracks, &countOfTracks);
            break;
        case 3:
            displayTrack(tracks, countOfTracks);
            break;
        case 4:
            searchTrack(tracks, countOfTracks);
            break;
        case 5:
            sortTrack(tracks, countOfTracks);
            break;
        case 6:
            printf("Exiting from program\n");
            break;
        default:
            printf("Invalid Choice. Try again\n");
        }
    } while (choice != 6);
    printf("Exited from program\n");
    return 0;
}

