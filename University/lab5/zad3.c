#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *zwroc_tablice(int N)
{
    int *tab = calloc((N + 1), sizeof(int));
    for (int i = 0; i < N + 1; i++)
    {
        tab[i] = 1;
    }
    return tab;
}

int main()
{
    int N = 50;

    int *tab = zwroc_tablice(N);

    for (int i = 2; i < sqrt(N) + 1; i++)
    {
        if (tab[i] == 1)
        {
            for (int j = 2 * i; j < N; j += i)
            {
                tab[j] = 0;
            }
        }
    }
    int ilosc_liczb_pierwszych = 0;
    for (int i = 2; i < N; i++)
    {
        if (tab[i] == 1)
        {
            printf("%d jest liczba pierwsza.\n", i);
            ilosc_liczb_pierwszych++;
        }
        else
        {
            printf("%d nie jest liczba pierwsza.\n", i);
        }
    }
    printf("\nW zakresie od 2 do %d jest %d liczb pierwszych\n", N, ilosc_liczb_pierwszych);

    int *liczby_pierwsze = malloc(ilosc_liczb_pierwszych * sizeof(int));
    int j = 0;
    for (int i = 2; i < N; i++)
    {
        if (tab[i] == 1)
        {
            liczby_pierwsze[j++] = i;
        }
    }

    for (int i = 0; i < ilosc_liczb_pierwszych; i++)
    {
        printf("%d: %d\n", i + 1, liczby_pierwsze[i]);
    }

    free(tab);
    free(liczby_pierwsze);

    return 0;
}