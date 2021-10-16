#include<stdio.h>
#include<string.h>

int main()
{
    char nazwa[40];
    char nazwisko[40];
    scanf("%s %s", nazwa, nazwisko);
    printf("\n");
    int litery = strlen(nazwa);
    int ilosc =strlen(nazwisko);
    printf("%s %s\n", nazwa, nazwisko);
    printf("%*.d%*d\n", litery, litery, ilosc, ilosc);
    printf("%d %*d\n", litery, litery, ilosc);
    return 0;
}