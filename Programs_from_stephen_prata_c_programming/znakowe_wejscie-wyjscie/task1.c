#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;
    int i = 0;

    FILE *fp;
    char nazwplik[40];
    printf("Podaj nazwe pliku: ");
    scanf("%s", nazwplik);
    fp = fopen(nazwplik, "r");
    if (fp == NULL)
    {
        printf("Blad przy probie otwarcia pliku\nPodaj dane z wejscia\n");
        ch = getchar();
        while ((ch = getchar()) != '\n')
        {
            i++;
        }
        printf("%d\n", i);
        exit(1);
    }
    while ((ch = getc(fp)) != EOF)
        i++;
    fclose(fp);

    printf("%d\n", i);
    return 0;
}