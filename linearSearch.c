#include <stdio.h>

void printfElements(int arr[], int totalElements)
{
    for (int index = 0; index < totalElements; index++)
    {
        printf("%d\t", arr[index]);
    }
    printf("\n");
}

int linearSearch(int arr[], int totalElements, int key)
{
    for (int index = 0; index < totalElements; index++)
    {
        if (arr[index] == key)
        {
            return index;
        }
    }
    return -1;
}

int main()
{
    int arr[1000], totalElements;
    printf("Enter the total number of elements in the array:\n");
    scanf("%d", &totalElements);
    printf("Enter array elements:\n");
    for (int index = 0; index < totalElements; index++)
    {
        scanf("%d", &arr[index]);
    }

    printf("Elements of the array:\n");
    printfElements(arr, totalElements);

    int key;
    printf("Enter the element you want to search in array:\n");
    scanf("%d", &key);

    int searchResults = linearSearch(arr, totalElements, key);

    if (searchResults != -1)
    {
        printf("The element is present at %d index.", searchResults);
    }
    else
    {
        printf("The element is not present.");
    }

    return 0;
}

