#include <stdio.h>

double wyraz_ciagu(int n)
{
    return 1.0 / n;
}

void wypisz_ile_wyrazow(double do_ilu)
{
    double suma = 0;
    int i = 0;
    while (suma <= do_ilu)
    {
        i++;
        suma = suma + wyraz_ciagu(i);
    }
    printf("Suma %d elementow = %2.10f\n", i, suma);
}

int main()
{
    wypisz_ile_wyrazow(10);

    return 0;
}
