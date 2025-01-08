#include <stdio.h>
#include <string.h>

int getValidInput(const char * prompt, int min, int max) {
    int value;
    printf("%s", prompt);
    scanf("%d", & value);
    while (value < min || value > max) {
        printf("Value does not lie in the constraint range.\nPlease enter a value between %d and %d: ", min, max);
        scanf("%d", & value);
    }
    return value;
}

void inputNames(int rows, int columns, char names[rows][columns][51], char longestNames[rows * columns][51], int * maxLength, int * longestCount) {
    printf("Enter the names:\n");
    * maxLength = 0;
    * longestCount = 0;
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int colIndex = 0; colIndex < columns; colIndex++) {
            while (1) {
                printf("Name at [%d, %d]: ", rowIndex, colIndex);
                scanf("%s", names[rowIndex][colIndex]);
                int lengthOfString = strlen(names[rowIndex][colIndex]);
                if (lengthOfString <= 50) {
                    if (lengthOfString > * maxLength) {
                        * maxLength = lengthOfString;
                        * longestCount = 0;
                        strcpy(longestNames[ * longestCount], names[rowIndex][colIndex]);
                        ( * longestCount) ++;
                    } else if (lengthOfString == * maxLength) {
                        strcpy(longestNames[ * longestCount], names[rowIndex][colIndex]);
                        ( * longestCount) ++;
                    }
                    break;
                } else {
                    printf("Name is exceeding 50 characters. Please try a different name.\n");
                }
            }
        }
    }
}

void printNames(int rows, int columns, char names[rows][columns][51]) {
    printf("\nThe 2D array of names is:\n");
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int colIndex = 0; colIndex < columns; colIndex++) {
            printf("%s  ", names[rowIndex][colIndex]);
        }
        printf("\n");
    }
}

int countNamesStartingWithVowel(int rows, int columns, char names[rows][columns][51]) {
    int count = 0;
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int colIndex = 0; colIndex < columns; colIndex++) {
            char firstChar = names[rowIndex][colIndex][0];
            if (firstChar == 'A' || firstChar == 'E' || firstChar == 'I' || firstChar == 'O' || firstChar == 'U' ||
                firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u') {
                count++;
            }
        }
    }
    return count;
}

void printLongestNames(char longestNames[][51], int longestCount, int maxLength) {
    printf("\nThe longest name/names:\n");
    for (int i = 0; i < longestCount; i++) {
        printf("%s\n", longestNames[i]);
    }
}

int main() {
    int rows = getValidInput("Enter the number of rows: ", 1, 10);
    int columns = getValidInput("Enter the number of columns: ", 1, 101);

    char names[rows][columns][51];
    char longestNames[rows * columns][51];
    int maxLength, longestCount;

    inputNames(rows, columns, names, longestNames, & maxLength, & longestCount);
    printNames(rows, columns, names);

    int vowelCount = countNamesStartingWithVowel(rows, columns, names);
    printf("\nNumber of names starting with a vowel: %d\n", vowelCount);
    printLongestNames(longestNames, longestCount, maxLength);
    return 0;
}
