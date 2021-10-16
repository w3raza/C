#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define S1 4
#define S2 6
#define S3 3
#define S4 2
#define S5 4

#define S_TAB 5

double d_rand(double min, double max)
{
    double r = (double)rand() / RAND_MAX;
    return r * (max - min) + min;
}

void wypelnij(int size, double tab[size])
{
    for (int i = 0; i < size; i++)
    {
        tab[i] = d_rand(0, 10);
    }
}

void wypisz(int size, double tab[size])
{
    for (int i = 0; i < size; i++)
    {
        printf("%g\t", tab[i]);
    }
    printf("\n");
}

double suma(double *tab[], int numer, int size)
{

    double suma = 0;
    for (int i = 0; i < size; i++)
    {
        suma += tab[numer][i];
    }
    return suma;
}

int main(void)
{

    double T_1[S1], T_2[S2], T_3[S3], T_4[S4], T_5[S5];

    wypelnij(S1, T_1);
    wypelnij(S2, T_2);
    wypelnij(S3, T_3);
    wypelnij(S4, T_4);
    wypelnij(S5, T_5);

    wypisz(S1, T_1);
    wypisz(S2, T_2);
    wypisz(S3, T_3);
    wypisz(S4, T_4);
    wypisz(S5, T_5);

    double *tab[S_TAB];

    tab[0] = T_1;
    tab[1] = T_2;
    tab[2] = T_3;
    tab[3] = T_4;
    tab[4] = T_5;

    printf("suma dla %d elementu: %g\n", 1, suma(tab, 1, S1));
    printf("suma dla %d elementu: %g\n", 2, suma(tab, 2, S2));
    printf("suma dla %d elementu: %g\n", 3, suma(tab, 3, S3));
    printf("suma dla %d elementu: %g\n", 4, suma(tab, 4, S4));
    printf("suma dla %d elementu: %g\n", 5, suma(tab, 5, S5));

    printf("** %ld **\n", sizeof(tab) / sizeof(double *));

    return 0;
}