#include <stdio.h>
#include <stdlib.h>

#define ORDERIAL_NUMBER(NUMBER) (((NUMBER) % 10) == 1 ? "st" : ((NUMBER) % 10) == 2 ? "nd" \
                                                           : ((NUMBER) % 10) == 3   ? "rd" \
                                                                                    : "th")

#define MAX_LEN 100

void matrix_print(char matrix[MAX_LEN][MAX_LEN], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j])
            {
                printf("%c ", matrix[i][j]);
            }
            else
            {

                printf("√ ");
            }

        }
        printf("\n");
    }
}

void star_generator(char matrix[MAX_LEN][MAX_LEN], int *rows, int *cols)
{
    int m = 0;
    int n = 0;
    do
    {
        printf("Enter matrix shape M x N: ");
        scanf("%d %d", &m, &n);
        if (MAX_LEN < m || MAX_LEN < n)
        {
            printf("Invalid Input\n");
        }
        
    } while (MAX_LEN < m || MAX_LEN < n);
    
    int star_m = 0;
    int star_n = 0;
    do {
        printf("Enter star position (m, n): ");
        scanf("%d %d", &star_m, &star_n);
        if (m < star_m || n < star_n)
        {
            printf("Invalid Input\n");
        }
    } while (m < star_m || n < star_n);
    star_m -= 1;
    star_n -= 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < star_m && j < star_n)
            {
                matrix[i][j] = '\\';
            }
            else if (i > star_m && j < star_n)
            {
                matrix[i][j] = '/';
            }
            else if (i < star_m && j > star_n)
            {
                matrix[i][j] = 'D';
            }
            else if (i > star_m && j > star_n)
            {
                matrix[i][j] = 'C';
            }
            else if (i == star_m && j < star_n)
            {
                matrix[i][j] = '>';
            }
            else if (i == star_m && j > star_n)
            {
                matrix[i][j] = '<';
            }
            else if (i < star_m && j == star_n)
            {
                matrix[i][j] = '\0';
            }
            else if (i > star_m && j == star_n)
            {
                matrix[i][j] = '^';
            }
            else
            {
                matrix[i][j] = '*';
            }
        }
    }
    *rows = m;
    *cols = n;
}

void star_find(char matrix[MAX_LEN][MAX_LEN], int rows, int cols, int *find_row, int *find_col)
{
    int row_low = 0;
    int row_high = rows - 1;
    int col_low = 0;
    int row_mid = (row_low + row_high) / 2;
    int col_high = cols - 1;
    int col_mid = (col_low + col_high) / 2;
    while (matrix[row_mid][col_mid] != '*')
    {
        row_mid = (row_low + row_high) / 2;
        col_mid = (col_low + col_high) / 2;
        if (matrix[row_mid][col_mid] == '\\')
        {
            row_low = row_mid + 1;
            col_low = col_mid + 1;
        }
        else if (matrix[row_mid][col_mid] == '/')
        {
            row_high = row_mid - 1;
            col_low = col_mid + 1;
        }
        else if (matrix[row_mid][col_mid] == 'D')
        {
            row_low = row_mid + 1;
            col_high = col_mid - 1;
        }
        else if (matrix[row_mid][col_mid] == 'C')
        {
            row_high = row_mid - 1;
            col_high = col_mid - 1;
        }
        else if (matrix[row_mid][col_mid] == '>')
        {
            col_low = col_mid + 1;
        }
        else if (matrix[row_mid][col_mid] == '<')
        {
            col_high = col_mid - 1;
        }
        else if (matrix[row_mid][col_mid] == '^')
        {
            row_high = row_mid - 1;
        }
        else
        {
            row_low = row_mid + 1;
        }
    }
    *find_col = col_mid + 1;
    *find_row = row_mid + 1;
}

int main()
{
    char star_matrix[MAX_LEN][MAX_LEN];
    int star_rows = 0;
    int star_cols = 0;
    star_generator(star_matrix, &star_rows, &star_cols);
    matrix_print(star_matrix, star_rows, star_cols);
    int star_pos_X = 0;
    int star_pos_Y = 0;
    star_find(star_matrix, star_rows, star_cols, &star_pos_X, &star_pos_Y);
    printf("Star is in the %d%s row at the %d%s column\n", star_pos_X, ORDERIAL_NUMBER(star_pos_X), star_pos_Y, ORDERIAL_NUMBER(star_pos_Y));
    return 0;
}