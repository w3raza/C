#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLUMNS 5
#define ROWS 3

void initialisation(int array[][COLUMNS], int rows)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            array[i][j] = rand() % 10;
        }
    }
}

void printNumbers(int array[][COLUMNS], int rows)
{
    printf("Array:\n");
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < COLUMNS; ++c)
        {
            printf("%d ", array[r][c]);
        }
        putchar('\n');
    }
}

void doubling(int array[][COLUMNS], int rows)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            array[i][j] = 2 * array[i][j];
        }
    }
}

int main()
{
    int array[ROWS][COLUMNS];

    initialisation(array, ROWS);
    printNumbers(array, ROWS);
    doubling(array, ROWS);
    printf("\nNew ");
    printNumbers(array, ROWS);

    return 0;
}