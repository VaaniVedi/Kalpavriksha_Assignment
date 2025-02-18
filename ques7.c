// Problem Statement:-Reverse a string using stack

#include <stdio.h>
#include <string.h>
#define size 100

typedef struct
{
    char stack[size];
    int top;
} stack;

void push(stack *st, char data)
{
    st->top++;
    st->stack[st->top] = data;
}

char pop(stack *st)
{
    return st->stack[st->top--];
}

void reverse(stack *st, char str[])
{
    int index = 0;
    int length = strlen(str);
    char ans[length];
    while (str[index] != '\0')
    {
        push(st, str[index]);
        index++;
    }
    index = 0;
    while (st->top != 0)
    {
        int value = pop(st);
        ans[index++] = value;
    }
    ans[index] = '\0';
    printf("Reverse: %s ", ans);
}

int main()
{
    stack st;
    st.top = 0;
    char str[100];
    printf("Enter String\n");
    scanf("%s", str);
    reverse(&st, str);
    return 0;
}

