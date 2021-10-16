#include <stdio.h>
#include <stdlib.h>
#define N 5

void suma1(int (*tab)[N])
{
    int suma_elementow = 0;
    int suma_pod = 0;
    int suma_nad = 0;
    int suma_na = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            suma_elementow += tab[i][j];

            if (i == j)
            {
                suma_na += tab[i][j];
            }
            if (i < j)
            {
                suma_nad += tab[i][j];
            }
            if (i > j)
            {
                suma_pod += tab[i][j];
            }
        }
    }
    printf("Suma wszystkich elementów tablicy %d:\n", suma_elementow);
    printf("Suma wszystkich elementów pod przekątną główną: %d\n", suma_pod);
    printf("Suma wszystkich elementów nad przekątną główną: %d\n", suma_nad);
    printf("Suma wszystkich elementów na przekątną główną: %d\n", suma_na);
}

void suma2(int (*tab)[N])
{
    int suma_elementow = 0;
    int suma_pod = 0;
    int suma_nad = 0;
    int suma_na = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            suma_elementow += *(*(tab + i) + j);

            if (i == j)
            {
                suma_na += *(*(tab + i) + j);
            }
            if (i < j)
            {
                suma_nad += *(*(tab + i) + j);
            }
            if (i > j)
            {
                suma_pod += *(*(tab + i) + j);
            }
        }
    }
    printf("Suma wszystkich elementów tablicy %d:\n", suma_elementow);
    printf("Suma wszystkich elementów pod przekątną główną: %d\n", suma_pod);
    printf("Suma wszystkich elementów nad przekątną główną: %d\n", suma_nad);
    printf("Suma wszystkich elementów na przekątną główną: %d\n", suma_na);
}

int main()
{
    int tab[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tab[i][j] = j;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", *(*(tab + i) + j));
        }
        printf("\n");
    }
    suma2(tab);
    suma1(tab);

    return 0;
}