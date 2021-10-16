#include<stdio.h>

int main(void)
{
    double kasa = 1000000;
    const int wyplaca = 100000;
    int n=0;

    while(kasa > 0)
    {
        kasa *=1.08;
        kasa -= wyplaca;
        printf("%g\n", kasa);
        n++;
    }
    printf("Ile mineło lat: %d\n", n);
    return 0;
}