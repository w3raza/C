#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dane
{
    char nazwisko[20], imie[20], grupa[5];
    int nr_rekordu, nr_indeksu;
} dane;

int haslo(int proby)
{
    char *password = "abcd";
    char podanehaslo[10];
    printf("(Masz 3 proby)\n");
    printf("-------------------\n");

    do
    {
        printf("Podaj haslo:\n");
        scanf("%s", podanehaslo);

        if (strcmp(password, podanehaslo) == 0)
        {
            return 1;
            break;
        }
        proby++;
        printf("Podano bledne haslo\n");

        if (proby == 3)
        {
            printf("------------------------------\n");
            printf("Koniec prob\n");
            return 0;
            break;
        }
    } while (proby < 3);
}

void sprawdz(void *a)
{
    if (a == NULL)
    {
        puts("ERROR");
        exit(EXIT_FAILURE);
    }
}

void dodaj(FILE *file)
{
    struct dane nowe;
    printf("------------------------------\n");

    printf("Podaj dane:\nimie:\n");
    scanf("%s", &(nowe.imie));

    printf("nazwisko:\n");
    scanf("%s", &(nowe.nazwisko));

    printf("grupa(np. IS_L3):\n");
    scanf("%s", &(nowe.grupa));

    printf("nr_indeksu:\n");
    scanf("%d", &(nowe.nr_indeksu));

    printf("------------------------------\n");
    printf("Podane dane:\n%s\t %s\t %s\t %d\n", nowe.imie, nowe.nazwisko, nowe.grupa, nowe.nr_indeksu);
    printf("------------------------------\n");

    file = fopen("baza.txt", "a");
    sprawdz(file);

    fseek(file, 0L, SEEK_END);
    fprintf(file, "%s\n%s\n%s\n%d\n", nowe.imie, nowe.nazwisko, nowe.grupa, nowe.nr_indeksu);

    fclose(file);
}

void usun(FILE *file, int size)
{
    file = fopen("baza.txt", "r");
    char arr[size];
    int zmienna = 0;
    while (fgets(arr, size, file) != NULL)
        ;
}

int rozmiar(FILE *file)
{
    long size = ftell(file);
    int ilosc_rekordow = size / sizeof(dane);
    printf("Rozmiar: %ld\nIlosc rekordow: %d\n", size, ilosc_rekordow);
    return ilosc_rekordow;
}

char wypisz(FILE *file, int size)
{
    file = fopen("baza.txt", "r");
    char arr[size];

    while (fgets(arr, size, file) != NULL)
        puts(arr);

    getchar();
}

void szukaj_nazwisko(FILE *file, int size)
{
    char arr[20];
    dane szukanie;
    file = fopen("baza.txt", "r");

    printf("Podaj nazwisko studenta ktorego chcesz znalesc:\n");
    scanf("%s", arr);

    for (int i = 0; i < size; i++)
    {
        fread(&szukanie, sizeof(dane), 1, file);
        if (strcmp(arr, szukanie.nazwisko) == 0)
        {
            printf("%d: %s %s %s %d\n", i, szukanie.imie, szukanie.nazwisko, szukanie.grupa, szukanie.nr_indeksu);
        }
    }
}

void szukaj_indeks(FILE *file, int size)
{
    int a;
    dane szukanie;
    file = fopen("baza.txt", "r");

    printf("Podaj nr_indeksu studenta ktorego chcesz znalesc:\n");
    scanf("%d", &a);

    for (int i = 0; i < size; i++)
    {
        fread(&szukanie, sizeof(dane), 1, file);
        if (a == szukanie.nr_indeksu)
        {
            printf("%d: %s %s %s %d\n", i, szukanie.imie, szukanie.nazwisko, szukanie.grupa, szukanie.nr_indeksu);
        }
    }
}

int main()
{
    FILE *file;

    printf("Witaj\n");
    int n = haslo(0);

    while (n != 0)
    {
        char zgoda;
        printf("\nChcesz dopisać uzytkownika?(y/n)\n");
        scanf("%s", &zgoda);
        if (zgoda == 'y')
        {
            dodaj(file);
            n++;
        }
        printf("------------------------------\n");

        long size = ftell(file);
        int k = 0;
        file = fopen("baza.txt", "a");
        sprawdz(file);

        printf("Wpisz cyfre co chcesz zrobic\n");
        printf("1 -ile rekordow i ozmiar\n");
        printf("2 -wypisz plik\n");
        printf("3 -usun rekord\n");
        printf("4 -szukaj studenta po nazwisku\n");
        printf("5 -szukaj studenta po indeksie\n");

        scanf("%d", &k);

        if (k == 1)
        {
            rozmiar(file);
        }
        if (k == 2)
        {
            wypisz(file, size);
        }
        if (k == 3)
        {
            usun(file, size);
        }
        if (k == 4)
        {
            szukaj_nazwisko(file, size);
        }
        if (k == 5)
        {
            szukaj_indeks(file, size);
        }

        fclose(file);
    }
    return 0;
}