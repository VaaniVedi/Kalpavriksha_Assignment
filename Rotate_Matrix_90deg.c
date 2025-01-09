#include <stdio.h>
#include <stdlib.h>
int **createMatrix(int size) {
	int **matrix = (int **)malloc(size * sizeof(int *));
	for(int index = 0; index < size; index++) {
		matrix[index] = (int *)malloc(size * sizeof(int *));
	}
	return matrix;
}

void inputMatrix(int **matrix, int size) {
	printf("\nEnter the elements of the %d x %d matrix:\n", size, size);
	for(int rowIndex = 0; rowIndex < size; rowIndex++) {
		for(int colIndex = 0; colIndex < size; colIndex++) {
			printf("\nEnter the [%d, %d] element: ", rowIndex, colIndex);
			scanf("%d", &matrix[rowIndex][colIndex]);
		}
	}
}

void reverse(int **matrix, int size) {
	for(int rowIndex = 0; rowIndex < size; rowIndex++) {
		for(int colIndex = 0; colIndex < size/2; colIndex++) {
			int tempValue = matrix[rowIndex][colIndex];
			matrix[rowIndex][colIndex] = matrix[rowIndex][size - 1 - colIndex];
			matrix[rowIndex][size - 1 - colIndex] = tempValue;
		}
	}
}

void rotate(int **matrix, int size) {
	for(int rowIndex = 0; rowIndex < size; rowIndex++) {
		for(int colIndex = rowIndex+1; colIndex < size; colIndex++) {
			int temp = matrix[rowIndex][colIndex];
			matrix[rowIndex][colIndex] = matrix[colIndex][rowIndex];
			matrix[colIndex][rowIndex] = temp;
		}
	}
	reverse(matrix, size);
}

void printMatrix(int **matrix, int size) {
	printf("\nThe entered matrix is:\n");
	for(int rowIndex = 0; rowIndex < size; rowIndex++) {
		for(int colIndex = 0; colIndex < size; colIndex++) {
			printf("%d\t", matrix[rowIndex][colIndex]);
		}
		printf("\n");
	}
}

void freeMatrix(int **matrix, int size) {
	for(int rowIndex = 0; rowIndex < size; rowIndex++) {
		free(matrix[rowIndex]);
	}
	free(matrix);
	printf("Memory freed successfully!");
}

int main() {
	int size;
	printf("Enter the size of the nxn matrix:\n");
	scanf("%d", &size);

	int **matrix = createMatrix(size);
	inputMatrix(matrix, size);
	printMatrix(matrix, size);

	rotate(matrix, size);
	printMatrix(matrix, size);
	freeMatrix(matrix, size);

	return 0;
}
