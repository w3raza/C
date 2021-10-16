#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int iteracyjnie(int liczba)
{
    int silnia = 1;
    int i = 1;
    while (i <= liczba)
    {
        silnia *= i;
        i++;
    }
    return silnia;
}

int rekurencyjnie(int liczba)
{
    static int wynik = 1;
    printf("Wartosc k=%d, adres k=%p\n", liczba, &liczba);
    if (liczba == 1 || liczba == 0)
    {
        return 1;
    }
    wynik = liczba * rekurencyjnie(liczba - 1);
    printf("Wartosc k=%d, adres k=%p", liczba, &liczba);
    printf(" wartosc wyn=%d, adres wyn=%p\n", wynik, &wynik);
    return wynik;
}

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        printf("Prosze podac liczbe i sposob obliczen(rekurencja/iteracja)\n");
        return 0;
    }

    int (*functionPtr)(int);
    int liczba = atoi(argv[1]);

    if (strcmp(argv[2], "rekurencja") == 0)
    {
        functionPtr = &rekurencyjnie;
    }

    else
    {
        functionPtr = &iteracyjnie;
    }

    printf("Wynik: %d \n", functionPtr(liczba));
    return 0;
}