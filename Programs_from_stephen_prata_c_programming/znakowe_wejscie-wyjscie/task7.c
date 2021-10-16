#include <stdio.h>
#include <ctype.h>
#define N 40

int download_int(void)
{
    int we;
    char ch;

    while (scanf("%d", &we) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a natural number.\nPliss choose ");
        printf("Total value, np.23\n");
    }

    return we;
}

double basic(int integer, int n)
{
    return (double)n * integer;
}

double overtime(int integer, int n)
{
    integer = download_int();
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
    printf("Enter the letter corresponding to the rate or option in question:\n");
    printf("a 35 zl/h \tb 37 zl/h \nc 40 zl/h \td 45 zl/h \nq exit\n");
}

char download_first(void)
{
    int ch;

    ch = getchar();
    while (getchar() != '\n')
        continue;
    if (isprint(ch))
        return ch;
}

char download(void)
{
    int ch;
    ch = download_first();

    while ((ch < 'a' || ch > 'd') && ch != 'q')
    {
        printf("Enter a, b, c, d or q\n");
        ch = download_first();
    }
    return ch;
}

int main()
{
    int integer, n, choice;
    print();
    scanf("%d", &choice);
    choice = download();

    switch (choice)
    {
    case 'a':
        n = 35;
        break;
    case 'b':
        n = 37;
        break;
    case 'c':
        n = 40;
        break;
    case 'd':
        n = 45;
        break;
    case 'q':
        break;
    default:
        printf("Program error!\n");
        break;
    }

    printf("Podaj liczbę nadgodzin:");
    scanf("%d", &integer);

    double brutto = overtime(integer, n);
    double netto = reward(brutto);

    printf("Brutto: %g, Podatek: %g, Netto:%g\n", brutto, brutto - netto, netto);
    return 0;
}