#include <stdio.h>
#include <stdlib.h>

void viewMatrix(int **matrix, int rows, int columns){
    //Function for dispaying the matrix
    for(int indexOfRow=0; indexOfRow < rows; indexOfRow++){
        for(int indexOfColumn=0; indexOfColumn < columns; indexOfColumn++){
            printf("%d\t",*(*(matrix + indexOfRow) + indexOfColumn));
        }
        printf("\n");
    }
  
}

void freeMatrix(int **matrix, int rows){
    //Freeing memory space
    for(int index=0; index < rows; index++){
        free(matrix[index]);
    }
    free(matrix);
}

int **createMatrixStructure(int rows, int columns){
    //Function for creating a structure of 2D matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int index = 0; index < rows; index++){
        matrix[index] = (int *)malloc(columns * sizeof(int));
    }
    return matrix;
  
}

void inputFromUser(int **matrix, int rows, int columns){
    //Function for entering input in the structure of 2D matrix
    printf("Enter the elements of the matrix:\n");
    for (int indexOfRow = 0; indexOfRow < rows; indexOfRow++){
        for (int indexOfColumn = 0; indexOfColumn < columns; indexOfColumn++){
            printf("Enter element [%d,%d]: ", indexOfRow + 1, indexOfColumn + 1);
            scanf("%d", &*(*(matrix + indexOfRow) + indexOfColumn));
        }
    }
  
}

void matrixMultiplication(int **ptrToFirst, int **ptrToSecond, int **ptrToResult, int row1Matrix, int col1Matrix,  int columns){
    //Logic of Multiplication
    for(int indexOfRow=0; indexOfRow < row1Matrix ; indexOfRow++){
        for(int indexOfColumn=0; indexOfColumn < columns ; indexOfColumn++){
            *(*(ptrToResult + indexOfRow) + indexOfColumn) = 0;
            for(int additionIndex=0; additionIndex < col1Matrix; additionIndex++){
                *(*(ptrToResult + indexOfRow) + indexOfColumn) += *(*(ptrToFirst + indexOfRow) + additionIndex) * *(*(ptrToSecond + additionIndex) + indexOfColumn);
            }
        }
    }
  
}

void viewChoice(int **ptrToFirst, int row1Matrix, int col1Matrix,  int **ptrToSecond,  int row2Matrix, int col2Matrix){
    //Function providing choice to view input matrix
    printf("Do you want to view the matrix? Enter 1 to view the matrix.\n");
    int optionToView;
    scanf("%d",&optionToView);

    if(optionToView==1){
        printf("First Matrix:\n");
        viewMatrix(ptrToFirst,row1Matrix,col1Matrix);
        printf("Second Matrix:\n");
        viewMatrix(ptrToSecond,row2Matrix,col2Matrix);
    }
  
}

int main(){
    int row1Matrix, row2Matrix, col1Matrix, col2Matrix;
    printf("Enter rows and columns for the first matrix:");
    scanf("%d %d",&row1Matrix,&col1Matrix);
    printf("Enter rows and columns for the second matrix:");
    scanf("%d %d",&row2Matrix,&col2Matrix);
    
    if(row2Matrix!=col1Matrix){
        printf("Dimensionality ERROR!");
        return 0;
    }

    int **ptrToFirst = createMatrixStructure(row1Matrix,col1Matrix);
    int **ptrToSecond = createMatrixStructure(row2Matrix,col2Matrix);
    int **ptrToResult = createMatrixStructure(row1Matrix,col2Matrix);

    inputFromUser(ptrToFirst, row1Matrix, col1Matrix);
    inputFromUser(ptrToSecond, row2Matrix, col2Matrix);

    viewChoice(ptrToFirst,row1Matrix,col1Matrix,ptrToSecond,row2Matrix,col2Matrix);

    matrixMultiplication(ptrToFirst,ptrToSecond,ptrToResult,row1Matrix,col1Matrix,col2Matrix);
    printf("Result Matrix:\n");
    viewMatrix(ptrToResult,row1Matrix,col2Matrix);

    freeMatrix(ptrToFirst, row1Matrix);
    freeMatrix(ptrToSecond, row2Matrix);
    freeMatrix(ptrToResult, row1Matrix);

    printf("The memory has been freed successfully. Operation ended safely!");
    return 0;
    
}
