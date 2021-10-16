#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

typedef struct
{
    int pozycja;
    char *produkt;
    double kwota;
} zakupy;

void wypisz_d(int n, ...)
{
    va_list ap;
    va_start(ap, n);

    printf("Podpunkt a:\n");

    while (n--)
    {
        printf("%g\t", va_arg(ap, double));
    }
    printf("\n--------------------\n");
    va_end(ap);
}

void wypisz_c(int n, ...)
{
    char *tab[n];
    int max_len = 0;
    int index;

    va_list ap;
    va_start(ap, n);

    printf("Podpunkt b:\n");

    for (int i = 0; i < n; i++)
    {
        tab[i] = va_arg(ap, char *);
        if (strlen(tab[i]) > max_len)
        {
            index = i;
            max_len = strlen(tab[i]);
        }
    }
    printf("Najdluzszy z wczytanych lancuch to: %s\n", tab[index]);
    printf("--------------------\n");
    va_end(ap);
}

void wypisz_cyklicznie(int n, ...)
{
    va_list ap;
    char *tab[n];
    va_start(ap, n);

    while (n--)
    {
        printf("%d ", va_arg(ap, int));
        printf("%c ", va_arg(ap, int));
        printf("%g ", (float)va_arg(ap, double));
        printf("\t");
    }
    printf("\n--------------------\n");
    va_end(ap);
}

void tab(int n, ...)
{
    va_list ap;
    zakupy *tab = malloc(n * sizeof(zakupy));
    va_start(ap, n);

    for (int i = 0; i < n; i++)
    {
        tab[i].pozycja = va_arg(ap, int);
        tab[i].produkt = va_arg(ap, char *);
        tab[i].kwota = va_arg(ap, double);

        printf("%d. %s:  %g zl \n", tab[i].pozycja, tab[i].produkt, tab[i].kwota);
    }
    va_end(ap);
}

int main(void)
{
    wypisz_d(4, 6.787, 6.5, 1.54, 3.875);
    wypisz_c(5, "abc", "xy", "nazwa", "zakupy", "licz");
    wypisz_cyklicznie(3, 3, '-', 2.67, 2, 'k', 3.2, 1, '!', 4.79);
    tab(3, 1, "ogorki", 2.67, 2, "pomidory", 3.2, 3, "dlugopis", 4.79);
}