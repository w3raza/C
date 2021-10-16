#include <stdio.h>
#define COLUMNS 5
#define ROWS 3

void copy(double source[][COLUMNS], double copy_array[][COLUMNS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            copy_array[i][j] = source[i][j];
        }
    }
}

void printNumbers(double array[][COLUMNS], int rows)
{
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < COLUMNS; ++c)
        {
            printf("array[%d][%d] = %g\n", r + 1, c + 1, array[r][c]);
        }
    }
}

int main()
{
    double array[ROWS][COLUMNS] = {
        4.0,
        12.2,
        7.2,
        89.6,
        1.8,
        78.3,
        0.5,
        101,
        12.3, 14.5};
    double copy_array[ROWS][COLUMNS];
    copy(array, copy_array, ROWS);
    printNumbers(array, ROWS);

    return 0;
}