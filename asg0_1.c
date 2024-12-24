#include <stdio.h>
#include <limits.h>
int isNumber(char currentCharacter){
    if(currentCharacter<='9' && currentCharacter>='0'){
        return 1;
    }
    return 0;
}

int isSpace(char currentCharacter){
    if(currentCharacter==' '){
        return 1;
    }
    return 0;
}

int checkOperator(char currentCharacter){
    if(currentCharacter == '+' || currentCharacter== '-' || currentCharacter == '*' || currentCharacter == '/'){
        return 1;
    }
    return 0;
}

int getNumber(char* currentCharacter, int* index) {
    int tempNumber = 0;
    while (isNumber(currentCharacter[*index])==1) {
        tempNumber = tempNumber * 10 + (currentCharacter[*index] - '0');
        (*index)++;
    }
    return tempNumber;

}

int evaluateResult(int operands[], char operators[], int operandInd){
    int ans = operands[0];
    int index = 1; 
    for (int i = 0; i < operandInd; i++) {
        if (operators[i] == '+') {
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
        if (isSpace(inputExp[index])==1){
            index++;
        } 
        else if (isNumber(inputExp[index])==1) {
            operands[numIndex++] = getNumber(inputExp, &index);
        } 
        else { 
            if (inputExp[index] == '*' || inputExp[index] == '/') {
                char currOperator = inputExp[index];
                index++;
                while (isSpace(inputExp[index])==1) index++;

                int operand_2 = getNumber(inputExp, &index); 
                int operand_1 = operands[--numIndex];

                if (currOperator == '*') {
                    operands[numIndex++] = operand_1 * operand_2;
                } 
                else {
                    if(operand_2==0){
                        return divByZero;
                    }
                    operands[numIndex++] = operand_1 / operand_2;
                }
            } 
            else {
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
        if(index>10000){
            printf("The string exceeds the input range. Please enter a shortr string.");
            return 0;
        }
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
