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

void bubbleSort(int arr[], int totalElements)
{

    for (int index = 0; index < totalElements; index++)
    {
        for (int comparator = 0; comparator < totalElements - index - 1; comparator++)
        {
            if (arr[comparator] > arr[comparator + 1])
            {
                swap(&arr[comparator + 1], &arr[comparator]);
            }
        }
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
    bubbleSort(arr, totalElements);
    printf("\nElements after sort:\n");
    printfElements(arr, totalElements);
    return 0;
}

