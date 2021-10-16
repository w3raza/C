#include <stdio.h>
#include <string.h>
#define size 5

struct klient
{
    char imie[20];
    char nazwisko[32];
    char postcode[7];
    int wiek;
};

int compare(const void *a, const void *b)
{
    struct klient klientA = *(struct klient *)a;
    struct klient klientB = *(struct klient *)b;

    int cmp = strcmp(klientA.nazwisko, klientB.nazwisko);

    if (cmp == 0)
    {
        return strcmp(klientA.imie, klientB.imie);
    }
    return cmp;
}

int main(int argc, char const *argv[])
{
    struct klient klients[size];
    int i = 0;

    while (i < size)
    {
        struct klient klient;
        scanf("%s", klient.imie);
        scanf("%s", klient.nazwisko);
        scanf("%s", klient.postcode);
        scanf("%d", &klient.wiek);

        klients[i] = klient;
        i++;
    }

    qsort(klients, size, sizeof(klients[0]), compare);

    for (i = 0; i < size; i++)
    {
        printf("imie: %s nazwisko: %s kod: %s wiek: %d\n", klients[i].imie, klients[i].nazwisko, klients[i].postcode, klients[i].wiek);
    }

    return 0;
}