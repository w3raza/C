#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int licznik = 0;
    char tab[80];

    while (gets(&tab))
    {
        printf("%s\n", tab);

        if (*tab == '\0')
        {
            continue;
        }

        for (char *tmp = tab; *tmp != '\0'; tmp++)
        {

            if (*tmp == ' ')
            {
                licznik++;
            }

            if (*tmp == '-')
            {
                licznik--;
            }
        }
        licznik++;
    }
    printf("Ilosc wszystkich wyrazow: %d\n", licznik);

    return 0;
}