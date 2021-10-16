#include <stdio.h>
#include <stdlib.h>
#define N 4

void wypisz(float (*Tab_2D)[N], int s)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%g\t", *(*(Tab_2D + i) + j));
        }
        printf("\n");
    }
}

int main()
{

    int s = 3;

    float tablica_1[N];
    float tablica_2[N];

    float Tab_2D[s][N];

    for (int i = 0; i < N; i++)
    {
        tablica_1[i] = 1.2;
        tablica_2[i] = 2.5;
    }

    for (int j = 0; j < N; j++)
    {
        Tab_2D[0][j] = tablica_1[j];
        Tab_2D[1][j] = tablica_2[j];
        Tab_2D[2][j] = tablica_1[j] + tablica_2[j];
    }

    wypisz(Tab_2D, s);

    return 0;
}