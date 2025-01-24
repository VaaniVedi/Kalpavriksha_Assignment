#include <stdio.h>

int MAX_ROW = 30;
int MAX_COL = 30;
int minimumVal(int first, int second, int third, int fourth)
{
    int min = first;
    if (second < min)
        min = second;
    if (third < min)
        min = third;
    if (fourth < min)
        min = fourth;
    return min;
}

void Rmax(int matrix[][MAX_COL], int row, int col, int Rmatrix[][MAX_COL])
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        int maximum = -1;
        for (int colIndex = col - 1; colIndex >= 0; colIndex--)
        {
            if (matrix[rowIndex][colIndex] > maximum)
            {
                maximum = matrix[rowIndex][colIndex];
            }
            Rmatrix[rowIndex][colIndex] = maximum;
        }
    }
}

void Lmax(int matrix[][MAX_COL], int row, int col, int Lmatrix[][MAX_COL])
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        int maximum = -1;
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            if (matrix[rowIndex][colIndex] > maximum)
            {
                maximum = matrix[rowIndex][colIndex];
            }
            Lmatrix[rowIndex][colIndex] = maximum;
        }
    }
}

void Umax(int matrix[][MAX_COL], int row, int col, int Umatrix[][MAX_COL])
{
    for (int colIndex = 0; colIndex < col; colIndex++)
    {
        int maximum = -1;
        for (int rowIndex = 0; rowIndex < row; rowIndex++)
        {
            if (matrix[rowIndex][colIndex] > maximum)
            {
                maximum = matrix[rowIndex][colIndex];
            }
            Umatrix[rowIndex][colIndex] = maximum;
        }
    }
}

void Dmax(int matrix[][MAX_COL], int row, int col, int Dmatrix[][MAX_COL])
{
    for (int colIndex = 0; colIndex < col; colIndex++)
    {
        int maximum = -1;
        for (int rowIndex = row - 1; rowIndex >= 0; rowIndex--)
        {
            if (matrix[rowIndex][colIndex] > maximum)
            {
                maximum = matrix[rowIndex][colIndex];
            }
            Dmatrix[rowIndex][colIndex] = maximum;
        }
    }
}

void printMatrix(int row, int col, int matrix[][MAX_COL])
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            printf("%d ", matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }
}

void rainwaterTrapped(int matrix[][MAX_COL], int Rmatrix[][MAX_COL], int Lmatrix[][MAX_COL], int Umatrix[][MAX_COL], int Dmatrix[][MAX_COL], int row, int col)
{
    int amount = 0;
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            int value = minimumVal(Rmatrix[rowIndex][colIndex], Lmatrix[rowIndex][colIndex], Umatrix[rowIndex][colIndex], Dmatrix[rowIndex][colIndex]);
            int trapped = value - matrix[rowIndex][colIndex];
            if (trapped > 0)
                amount += trapped;
        }
    }
    printf("Total rainwater trapped is %d", amount);
}

int main()
{
    int row, col;
    printf("Enter rows and columns within the range of 30:\n");
    scanf("%d %d", &row, &col);
    printf("\nEnter matrix elements:\n");
    int matrix[MAX_ROW][MAX_COL];
    int Rmatrix[MAX_ROW][MAX_COL], Lmatrix[MAX_ROW][MAX_COL];
    int Umatrix[MAX_ROW][MAX_COL], Dmatrix[MAX_ROW][MAX_COL];
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        printf("Enter the elements for %d row:\n", rowIndex);
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            scanf("%d", &matrix[rowIndex][colIndex]);
        }
    }

    printf("Matrix is:\n");
    printMatrix(row, col, matrix);

    Rmax(matrix, row, col, Rmatrix);
    Lmax(matrix, row, col, Lmatrix);
    Umax(matrix, row, col, Umatrix);
    Dmax(matrix, row, col, Dmatrix);
    
    rainwaterTrapped(matrix, Rmatrix, Lmatrix, Umatrix, Dmatrix, row, col);

    return 0;
}#include <stdio.h>
#include <stdio.h>
int MAX_ROW = 30;
int MAX_COL = 30;
int minimumVal(int first, int second, int third, int fourth)
{
    int min = first;
    if (second < min)
        min = second;
    if (third < min)
        min = third;
    if (fourth < min)
        min = fourth;
    return min;
}

