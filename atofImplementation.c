#include <stdio.h>

int isNumber(char inputStr)
{
    char expressionValue = inputStr - '0';
    if (expressionValue <= 9 && expressionValue >= 0)
    {
        return 1;
    }
    else{
        return 0;
    }
}

double power(double base, int exponent)
{
    double result = 1.0;
    int isNegative = 0;
    if (exponent < 0)
    {
        isNegative = 1;
        exponent = -exponent;
    }
    while (exponent > 0)
    {
        result *= base;
        exponent--;
    }
    if (isNegative)
    {
        return 1.0 / result;
    }
    return result;
}

double atof(char *inputStr)
{
    double result = 0.0, fraction = 0.0, divisor = 1.0;
    int sign = 1, fractionalSide = 0;
    while (*inputStr == ' ')
    {
        inputStr++;
    }
    if (*inputStr == '-')
    {
        sign = -1;
        inputStr++;
    }
    else if (*inputStr == '+')
    {
        inputStr++;
    }
    while (isNumber(*inputStr))
    {
        result = result * 10 + (*inputStr - '0');
        inputStr++;
    }
    if (*inputStr == '.')
    {
        inputStr++;
        fractionalSide = 1;
        while (isNumber(*inputStr))
        {
            fraction = fraction * 10 + (*inputStr - '0');
            divisor *= 10;
            inputStr++;
        }
    }
    result += fraction / divisor;
    if (*inputStr == 'e' || *inputStr == 'E')
    {
        inputStr++;
        int exponentSign = 1, exponent = 0;
        if (*inputStr == '-')
        {
            exponentSign = -1;
            inputStr++;
        }
        else if (*inputStr == '+')
        {
            inputStr++;
        }
        while (isNumber(*inputStr))
        {
            exponent = exponent * 10 + (*inputStr - '0');
            inputStr++;
        }
        result *= power(10, exponentSign * exponent);
    }
    return sign * result;
}

int main()
{
    char inputStr[100];
    printf("Enter the string which you want to be coverted to float:\n");
    fgets(inputStr, 100, stdin);
    printf("Converted: %f\n", atof(inputStr));
    return 0;
}

