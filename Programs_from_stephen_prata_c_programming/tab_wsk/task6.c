#include <stdio.h>
#define N 6

void reverse(double tab[], double array[])
{
    for (int i = 0; i < N; i++)
    {
        array[N - i - 1] = tab[i];
    }
}

int main()
{
    double tab[N] = {4.0, 12.2, 7.0, 89.9, 1.2, 78.8};
    double array[6];

    reverse(tab, array);

    printf("Reverses the order of an array: ");
    for (int i = 0; i < N; i++)
    {
        printf("%g ", array[i]);
    }
    printf("\n");

    return 0;
}