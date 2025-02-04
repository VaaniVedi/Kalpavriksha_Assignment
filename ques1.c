You are given a string S of size N that represents the prefix form of a valid mathematical 
expression. The string S contains only lowercase and uppercase alphabets as operands 
and the operators are +, -, *, /, %, and ^. Convert it to its infix form.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100
typedef struct
{
    char arr[MAX_SIZE][MAX_SIZE];
    int index;
} stack;

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

bool isOperand(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return true;
    return false;
}

void push(stack *st, char *ch)
{
    if (st->index == MAX_SIZE)
    {
        printf("Stack is full");
        return;
    }
    st->index++;
    strcpy(st->arr[st->index], ch);
}

bool pop(stack *st, char result[])
{
    if (st->index == 0)
    {
        printf("stack empty\n");
        return false;
    }

    strcpy(result, st->arr[st->index]);
    st->index--;
    return true;
}

int main()
{
    char str[MAX_SIZE];
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0';
    int len = strlen(str);
    stack st;
    st.index = 0;

    for (int index = len - 1; index >= 0; index--)
    {
        char inStack[3] = {str[index], '\0'};
        if (isOperand(str[index]) == true)
        {
            push(&st, inStack);
        }
        else if (isOperator(str[index]) == true)
        {
            char operand1[MAX_SIZE], operand2[MAX_SIZE], result[MAX_SIZE];
            if (!pop(&st, operand1) || !pop(&st, operand2))
            {
                printf("Invalid Prefix error!\n");
                return 1;
            }
            strcpy(result, "(");
            strcat(result, operand1);
            strcat(result, inStack);
            strcat(result, operand2);
            strcat(result, ")");

            push(&st, result);
        }
        else
        {
            printf("Invalid character %c!!", str[index]);
            return 0;
        }
    }
  
    char ans[MAX_SIZE];
    pop(&st, ans);
    printf("Infix: %s", ans);
    return 0;
}

