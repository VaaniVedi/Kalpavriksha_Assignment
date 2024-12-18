#include <stdio.h>
#include <limits.h>
int isNumber(char currChar){
    if(currChar<='9'&&currChar>='0'){
        return 1;
    }
    return 0;
    
}

int isSpace(char currChar){
    if(currChar==' '){
        return 1;
    }
    return 0;

}

int checkOperator(char currChar){
    if(currChar == '+' || currChar== '-' || currChar == '*' || currChar == '/'){
        return 1;
    }
    return 0;

}

int getNumber(char* currChar, int* index) {
    int tempNumber = 0;
    while (isNumber(currChar[*index])==1) {
        tempNumber = tempNumber * 10 + (currChar[*index] - '0');
        (*index)++;
    }
    return tempNumber;

}

int evaluateResult(int operands[],char op_sign[], int sign_p){
    int ans = operands[0];
    int index = 1; 
    for (int i = 0; i < sign_p; i++) {
        if (op_sign[i] == '+') {
            ans += operands[index];
        } else {
            ans -= operands[index];
        }
        index++;
    }
    return ans;

}

int calculate(char* inputExp) {
    int operands[10000] = {0}, invalidInputError = INT_MAX, divByZero = INT_MIN, numIndex = 0, operandInd = 0, index = 0, inputIndex=0;
    char operators[10000];

    while(inputExp[inputIndex]){
        if(isSpace(inputExp[inputIndex])==1 || isNumber(inputExp[inputIndex])==1 || checkOperator(inputExp[inputIndex])) inputIndex++;
        else return invalidInputError;
    }

    while (inputExp[index]) {
        if (isSpace(inputExp[index])==1) index++;
        else if (isNumber(inputExp[index])==1) {
            operands[numIndex++] = getNumber(inputExp, &index);
        } else { 
            if (inputExp[index] == '*' || inputExp[index] == '/') {
                char curr_operator = inputExp[index];
                index++;
                while (isSpace(inputExp[index])==1) index++;
                int operand_2 = getNumber(inputExp, &index); 
                int operand_1 = operands[--numIndex];
                if (curr_operator == '*') {
                    operands[numIndex++] = operand_1 * operand_2;
                } else {
                    if(operand_2==0){
                        return divByZero;
                    }
                    operands[numIndex++] = operand_1 / operand_2;
                }
            } else {
                operators[operandInd++] = inputExp[index++];
            }
        }
    }
    int result = evaluateResult(operands,operators,operandInd);
    return result;

}

int main() {
    char inputExp[10000];
    int index = 0;
    char inputChar;

    printf("Enter a string: ");
    inputChar=getchar();
    while(inputChar!='\n'){
        inputExp[index]=inputChar;
        index++;
        inputChar=getchar();
    }

    inputExp[index] = '\0';
    int result = calculate(inputExp);

    if(inputExp[0] == '\0'){
        printf("The input string is empty");
    }
    else if(result==INT_MAX){ 
        printf("Invalid character in the string"); 
    }

    else if(result==INT_MIN){
        printf("Error division by zero");
    }

    else {
        printf("Result: %d\n", result);
    }
    
    return 0;

}
