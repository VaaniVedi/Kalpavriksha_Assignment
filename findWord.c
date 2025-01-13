#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searching(int row, int col, int currentRow, int currentCol, char **grid, char *word, int indexWord)
{
    if (indexWord == strlen(word))
        return 1;
    if (currentRow >= row || currentCol >= col || currentCol < 0 || currentRow < 0 || grid[currentRow][currentCol] != word[indexWord])
    {
        return 0;
    }

    char temp = grid[currentRow][currentCol];
    grid[currentRow][currentCol] = '0';
    int result = searching(row, col, currentRow + 1, currentCol, grid, word, indexWord + 1) ||
                 searching(row, col, currentRow, currentCol + 1, grid, word, indexWord + 1) ||
                 searching(row, col, currentRow - 1, currentCol, grid, word, indexWord + 1) ||
                 searching(row, col, currentRow, currentCol - 1, grid, word, indexWord + 1) ||
                 searching(row, col, currentRow + 1, currentCol + 1, grid, word, indexWord + 1) ||
                 searching(row, col, currentRow + 1, currentCol - 1, grid, word, indexWord + 1) ||
                 searching(row, col, currentRow - 1, currentCol - 1, grid, word, indexWord + 1) ||
                 searching(row, col, currentRow - 1, currentCol + 1, grid, word, indexWord + 1);

    grid[currentRow][currentCol] = temp;
    return result;
}

int wordFind(char **grid, char *word, int row, int col)
{
    int wordLength = strlen(word);

    if (wordLength > row * col)
    {
        return 0;
    }
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            if (grid[rowIndex][colIndex] == word[0])
            {
                if (searching(row, col, rowIndex, colIndex, grid, word, 0))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void freeGrid(char **grid, int row)
{
    for (int index = 0; index < row; index++)
    {
        free(grid[index]);
    }
    free(grid);
}

void printGrid(char **grid, int row, int col)
{
    for (int indexRow = 0; indexRow < row; indexRow++)
    {
        for (int indexCol = 0; indexCol < col; indexCol++)
        {
            printf("%c ", grid[indexRow][indexCol]);
        }
        printf("\n");
    }
}

int main()
{
    int row, col;
    char word[100];

    printf("Enter the row of matrix:");
    scanf("%d", &row);
    printf("Enter the coloumn of matrix:");
    scanf("%d", &col);
    printf("Enter the word to find in the grid:");
    scanf("%s", word);

    char **grid = malloc(row * sizeof(char *));
    for (int index = 0; index < row; index++)
    {
        grid[index] = malloc(col * sizeof(char));
    }

    for (int indexRow = 0; indexRow < row; indexRow++)
    {
        for (int indexCol = 0; indexCol < col; indexCol++)
        {
            printf("Enter character at [%d][%d]:", indexRow, indexCol);
            char value;
            do
            {
                value = getchar();
            } while (value == '\n');
            grid[indexRow][indexCol] = value;
        }
    }

    printf("\nGrid:\n");
    printGrid(grid, row, col);

    if (wordFind(grid, word, row, col))
    {
        printf("Word Found.\n");
    }
    else
        printf("Word NOT Found.\n");

    freeGrid(grid, row);
    return 0;
}

