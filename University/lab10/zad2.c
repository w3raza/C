#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

struct zespolona
{
    float re;
    float im;
};

struct zesp_modul
{
    struct zespolona z;
    float modul;
    void (*func)(struct zespolona);
};

void wypisz(struct zespolona z)
{
    printf("%g+%g*i", z.re, z.im);
}

void wypelnij(struct zesp_modul *z)
{
    float wynik;
    wynik = sqrt(z->z.re * z->z.re + z->z.im * z->z.im);
    z->modul = wynik;
}

int compare(const void *a, const void *b)
{
    return ((struct zesp_modul *)a)->modul - ((struct zesp_modul *)b)->modul;
}

int main()
{
    int rozmiar;
    printf("Podaj rozmiar tablicy: \n");
    scanf("%d", &rozmiar);

    struct zesp_modul *tab = malloc(sizeof(struct zesp_modul) * rozmiar);

    srand(time(NULL));

    void (*wsk)(struct zespolona);
    wsk = &wypisz;

    for (int i = 0; i < rozmiar; i++)
    {
        tab[i].z.re = (double)rand() * 100 / RAND_MAX;
        tab[i].z.im = (double)rand() * 100 / RAND_MAX;
        wypelnij(&tab[i]);
        printf("| ");
        (*wsk)(tab[i].z);
        printf(" | = ");
        printf("%f \n", tab[i].modul);
    }
    qsort(tab, rozmiar, sizeof(struct zesp_modul), compare);
    printf("\nPosortowana:\n");

    FILE *zapisz = fopen("zad2.bin", "wb");

    for (int i = 0; i < rozmiar; i++)
    {
        printf("| ");
        (*wsk)(tab[i].z);
        printf(" | =");
        printf("%f \n", tab[i].modul);
    }

    fwrite(tab, sizeof(*tab), rozmiar, zapisz);
    fclose(zapisz);
    free(tab);
    return 0;
}