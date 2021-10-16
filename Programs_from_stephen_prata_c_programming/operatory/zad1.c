#include<stdio.h>

int main()
{
    const int stala=60;
    int czas, h, min;
    printf("Podaj czas w minutach\n");
    scanf("%d", &czas);
    while(czas>0)
    {
        h=czas/stala;
        min=czas%stala;
        printf("W godzinach: %d, w minutach: %d\n", h, min);
        czas-=czas;     
    }
    return 0;
}