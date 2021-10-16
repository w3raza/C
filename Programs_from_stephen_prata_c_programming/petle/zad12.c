#include<stdio.h>

int main()
{ 
    double wynik;
    int granica;

    printf("Podaj granice:\n");
    scanf("%d", &granica);
    if(granica>0)
    {
        for(int i = 0; i < granica; i++)
        {
            wynik += 1.0/(2.0+i);
            printf("Wynik: %g\n", wynik);
        }
    }
    return 0;
}