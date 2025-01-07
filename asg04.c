#include <stdio.h>
#include <stdlib.h>

void viewMatrix(int **matrix, int dimensions[2]) {
    for (int indexOfRow = 0; indexOfRow < dimensions[0]; indexOfRow++) {
        for (int indexOfColumn = 0; indexOfColumn < dimensions[1]; indexOfColumn++) {
            printf("%d\t", matrix[indexOfRow][indexOfColumn]);
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int rows) {
    for (int indexOfRow = 0; indexOfRow < rows; indexOfRow++) {
        free(matrix[indexOfRow]);
    }
    free(matrix);
}

int **createMatrix(int dimensions[2]) {
    int rows = dimensions[0], columns = dimensions[1];
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int indexOfRow = 0; indexOfRow < rows; indexOfRow++) {
        matrix[indexOfRow] = (int *)malloc(columns * sizeof(int));
    }
    return matrix;
}

void inputFromUser(int **matrix, int dimensions[2]) {
    int rows = dimensions[0], columns = dimensions[1];
    printf("Enter the elements of the matrix:\n");
    for (int indexOfRow = 0; indexOfRow < rows; indexOfRow++) {
        for (int indexOfColumn = 0; indexOfColumn < columns; indexOfColumn++) {
            printf("Enter element [%d, %d]: ", indexOfRow + 1, indexOfColumn + 1);
            scanf("%d", &matrix[indexOfRow][indexOfColumn]);
        }
    }
}

void matrixMultiplication(int **first, int **second, int **result, int dimensions[3]) {
    int rows1 = dimensions[0], column1 = dimensions[1], column2 = dimensions[2];
    for (int indexOfRow = 0; indexOfRow < rows1; indexOfRow++) {
        for (int indexOfColumn = 0; indexOfColumn < column2; indexOfColumn++) {
            result[indexOfRow][indexOfColumn] = 0;
            for (int additionIndex = 0; additionIndex < column1; additionIndex++) {
                result[indexOfRow][indexOfColumn] += first[indexOfRow][additionIndex] * second[additionIndex][indexOfColumn];
            }
        }
    }
}

void viewChoice(int **first, int dimensions1[2], int **second, int dimensions2[2]) {
    printf("Do you want to view the matrices? Enter 1 to view them.\n");
    int optionToView;
    scanf("%d", &optionToView);

    if (optionToView == 1) {
        printf("First Matrix:\n");
        viewMatrix(first, dimensions1);
        printf("Second Matrix:\n");
        viewMatrix(second, dimensions2);
    }
}

int main() {
    int dimensions1[2], dimensions2[2], resultDimensions[2];
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &dimensions1[0], &dimensions1[1]);
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &dimensions2[0], &dimensions2[1]);

    if (dimensions1[1] != dimensions2[0]) {
        printf("Dimensionality ERROR!\n");
        return 0;
    }

    resultDimensions[0] = dimensions1[0];
    resultDimensions[1] = dimensions2[1];

    int **first = createMatrix(dimensions1);
    int **second = createMatrix(dimensions2);
    int **result = createMatrix(resultDimensions);

    inputFromUser(first, dimensions1);
    inputFromUser(second, dimensions2);

    viewChoice(first, dimensions1, second, dimensions2);

    int multiplicationDimensions[3] = {dimensions1[0], dimensions1[1], dimensions2[1]};
    matrixMultiplication(first, second, result, multiplicationDimensions);

    printf("Result Matrix:\n");
    viewMatrix(result, resultDimensions);

    freeMatrix(first, dimensions1[0]);
    freeMatrix(second, dimensions2[0]);
    freeMatrix(result, resultDimensions[0]);

    printf("The memory has been freed successfully. Operation ended safely!\n");
    return 0;
}
