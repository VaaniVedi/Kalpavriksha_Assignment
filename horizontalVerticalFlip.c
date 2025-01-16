#include <stdio.h>

void horizontal(int matrix[][100], int row, int col)
{
    int temp;
    for (int indexRow = 0; indexRow < col; indexRow++)
    {
        for (int indexCol = 0; indexCol < row / 2; indexCol++)
        {
            temp = matrix[indexRow][indexCol];
            matrix[indexRow][indexCol] = matrix[indexRow][row - indexCol - 1];
            matrix[indexRow][row - indexCol - 1] = temp;
        }
    }
}

void vertical(int matrix[][100], int row, int col)
{
    int temp;
    for (int indexRow = 0; indexRow < col/2; indexRow++)
    {
        for (int indexCol = 0; indexCol < row; indexCol++)
        {
            temp = matrix[indexRow][j];
            matrix[indexRow][indexCol] = matrix[row - indexRow - 1][indexCol];
            matrix[row - indexRow - 1][indexCol] = temp;
        }
    }
}

int main()
{
    printf("Enter the rows:"); int m;
    scanf("%d", &m);
    printf("Enter the col:"); int n;
    scanf("%d", &n);
    int matrix[100][100];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    horizontal(matrix,m,n);
    vertical(matrix,m,n);
    
    printf("MATRIX AFTER FLIP H AND V\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", matrix[i][j]);
            if (j < n - 1)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}

