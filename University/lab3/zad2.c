#include <stdio.h>
#include <stdlib.h>
#define s1 4
#define s2 2

void wypisz(int (*tab)[s2])
{
    int k = 1;
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            printf("%d\t ", *(*(tab + i) + j));
            printf("adres %d to %p \n", k, *(tab + i) + j);

            printf("%d\t ", tab[i][j]);
            printf("adres %d to %p \n", k++, (tab + i) + j);

            printf("\n");
        }
        printf("\n");
    }
}

int main()
{
    int tab[s1][s2];
    int y = 2;

    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            tab[i][j] = y;
            y += 2;
        }
    }
    int(*ws_T_2D)[s2] = tab;
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            printf("%p\n", (*(ws_T_2D + i) + j));
            printf("%d\n", *(*(ws_T_2D + i) + j));
        }
    }
    printf("\n");
    printf("rozmiar wskanika %ld\n", sizeof(ws_T_2D));
    wypisz(tab);

    return 0;
}