void Rmax(int matrix[][MAX_COL], int row, int col, int Rmatrix[][MAX_COL])
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        int maximum = -1;
        for (int colIndex = col - 1; colIndex >= 0; colIndex--)
        {
            if (matrix[rowIndex][colIndex] > maximum)
            {
                maximum = matrix[rowIndex][colIndex];
            }
            Rmatrix[rowIndex][colIndex] = maximum;
        }
    }
}

void Lmax(int matrix[][MAX_COL], int row, int col, int Lmatrix[][MAX_COL])
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        int maximum = -1;
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            if (matrix[rowIndex][colIndex] > maximum)
            {
                maximum = matrix[rowIndex][colIndex];
            }
            Lmatrix[rowIndex][colIndex] = maximum;
        }
    }
}

void Umax(int matrix[][MAX_COL], int row, int col, int Umatrix[][MAX_COL])
{
    for (int colIndex = 0; colIndex < col; colIndex++)
    {
        int maximum = -1;
        for (int rowIndex = 0; rowIndex < row; rowIndex++)
        {
            if (matrix[rowIndex][colIndex] > maximum)
            {
                maximum = matrix[rowIndex][colIndex];
            }
            Umatrix[rowIndex][colIndex] = maximum;
        }
    }
}

void Dmax(int matrix[][MAX_COL], int row, int col, int Dmatrix[][MAX_COL])
{
    for (int colIndex = 0; colIndex < col; colIndex++)
    {
        int maximum = -1;
        for (int rowIndex = row - 1; rowIndex >= 0; rowIndex--)
        {
            if (matrix[rowIndex][colIndex] > maximum)
            {
                maximum = matrix[rowIndex][colIndex];
            }
            Dmatrix[rowIndex][colIndex] = maximum;
        }
    }
}

void printMatrix(int row, int col, int matrix[][MAX_COL])
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            printf("%d ", matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }
}

void rainwaterTrapped(int matrix[][MAX_COL], int Rmatrix[][MAX_COL], int Lmatrix[][MAX_COL], int Umatrix[][MAX_COL], int Dmatrix[][MAX_COL], int row, int col)
{
    int amount = 0;
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            int value = minimumVal(Rmatrix[rowIndex][colIndex], Lmatrix[rowIndex][colIndex], Umatrix[rowIndex][colIndex], Dmatrix[rowIndex][colIndex]);
            int trapped = value - matrix[rowIndex][colIndex];
            if (trapped > 0)
                amount += trapped;
        }
    }
    printf("Total rainwater trapped is %d", amount);
}

int main()
{
    int row, col;
    printf("Enter rows and columns within the range of 30:\n");
    scanf("%d %d", &row, &col);
    printf("\nEnter matrix elements:\n");
    int matrix[MAX_ROW][MAX_COL];
    int Rmatrix[MAX_ROW][MAX_COL], Lmatrix[MAX_ROW][MAX_COL];
    int Umatrix[MAX_ROW][MAX_COL], Dmatrix[MAX_ROW][MAX_COL];
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        printf("Enter the elements for %d row:\n", rowIndex);
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            scanf("%d", &matrix[rowIndex][colIndex]);
        }
    }

    printf("Matrix is:\n");
    printMatrix(row, col, matrix);

    Rmax(matrix, row, col, Rmatrix);
    Lmax(matrix, row, col, Lmatrix);
    Umax(matrix, row, col, Umatrix);
    Dmax(matrix, row, col, Dmatrix);
    
    rainwaterTrapped(matrix, Rmatrix, Lmatrix, Umatrix, Dmatrix, row, col);

    return 0;
}

