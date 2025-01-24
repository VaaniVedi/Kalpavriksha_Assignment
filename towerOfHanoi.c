#include <stdio.h>

void towerOfHanoi(int disks, char sourceRod, char extraRod, char destinationRod)
{
    if (disks == 0)
    {
        return;
    }
    towerOfHanoi(disks - 1, sourceRod, destinationRod, extraRod);
    printf("Move disk %d from rod %c to rod %c \n", disks, sourceRod, destinationRod);
    towerOfHanoi(disks - 1, extraRod, sourceRod, destinationRod);
}
int main()
{
    printf("Enter the number of disks for which you want to play:\n");
    int disks;
    scanf("%d", &disks);
    printf("Playing from rod A to rod C\n\n");
    towerOfHanoi(disks,'A','B','C');
    return 0;
}

