#include<stdio.h>

int main()
{
    char nazwa[40];
    char nazwisko[40];
    scanf("%s %s", nazwa, nazwisko);
    printf("\n");
    printf("Nazwisko:%s\n Imie:%s\n", nazwisko, nazwa);
    printf("\"%20s\" \n", nazwa);
    printf("\"%s   \" \n", nazwa);
    return 0;
}