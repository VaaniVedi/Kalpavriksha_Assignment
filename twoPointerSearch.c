#include <stdio.h>

void printfElements(int arr[], int totalElements)
{
    for (int index = 0; index < totalElements; index++)
    {
        printf("%d\t", arr[index]);
    }
    printf("\n");
}

int twoPointerTechnique(int arr[], int totalElements, int key)
{
    int start = 0;              
    int end = totalElements - 1;
    while (start <= end)
    {
        if (arr[start] == key || arr[end] == key)
        {
            return arr[start] == key ? start : end;
        }
        start++;
        end--;
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

    int searchResults = twoPointerTechnique(arr, totalElements, key);
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

