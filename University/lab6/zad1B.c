#include <stdio.h>
#include <stdlib.h>

#define N 80

int main()
{
    char tab[N];

    for (int i = 0; i < N; i++)
    {
        scanf(" %c", &tab[i]);
        printf("Argument[%d] - %c\n", i, tab[i]);
    }
    gets(tab);
    printf("Wczytany tekst: %s\n", tab);

    fgets(tab, 80, stdin);
    printf("Wczytany tekst: %s\n", tab);

    return 0;
}