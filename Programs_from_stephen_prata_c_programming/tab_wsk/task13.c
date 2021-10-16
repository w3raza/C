#include <stdio.h>
#define COLUMNS 5
#define ROWS 3
void initialisation(double array[][COLUMNS], int rows)
{
    printf("Enter three sets of five double numbers:\n");
    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < COLUMNS; j++)
        {
            scanf("%lf", &array[i][j]);
        }
        if (i < rows - 1)
        {
            printf("the next one\n");
        }
    }
}
double average_set(double array[][COLUMNS], int rows)
{
    double sum = 0;

    for (int c = 0; c < COLUMNS; ++c)
    {
        sum += array[rows][c];
    }

    return sum / COLUMNS;
}

double average(double array[][COLUMNS], int rows)
{
    double sum = 0;

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < COLUMNS; ++c)
        {
            sum += array[r][c];
        }
    }

    return sum / (COLUMNS * rows);
}

double max(double array[][COLUMNS], int rows)
{
    double max_value = 0;

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < COLUMNS; ++c)
        {
            if (array[r][c] > max_value)
                max_value = array[r][c];
        }
    }

    return max_value;
}

void printNumbers(double array[][COLUMNS], int rows)
{
    printf("\nArray:\n");
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < COLUMNS; ++c)
        {
            printf("%g ", array[r][c]);
        }
        putchar('\n');
    }
    for (int r = 0; r < rows; ++r)
        printf("Average for %d sets: %g\n", r, average_set(array, r));
    printf("Average: %g\n", average(array, ROWS));
    printf("Max: %g\n", max(array, ROWS));
}

int main()
{
    double array[ROWS][COLUMNS];

    initialisation(array, ROWS);
    printNumbers(array, ROWS);

    return 0;
}