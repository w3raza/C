#include <stdio.h>
#include <math.h>
#define N 3

void potegowanie(float l)
{
    float po;
    po = pow(l, N);
    printf("%f\n", po);
}

int main()
{
    float l;

    printf("Podaj liczbe\n");
    scanf("%f", &l);
    potegowanie(l);

    return 0;
}