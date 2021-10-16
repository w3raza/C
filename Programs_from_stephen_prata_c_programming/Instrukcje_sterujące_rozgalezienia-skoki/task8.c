#include <stdio.h>
#define N 40
double basic(int integer, int n)
{
    return (double)n * integer;
}

double overtime(int integer, int n)
{
    if (integer > N)
    {
        return (double)basic(integer, n) * 1.5;
    }
    else
    {
        return (double)basic(integer, n);
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
void print()
{
    printf("**************************************\n");
    printf("Podaj liczbę odpowiadajaca zadanej stawce wynagrodzenia lub opcji:\n");
    printf("1) 35 zl/godz. \t2) 37 zl/godz. \n3) 40 zl/godz. \t4) 45 zl/godz. \n5) wyjscie\n");
}

int main()
{
    int integer, n, choice;
    print();
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        n = 35;
        break;
    case 2:
        n = 37;
        break;
    case 3:
        n = 40;
        break;
    case 4:
        n = 45;
        break;
    case 5:
        break;
    default:
        print();
    }
    printf("Podaj liczbę nadgodzin:");
    scanf("%d", &integer);

    double brutto = overtime(integer, n);
    double netto = reward(brutto);

    printf("Brutto: %g, Podatek: %g, Netto:%g\n", brutto, brutto - netto, netto);
    return 0;
}