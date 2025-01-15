#include <stdio.h>

void horizontal(int matrix[][100], int m, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m / 2; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][m - j - 1];
            matrix[i][m - j - 1] = temp;
        }
    }
}

void vertical(int matrix[][100], int m, int n)
{
    int temp;
    for (int i = 0; i < n/2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[m - i - 1][j];
            matrix[m - i - 1][j] = temp;
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

