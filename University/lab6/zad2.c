#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void blad_alokacji()
{
    printf("Blad alokacji!");
    exit(-1);
}

float rand_float(float min, float max)
{
    return rand() / (float)RAND_MAX * (max - min) + min;
}

void wypelnij(float **tab, int s1, int s2, float min, float max)
{
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            tab[i][j] = rand_float(min, max);
        }
    }
}

void wypisz(float **tab, int s1, int s2)
{
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            printf("%g\t", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void sortuj(float *tab, int s)
{
    float tmp;
    for (int i = 0; i < s; i++)
    {
        for (int j = 1; j < s; j++)
        {
            if (tab[j] < tab[j - 1])
            {
                tmp = tab[j - 1];
                tab[j - 1] = tab[j];
                tab[j] = tmp;
            }
        }
    }
}

float sumuj(float *tab, int s)
{
    float suma = 0;
    for (int i = 0; i < s; i++)
    {
        suma += tab[i];
    }
    return suma;
}

void normalizuj(float *tab, int s)
{
    float suma = sumuj(tab, s);
    for (int i = 0; i < s; i++)
    {
        tab[i] /= suma;
    }
}

float **allocate(int s1, int s2)
{
    float **tab = malloc(s1 * sizeof(float *));
    if (!tab)
    {
        blad_alokacji();
    }

    tab[0] = malloc(s1 * s2 * sizeof(float));
    if (!tab[0])
    {
        blad_alokacji();
    }

    for (int i = 1; i < s1; i++)
    {
        tab[i] = tab[i - 1] + s2;
    }
    return tab;
}

void deallocate(float **tab)
{
    free(tab[0]);
    free(tab);
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    int s1 = atoi(argv[1]);
    int s2 = atoi(argv[2]);

    float min = atoi(argv[3]);
    float max = atoi(argv[4]);

    float **tab = allocate(s1, s2);

    wypelnij(tab, s1, s2, min, max);
    wypisz(tab, s1, s2);

    sortuj(tab[0], s1 * s2);
    wypisz(tab, s1, s2);

    normalizuj(tab[0], s1 * s2);
    wypisz(tab, s1, s2);
    printf("Suma po normalizacji: %g\n", sumuj(tab[0], s1 * s2));

    deallocate(tab);

    return 0;
}
