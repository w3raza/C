#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int _a = *(int *)a;
    int _b = *(int *)b;
    if (_b == _a)
        return 1;
    if (_a <= _b)
        return -1;
    else
        return 1;
}

int compareints(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int i_rand(int min, int max)
{
    return (rand() % max) - 10;
}

void wypelnij(int size, int tab[size])
{
    for (int i = 0; i < size; i++)
    {
        tab[i] = i_rand(0, 21);
    }
}

void wypisz(int size, int tab[size])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", tab[i]);
    }
    printf("\n");
}

int main()
{
    int tab[1000];
    wypelnij(1000, tab);
    wypisz(1000, tab);

    printf("\n");
    printf("Posortowane:\n");
    for (int i = 0; i < 1000; i++)
    {
        qsort(tab, 1000, sizeof(int), compare);
        printf("%d\t", tab[i]);
    }
    printf("\n");

    int *found;
    int i;
    int ile = 0;
    printf("Podaj liczbe od -10 do 10\n");
    scanf("%d", &i);

    found = bsearch(&i, tab, 1000, sizeof(tab[0]), compareints);

    if (found)
    {
        printf("\nfound: %d\n", *found);
    }
    else
    {
        printf("Not found\n");
    }

    return 0;
}