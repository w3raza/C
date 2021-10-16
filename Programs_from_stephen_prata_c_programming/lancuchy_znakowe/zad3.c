#include<stdio.h>

int main()
{
    float liczba;
    scanf("%f", &liczba);
    printf("\n");
    printf("Wpisano:%+g lub %1.3E\n ", liczba, liczba);
    return 0;
}