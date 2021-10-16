#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b)
{
    char _a = *(char *)a;
    char _b = *(char *)b;
    if (_b == _a + 32)
        return 1;
    if (_a < 91)
        _a += 32;
    if (_b < 91)
        _b += 32;
    if (_a <= _b)
        return -1;
    else
        return 1;
}

int main()
{
    struct tablica
    {
        char lancuch[15];
    };

    struct tablica tab[100];

    const char *literki = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(time(0));

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            tab[i].lancuch[j] = literki[rand() % strlen(literki)];
            printf("%c", tab[i].lancuch[j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 100; i++)
    {
        qsort(tab[i].lancuch, 15, sizeof(char), compare);
        for (int j = 0; j < 15; j++)
        {
            printf("%c ", tab[i].lancuch[j]);
        }
        printf("\n");
    }
    return 0;
}