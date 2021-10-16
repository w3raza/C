#include <stdio.h>
#define N 40
double basic(int integer)
{
    return (double)N * integer;
}

double overtime(int integer)
{
    if (integer > N)
    {
        return (double)basic(integer) * 1.5;
    }
    else
    {
        return (double)basic(integer);
    }
}
double reward(double brutto)
{
    if (brutto <= 1200)
        return brutto * 0.85;
    else if (brutto < 1800)
        return 1200 * 0.85 + (brutto - 1200) * 0.8;
    else
        return 1200 * 0.85 + 600 * 0.8 + (brutto - 1800) * 0.75;
}

int main()
{
    int integer;
    printf("Podaj liczbę nadgodzin:");
    scanf("%d", &integer);
    double brutto = overtime(integer);
    double netto = reward(brutto);
    printf("Brutto: %g, Podatek: %g, Netto:%g\n", brutto, brutto - netto, netto);
    return 0;
}