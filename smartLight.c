/*Smart Home Lighting System
Problem Statement:
You are designing a multithreaded smart home system to control lights in different rooms. The system should support turning lights on and off and checking the current status of a room's light. Each room's lighting operations (TURN_ON, TURN_OFF, STATUS) should be handled by a separate thread to allow concurrent control of multiple rooms.
Operations:
"TURN_ON <room>" → Turns on the light in the specified room.
"TURN_OFF <room>" → Turns off the light in the specified room.
"STATUS <room>" → Returns "ON" if the light is on and "OFF" if the light is off.
Input:
The first line contains an integer n (1 ≤ n ≤ 100) — the number of commands.
The next n lines contain a command of one of the following types:
"TURN_ON <room>"
"TURN_OFF <room>"
"STATUS <room>"
Output:
For each "STATUS" command, print "ON" or "OFF" based on the light's current status. If a room has never been turned on or off, assume it is off.
Multithreading Constraints:
Each room should have a dedicated thread that processes its commands.
*/

#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define MAX_ROOMS 100

typedef struct {
    char name[50];
    int lights;
    pthread_mutex_t lock;
} Room;

Room rooms[MAX_ROOMS];
int roomCount = 0;

void *roomThreadFunction(void *arg) {
    while (1)
    return NULL;
}

int main() {
    int totalCommands, totalRooms;
    printf("Enter the number of rooms: ");
    scanf("%d", &totalRooms);
    
    for (int index = 0; index < totalRooms; index++) {
        scanf("%s", rooms[index].name);
        rooms[index].lights = 0;
        pthread_mutex_init(&rooms[index].lock, NULL);
        pthread_t thread;
        pthread_create(&thread, NULL, roomThreadFunction, NULL);
        roomCount++;
    }
    
    printf("Enter the number of commands: ");
    scanf("%d", &totalCommands);
    getchar();
    
    for (int index = 0; index < totalCommands; index++) {
        char command[10], roomName[50];
        scanf("%s %s", command, roomName);
        
        int roomIndex = -1;
        for (int countIndex = 0; countIndex < roomCount; countIndex++) {
            if (strcmp(rooms[countIndex].name, roomName) == 0) {
                roomIndex = countIndex;
                break;
            }
        }
        if (roomIndex == -1) {
            printf("Room '%s' not found!\n", roomName);
            continue;
        }
        
        pthread_mutex_lock(&rooms[roomIndex].lock);
        if (strcmp(command, "TURN_ON") == 0) {
            rooms[roomIndex].lights = 1;
        } else if (strcmp(command, "TURN_OFF") == 0) {
            rooms[roomIndex].lights = 0;
        } else if (strcmp(command, "STATUS") == 0) {
            if (rooms[roomIndex].lights == 1) {
                printf("ON\n");
            } else {
                printf("OFF\n");
            }
        }
        pthread_mutex_unlock(&rooms[roomIndex].lock);
    }
    return 0;
}
