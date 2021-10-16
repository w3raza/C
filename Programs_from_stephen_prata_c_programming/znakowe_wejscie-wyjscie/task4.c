#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int sum = 0, i = 0;

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
        if (!ispunct(ch))
        {
            if (ch == 32)
            {
                i++;
            }
            else
                sum++;
        }
    }
    fclose(fp);

    printf("Sum: %d i:%d,Average number of letters in a word:%d\n", sum, i, sum / i);
    return 0;
}
