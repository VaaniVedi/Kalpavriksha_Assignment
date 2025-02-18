/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the 
input string is valid.
An input string is valid if:
->Open brackets must be closed by the same type of brackets.
->Open brackets must be closed in the correct order.
->Every close bracket has a corresponding open bracket of the same type.
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10
#define STRING_SIZE 20

typedef struct
{
    char arr[MAX_SIZE];
    int top;
} stack;

void push(stack *st, char data)
{
    if (st->top == MAX_SIZE - 1)
    {
        printf("overflow!!");
        return;
    }
    st->top++;
    st->arr[st->top] = data;
}

char pop(stack *st)
{
    if (st->top == -1)
    {
        return '0';
    }
    return st->arr[st->top--];
}

int pair(char first, char second)
{
    if ((first == '(' && second == ')') || (first == '{' && second == '}') || (first == '[' && second == ']'))
    {
        return 1;
    }
    return 0;
}

int main()
{

    stack st;
    st.top = 0;
    char str[STRING_SIZE];
    printf("String:\n");
    fgets(str, STRING_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0';
    int isValid = 1;
    int len = strlen(str);
    for (int index = 0; index < len; index++)
    {
        char ch = str[index];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(&st, ch);
        }
        else
        {
            if (st.top == -1)
            {
                isValid = 0;
            }
            char topElement = pop(&st);
            if (pair(topElement, ch) == 0)
            {
                isValid = 0;
            }
        }
    }
    if (st.top != 0)
        isValid = 0;

    if (isValid == 0)
    {
        printf("false");
    }
    else
        printf("true");
    return 0;
}

