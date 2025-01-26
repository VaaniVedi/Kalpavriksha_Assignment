#include <stdio.h>
void printfElements(int arr[], int totalElements)
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

void selectionSortByMinimumElement(int arr[], int totalElements)
{
    for (int index = 0; index < totalElements - 1; index++)
    {
        int minComparator = index;
        for (int comparator = index + 1; comparator < totalElements; comparator++)
        {
            if (arr[comparator] < arr[minComparator])
            {
                minComparator = comparator;
            }
        }
        swap(&arr[minComparator], &arr[index]);
    }
}

void selectionSortByMaximumElement(int arr[], int totalElements)
{
    for (int index = totalElements - 1; index >= 0; index--)
    {
        int maxComparator = index;
        for (int comparator = 0; comparator < index; comparator++)
        {
            if (arr[comparator] > arr[maxComparator])
            {
                maxComparator = comparator;
            }
        }
        swap(&arr[maxComparator], &arr[index]);
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
    printfElements(arr, totalElements);

    selectionSortByMinimumElement(arr, totalElements);
    
    printf("\nElements after sort:\n");
    printfElements(arr, totalElements);
    return 0;
}
