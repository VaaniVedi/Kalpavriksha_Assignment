#include <stdio.h>
void printElements(int arr[], int totalElements)
{
    for (int index = 0; index < totalElements; index++)
    {
        printf("%d\t", arr[index]);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int leftSize = mid - left + 1, rightSize = right - mid;
    int leftArr[leftSize], rightArr[rightSize];

    for (int index = 0; index < leftSize; index++){
        leftArr[index] = arr[left + index];
    }
    for (int index = 0; index < rightSize; index++){
        rightArr[index] = arr[mid + 1 + index];
    }

    int leftPos = 0, rightPos = 0, targetIndex = left;
    while(leftPos < leftSize && rightPos < rightSize){
        if(leftArr[leftPos] <= rightArr[rightPos]){
            arr[targetIndex] = leftArr[leftPos];
            leftPos++;
        }
        else{
            arr[targetIndex] = rightArr[rightPos];
            rightPos++;
        }
        targetIndex++;
    }

    while (leftPos < leftSize) {
        arr[targetIndex] = leftArr[leftPos];
        leftPos++;
        targetIndex++;
    }

    while (rightPos < rightSize) {
        arr[targetIndex] = rightArr[rightPos];
        rightPos++;
        targetIndex++;
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
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

    mergeSort(arr, 0, totalElements-1);

    printf("\nElements after sort:\n");
    printElements(arr, totalElements);
    return 0;
}

