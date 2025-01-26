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

void insertionSort(int arr[], int totalElements)
{
    for (int index = 0; index <= totalElements - 1; index++)
    {
        int comparator = index;
        while (comparator > 0 && arr[comparator - 1] > arr[comparator])
        {
            swap(&arr[comparator - 1], &arr[comparator]);
            comparator--;
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
    printElements(arr, totalElements);

    insertionSort(arr, totalElements);

    printf("\nElements after sort:\n");
    printElements(arr, totalElements);
    return 0;
}

