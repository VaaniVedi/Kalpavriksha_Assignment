#include <stdio.h>
#include <stdlib.h>

void freeGrid(int **grid, int row)
{
    for (int index = 0; index < row; index++)
    {
        free(grid[index]);
    }
    free(grid);
}

void markRow(int **grid, int currRow, int col)
{
    for (int indexCol = 0; indexCol < col; indexCol++)
    {
        if (grid[currRow][indexCol] != 0)
        {
            grid[currRow][indexCol] = -1;
        }
    }
}

void markCol(int **grid, int currCol, int row)
{
    for (int indexRow = 0; indexRow < row; indexRow++)
    {
        if (grid[indexRow][currCol] != 0)
        {
            grid[indexRow][currCol] = -1;
        }
    }
}

void findZeroes(int **grid, int row, int col)
{

    for (int indexRow = 0; indexRow < row; indexRow++)
    {
        for (int indexCol = 0; indexCol < col; indexCol++)
        {
            if (grid[indexRow][indexCol] == 0)
            {
                markRow(grid, indexRow, col);
                markCol(grid, indexCol, row);
            }
        }
    }

    for (int indexRow = 0; indexRow < row; indexRow++)
    {
        for (int indexCol = 0; indexCol < col; indexCol++)
        {
            if (grid[indexRow][indexCol] == -1)
            {
                grid[indexRow][indexCol] = 0;
            }
        }
    }
}

void printGrid(int **grid, int row, int col)
{
    for (int indexRow = 0; indexRow < row; indexRow++)
    {
        for (int indexCol = 0; indexCol < col; indexCol++)
        {
            printf("%d ", grid[indexRow][indexCol]);
        }
        printf("\n");
    }
}

int main()
{
    int row, col;

    printf("Enter the row of matrix:");
    scanf("%d", &row);
    printf("Enter the coloumn of matrix:");
    scanf("%d", &col);

    int **grid = malloc(row * sizeof(int *));
    for (int index = 0; index < row; index++)
    {
        grid[index] = malloc(col * sizeof(int));
    }

    for (int indexRow = 0; indexRow < row; indexRow++)
    {
        for (int indexCol = 0; indexCol < col; indexCol++)
        {
            printf("Enter character at [%d][%d]:", indexRow, indexCol);
            int value;
            do
            {
                scanf("%d", &value);
            } while (value == '\n');
            grid[indexRow][indexCol] = value;
        }
    }

    printf("\nGrid:\n");
    printGrid(grid, row, col);
    findZeroes(grid, row, col);
    printf("\nNew Grid:\n");
    printGrid(grid, row, col);
    freeGrid(grid, row);
    return 0;
}

