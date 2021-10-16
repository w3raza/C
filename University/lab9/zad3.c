#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define size 100

union Value
{
    int b;
    double c;
};

typedef struct liczba
{
    char zmZnakowa;
    union Value wart;
} liczba;

double d_rand(double min, double max)
{
    double r = (double)rand() / RAND_MAX;
    return r * (max - min) + min;
}

int i_rand(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void wypisz(struct liczba l)
{
    if (l.zmZnakowa == 'i')
    {
        printf("Typ: int\t Wartosc: %d\n", l.wart.b);
    }
    else
    {
        printf("Typ: double\t Wartosc: %f\n", l.wart.c);
    }
}

int compare_int(const void *left, const void *right)
{
    liczba a = *(liczba *)left;
    liczba b = *(liczba *)right;
    return (a.wart.b > b.wart.b);
}

int compare_double(const void *left, const void *right)
{
    liczba a = *(liczba *)left;
    liczba b = *(liczba *)right;
    return (a.wart.c > b.wart.c);
}

int compare_types(const void *left, const void *right)
{
    liczba a = *(liczba *)left;
    liczba b = *(liczba *)right;
    if (a.zmZnakowa == b.zmZnakowa)
    {
        return 0;
    }
    else if (a.zmZnakowa == 'i')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void srednia(liczba *tab, liczba *wsk)
{
    double suma = 0.0;
    for (wsk = tab; wsk < tab + size; wsk++)
    {
        suma += (*wsk).zmZnakowa == 'i' ? (double)(*wsk).wart.b : (*wsk).wart.c;
    }
    printf("Średnia: %g\n", suma / size);
}

void sortuj(liczba *tab)
{
    qsort(tab, size, sizeof(*tab), compare_types);
    int i_gr;
    for (int i = 0; i < size; i++)
    {
        if (tab[i].zmZnakowa == 'd')
        {
            i_gr = i;
            break;
        }
    }

    qsort(tab, i_gr, sizeof(*tab), compare_int);
    qsort(tab + i_gr, size - i_gr, sizeof(*tab), compare_double);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int max1 = 5;
    int min1 = -5;
    double max2 = 5.0;
    double min2 = -5.0;

    liczba *tab;
    liczba *wsk;

    tab = (liczba *)malloc(size * sizeof(liczba));

    for (wsk = tab; wsk < tab + size; wsk++)
    {
        if (rand() % 2 == 0)
        {
            (*wsk).zmZnakowa = 'i';
            (*wsk).wart.b = i_rand(min1, max1);
        }
        else
        {
            (*wsk).zmZnakowa = 'd';
            (*wsk).wart.c = d_rand(min2, max2);
        }
    }

    for (wsk = tab; wsk < tab + size; wsk++)
    {
        wypisz(*wsk);
    }
    printf("---------\n");

    sortuj(tab);

    for (wsk = tab; wsk < tab + size; wsk++)
    {
        wypisz(*wsk);
    }

    printf("---------\n");
    srednia(tab, wsk);
    free(tab);

    return 0;
}