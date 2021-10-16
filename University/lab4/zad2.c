#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 8

int i_rand(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void wypisz(int dwa_tab_a[N][N], int dwa_tab_b[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dwa_tab_a[i][j] = i_rand(0, 10);
            dwa_tab_b[i][j] = i_rand(0, 10);
        }
    }

    printf("Tablica dwa_tab_a:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", dwa_tab_a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Tablica dwa_tab_b:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", dwa_tab_b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void mnozenie(int dwa_tab_a[N][N], int dwa_tab_b[N][N])
{
    wypisz(dwa_tab_a, dwa_tab_b);
    int tab_wynik[N][N];
    /*tab_wynik = malloc(N * sizeof(int *));
    for(int i=0;i<N;i++)
    {
        tab_wynik[i] = malloc(N * sizeof(int *));
    }*/
    int wynik;
    int j = 0;
    printf("Wynik mnożenia dwoch tablic:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                wynik += dwa_tab_a[i][k] * dwa_tab_b[k][j];
            }
            tab_wynik[i][j] = wynik;
            wynik = 0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", tab_wynik[i][j]);
        }
        printf("\n");
    }
    //free(tab_wynik);
}

int main()
{
    int dwa_tab_a[N][N];
    int dwa_tab_b[N][N];

    mnozenie(dwa_tab_a, dwa_tab_b);

    return 0;
}