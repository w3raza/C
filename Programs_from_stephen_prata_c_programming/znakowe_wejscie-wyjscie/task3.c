#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;
    int small = 0, big = 0, character = 0;

    FILE *fp;
    char nazwplik[40];
    printf("Podaj nazwe pliku: ");
    scanf("%s", nazwplik);
    fp = fopen(nazwplik, "r");

    if (fp == NULL)
    {
        printf("Blad przy probie otwarcia pliku\nPodaj dane z wejscia\n");
    }

    while ((ch = getc(fp)) != EOF)
    {
        //printf("%d ", ch);
        if (97 <= ch && ch <= 122)
        {
            small++;
        }
        else if (65 <= ch && ch <= 90)
        {
            big++;
        }
        else
        {
            character++;
        }
    }
    fclose(fp);

    printf("Small letter:%d Big letter:%d Other character:%d\n", small, big, character);
    return 0;
}
