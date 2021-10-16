#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

typedef struct klient
{
    char imie[20];
    char nazwisko[32];
    char kod[7];
    int wiek;
} klient;

int compare(const void *left, const void *right)
{
    klient a = *(klient *)left;
    klient b = *(klient *)right;
    if (!strcmp(a.nazwisko, b.nazwisko))
    {
        return strcmp(a.imie, b.imie);
    }
    else
    {
        return strcmp(a.nazwisko, b.nazwisko);
    }
}

int main(int argc, char const *argv[])
{

    klient *klienci = (klient *)malloc(SIZE * sizeof(klient));
    for (klient *tmp = klienci; tmp < klienci + SIZE; tmp++)
    {
        scanf("%s", tmp->imie);
        scanf("%s", tmp->nazwisko);
        scanf("%s", tmp->kod);
        scanf("%d", &tmp->wiek);
    }

    for (klient *tmp = klienci; tmp < klienci + SIZE; tmp++)
    {
        printf("%s %s o wieku %d - kod: %s\n", tmp->imie, tmp->nazwisko, tmp->wiek, tmp->kod);
    }

    printf("\n\n");
    qsort(klienci, SIZE, sizeof(klient), compare);

    for (klient *tmp = klienci; tmp < klienci + SIZE; tmp++)
    {
        printf("%s %s o wieku %d - kod: %s\n", tmp->imie, tmp->nazwisko, tmp->wiek, tmp->kod);
    }
    free(klienci);

    return 0;
}