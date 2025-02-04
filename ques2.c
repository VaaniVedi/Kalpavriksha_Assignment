/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array 
such that the element has an index smaller than i
*/

#include <stdio.h>
#include <stdlib.h>
#define size 20

struct stack
{
    int arr[size];
    int index;
};

void push(struct stack *st, int data)
{
    if (st->index == size)
    {
        printf("Error: stack overflow!\n");
        return;
    }
    st->arr[st->index] = data;
    st->index++;
}

void pop(struct stack *st)
{
    if (st->index == 0)
    {
        printf("Error: stack underflow!\n");
        return;
    }
    st->index--;
    return;
}

int main()
{
    int totElements;
    printf("Enter total elements in arrway:\n");
    scanf("%d", &totElements);
    int *array = (int *)malloc(totElements * sizeof(int));
    for (int index = 0; index < totElements; index++)
    {
        scanf("%d", &array[index]);
    }
    struct stack st;
    st.index = 0;
    int *nse = (int *)malloc(totElements * sizeof(int));
    for (int index = 0; index < totElements; index++)
    {
        while (st.index > 0 && st.arr[st.index - 1] >= array[index])
        {
            pop(&st);
        }
        if (st.index == 0)
        {
            nse[index] = -1;
        }
        else
        {
            nse[index] = st.arr[st.index - 1];
        }
        push(&st, array[index]);
    }
    for (int index = 0; index < totElements; index++)
    {
        printf("%d ", nse[index]);
    }
    return 0;
}

