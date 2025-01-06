#include <stdio.h>
#include <stdlib.h>

//WAP to demonstrate matrix multiplication.
void viewMatrix(int **matrix, int rows, int columns){
    for(int indexOfRow=0; indexOfRow<rows;indexOfRow++){
        for(int indexOfColumn=0; indexOfColumn<columns;indexOfColumn++){
            printf("%d\t",*(*(matrix+indexOfRow)+indexOfColumn));
        }
        printf("\n");
    }
  
}

void freeMatrix(int **matrix, int rows){
    for(int index=0; index<rows;index++){
        free(matrix[index]);
    }
    free(matrix);
}

int **createMatrixStructure(int rows, int columns){
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int index = 0; index < rows; index++){
        matrix[index] = (int *)malloc(columns * sizeof(int));
    }
    return matrix;
  
}

void inputFromUser(int **matrix, int rows, int columns){
    printf("Enter the elements of the matrix:\n");
    for (int indexOfRow = 0; indexOfRow < rows; indexOfRow++){
        for (int indexOfColumn = 0; indexOfColumn < columns; indexOfColumn++){
            printf("Enter element [%d,%d]: ", indexOfRow + 1, indexOfColumn + 1);
            scanf("%d", &*(*(matrix + indexOfRow) + indexOfColumn));
        }
    }
  
}

void matrixMultiplication(int **ptrToFirstMatrix, int **ptrToSecondMatrix, int **ptrToResultMatrix, int rowFirstMatrix, int colFirstMatrix,  int columns){
    for(int indexOfRow=0; indexOfRow < rowFirstMatrix ; indexOfRow++){
        for(int indexOfColumn=0; indexOfColumn < columns ; indexOfColumn++){
            *(*(ptrToResultMatrix + indexOfRow) + indexOfColumn) = 0;
            for(int additionIndex=0; additionIndex < colFirstMatrix; additionIndex++){
                *(*(ptrToResultMatrix + indexOfRow) + indexOfColumn) += *(*(ptrToFirstMatrix + indexOfRow) + additionIndex) * *(*(ptrToSecondMatrix + additionIndex) + indexOfColumn);
            }
        }
    }
  
}

void viewChoice(int **ptrToFirstMatrix, int rowFirstMatrix, int colFirstMatrix,  int **ptrToSecondMatrix,  int rowSecondMatrix, int colSecondMatrix){
    printf("Do you want to view the matrix? Enter 1 to view the matrix.\n");
    int optionToView;
    scanf("%d",&optionToView);

    if(optionToView==1){
        printf("First Matrix:\n");
        viewMatrix(ptrToFirstMatrix,rowFirstMatrix,colFirstMatrix);
        printf("Second Matrix:\n");
        viewMatrix(ptrToSecondMatrix,rowSecondMatrix,colSecondMatrix);
    }
  
}

int main(){
    int rowFirstMatrix, rowSecondMatrix, colFirstMatrix, colSecondMatrix;
    printf("Enter rows and columns for the first matrix:");
    scanf("%d %d",&rowFirstMatrix,&colFirstMatrix);
    printf("Enter rows and columns for the second matrix:");
    scanf("%d %d",&rowSecondMatrix,&colSecondMatrix);
    
    if(rowSecondMatrix!=colFirstMatrix){
        printf("Dimensionality ERROR!");
        return 0;
    }

    int **ptrToFirstMatrix = createMatrixStructure(rowFirstMatrix,colFirstMatrix);
    int **ptrToSecondMatrix = createMatrixStructure(rowSecondMatrix,colSecondMatrix);
    int **ptrToResultMatrix = createMatrixStructure(rowFirstMatrix,colSecondMatrix);

    inputFromUser(ptrToFirstMatrix, rowFirstMatrix, colFirstMatrix);
    inputFromUser(ptrToSecondMatrix, rowSecondMatrix, colSecondMatrix);

    viewChoice(ptrToFirstMatrix,rowFirstMatrix,colFirstMatrix,ptrToSecondMatrix,rowSecondMatrix,colSecondMatrix);

    matrixMultiplication(ptrToFirstMatrix,ptrToSecondMatrix,ptrToResultMatrix,rowFirstMatrix,colFirstMatrix,colSecondMatrix);
    printf("Result Matrix:\n");
    viewMatrix(ptrToResultMatrix,rowFirstMatrix,colSecondMatrix);

    freeMatrix(ptrToFirstMatrix, rowFirstMatrix);
    freeMatrix(ptrToSecondMatrix, rowSecondMatrix);
    freeMatrix(ptrToResultMatrix, rowFirstMatrix);

    printf("The memory has been freed successfully. Operation ended safely!");
    return 0;
    
}
