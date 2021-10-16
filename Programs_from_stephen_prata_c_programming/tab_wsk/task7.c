#include <stdio.h>
#define N 3

void copy(int source[N][N], int copy_array[N][N], int n)
{
    printf("Copy_array:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            copy_array[i][j] = source[i][j];
            printf("%d ", copy_array[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

int main()
{
    int array[N][N] = {
        4,
        12,
        7,
        89,
        1,
        78,
        0,
    };
    int copy_array[N][N];
    copy(array, copy_array, N);

    return 0;
}