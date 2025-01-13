#include <stdio.h>
#include <stdlib.h>

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

void freeGrid(int **grid, int row)
{
    for (int index = 0; index < row; index++)
    {
        free(grid[index]);
    }
    free(grid);
}

int checkElements(int **grid, int mid, int row, int col)
{
    int rowIndex = row - 1, colIndex = 0, ans = 0;
    while (rowIndex >= 0 && colIndex < col)
    {
        if (grid[rowIndex][colIndex] > mid)
        {
            rowIndex--;
        }
        else
        {
            ans += rowIndex + 1;
            colIndex++;
        }
    }
    return ans;
}

int kthSmallest(int **grid, int k, int row, int col)
{
    int smallestElement = grid[0][0];
    int largestElement = grid[row - 1][col - 1];
    while (smallestElement < largestElement)
    {
        int mid = (smallestElement + largestElement) / 2;
        int count = checkElements(grid, mid, row, col);
        if (count < k)
        {
            smallestElement = mid + 1;
        }
        else
        {
            largestElement = mid;
        }
    }
    return smallestElement;
}

int main()
{
    int row, col, k;
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
    printf("Enter the value of k\n");
    scanf("%d", &k);
    printf("The value of k is %d\n", k);
    printf("The kth smallest element is %d\n", kthSmallest(grid, k, row, col));

    freeGrid(grid, row);
    return 0;
}

