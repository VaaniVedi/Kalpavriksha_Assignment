#include <stdio.h>

void printfElements(int arr[], int totalElements)
{
    for (int index = 0; index < totalElements; index++)
    {
        printf("%d\t", arr[index]);
    }
    printf("\n");
}

int binarySearch(int arr[], int totalElements, int key)
{
    int start = 0, end = totalElements - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[1000], totalElements;
    printf("Enter the total number of elements in the array:\n");
    scanf("%d", &totalElements);
    printf("Enter sorted array elements:\n");
    for (int index = 0; index < totalElements; index++)
    {
        scanf("%d", &arr[index]);
    }

    printf("Elements of the array:\n");
    printfElements(arr, totalElements);

    int key;
    printf("Enter the element you want to search in array:\n");
    scanf("%d", &key);

    int searchResults = binarySearch(arr, totalElements, key);
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

