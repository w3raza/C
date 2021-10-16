#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *suma(char *liczbaA, char *liczbaB, char *wyn)
{
    int lenA = strlen(liczbaA);
    int lenB = strlen(liczbaB);
    int nadwyzka = 0;
    int x = 0;

    if (lenA > lenB)
    {
        for (int i = 0; i < lenA; i++)
        {
            if (lenB - i - 1 < 0)
            {
                x = (liczbaA[lenA - i - 1] - 48) + nadwyzka;

                if (x >= 10)
                {
                    x -= 10;
                    wyn[lenA - i - 1] = x + 48;

                    for (int i = 0; i < lenA; i++)
                    {
                        int cmp = wyn[lenA - i - 1];
                        wyn[lenA - i] = cmp;
                    }
                    wyn[lenA - i - 1] = 1 + 48;
                    wyn[lenA + 1] = '\0';
                }
                else
                {
                    wyn[lenA - i - 1] = x + 48;
                    wyn[lenA] = '\0';
                }
            }

            else
            {
                x = (liczbaA[lenA - i - 1] - 48) + (liczbaB[lenB - i - 1] - 48) + nadwyzka;

                nadwyzka = 0;
                if (x >= 10)
                {
                    x -= 10;
                    nadwyzka = 1;
                }
                wyn[lenA - i - 1] = x + 48;
                wyn[lenB] = '\0';
            }
        }
    }
    else
    {
        if (lenA < lenB)
        {
            for (int i = 0; i < lenB; i++)
            {
                if (lenA - i - 1 < 0)
                {
                    x = (liczbaB[lenB - i - 1] - 48) + nadwyzka;

                    if (x >= 10)
                    {
                        x -= 10;
                        wyn[lenB - i - 1] = x + 48;

                        for (int i = 0; i < lenB; i++)
                        {
                            int cmp = wyn[lenB - i - 1];
                            wyn[lenB - i] = cmp;
                        }
                        wyn[lenB - i - 1] = 1 + 48;
                        wyn[lenB + 1] = '\0';
                    }
                    else
                    {
                        wyn[lenB - i - 1] = x + 48;
                        wyn[lenB] = '\0';
                    }
                }
                else
                {
                    x = (liczbaA[lenA - i - 1] - 48) + (liczbaB[lenB - i - 1] - 48) + nadwyzka;

                    nadwyzka = 0;
                    if (x >= 10)
                    {
                        x -= 10;
                        nadwyzka = 1;
                    }
                    wyn[lenB - i - 1] = x + 48;
                    wyn[lenB] = '\0';
                }
            }
        }
        else
        {
            for (int i = 0; i < lenB; i++)
            {
                if (lenA - i - 1 == 0)
                {
                    x = (liczbaA[lenA - i - 1] - 48) + (liczbaB[lenB - i - 1] - 48) + nadwyzka;

                    if (x >= 10)
                    {
                        x -= 10;
                        wyn[lenB - i - 1] = x + 48;

                        for (int i = 0; i < lenB; i++)
                        {
                            int cmp = wyn[lenB - i - 1];
                            wyn[lenB - i] = cmp;
                        }
                        wyn[lenB - i - 1] = 1 + 48;
                        wyn[lenB + 1] = '\0';
                    }
                    else
                    {
                        wyn[lenB - i - 1] = x + 48;
                        wyn[lenB] = '\0';
                    }
                }
                else
                {
                    x = (liczbaA[lenA - i - 1] - 48) + (liczbaB[lenB - i - 1] - 48) + nadwyzka;

                    nadwyzka = 0;
                    if (x >= 10)
                    {
                        x -= 10;
                        nadwyzka = 1;
                    }
                    wyn[lenB - i - 1] = x + 48;
                    wyn[lenB] = '\0';
                }
            }
        }
    }

    return wyn;
}

int main()
{
    char liczbaA[201];
    char liczbaB[201];
    char wynik[202];

    printf("Podaj liczbe A\n");
    scanf("%s", liczbaA);
    printf("Podano liczbe: %s\n", liczbaA);
    printf("--------------\n");

    printf("Podaj liczbe B\n");
    scanf("%s", liczbaB);
    printf("Podano liczbe: %s\n", liczbaB);
    printf("--------------\n");

    suma(liczbaA, liczbaB, wynik);

    printf("Wynik sumy liczb: %s\n", wynik);

    return 0;
}