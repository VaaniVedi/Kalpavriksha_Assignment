#include <stdio.h>

void printElements(int arr[], int totalElements)
{
    for (int index = 0; index < totalElements; index++)
    {
        printf("%d\t", arr[index]);
    }
}

void swap(int *firstNumber, int *secondNumber)
{
    int temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}

int partition(int arr[], int start, int end)
{
    int indexStart = start - 1;
    int pivot = arr[end];
    for (int indexTillPivot = start; indexTillPivot < end; indexTillPivot++)
    {
        if (arr[indexTillPivot] <= pivot)
        {
            indexStart++;
            swap(&arr[indexTillPivot], &arr[indexStart]);
        }
    }
    indexStart++;
    swap(&arr[end], &arr[indexStart]);
    return indexStart;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
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
    printf("Elements before sort:\n");
    printElements(arr, totalElements);

    quickSort(arr, 0, totalElements - 1);

    printf("\nElements after sort:\n");
    printElements(arr, totalElements);
    return 0;
}

