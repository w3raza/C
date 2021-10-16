#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

typedef float (*fun)(float *, int);

typedef struct elast_tab
{
    float *wyniki;
    int licznik;
    float srednia;
    fun srednia_fun;

} elast_tab;

float licz_srednia(float *t, int count)
{
    float suma = 0.0;
    for (int i = 0; i < count; i++)
    {
        suma += t[i];
    }
    return suma / (float)count;
}

elast_tab *factory(int len)
{
    elast_tab *new_tab = malloc(sizeof(elast_tab));
    new_tab->licznik = len;
    new_tab->wyniki = malloc(len * sizeof(float));
    new_tab->srednia_fun = licz_srednia;
    return new_tab;
}

void wypelnij(elast_tab *tab)
{
    for (int i = 0; i < tab->licznik; i++)
    {
        tab->wyniki[i] = (float)(rand() % 10);
    }
}

void zaktualizuj_srednia(elast_tab *tab)
{
    tab->srednia = tab->srednia_fun(tab->wyniki, tab->licznik);
}

void wypisz(elast_tab *tab)
{
    printf("liczba danych tablicy:\t%d\n", tab->licznik);
    printf("tablica wyniki[]:\t");
    for (int i = 0; i < tab->licznik; i++)
    {
        printf("%g ", tab->wyniki[i]);
    }
    printf("\nsredni wynik\t\t%g\n", tab->srednia);
    printf("-----------------------------------\n");
}

void zwolnij_pamiec(elast_tab *tab)
{
    free(tab->wyniki);
    free(tab);
}

int main()
{
    srand(time(NULL));
    int dlugosci_eleast[] = {3, 6, 4, 2};

    elast_tab *Tab_wsk_elast[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        Tab_wsk_elast[i] = factory(dlugosci_eleast[i]);
        wypelnij(Tab_wsk_elast[i]);
        zaktualizuj_srednia(Tab_wsk_elast[i]);
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("\nStruct %d:\n", i + 1);
        wypisz(Tab_wsk_elast[i]);
    }

    for (int i = 0; i < SIZE; i++)
    {
        zwolnij_pamiec(Tab_wsk_elast[i]);
    }

    return 0;
}