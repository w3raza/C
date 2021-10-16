#include <stdio.h>

int krytyka(void);
int main()
{
    int jednostki;
    printf("Ile funtow masla miesci sie w barylce?\n");
    scanf("%d", &jednostki);
    while (jednostki != 56)
        jednostki = krytyka();
    printf("Musiales podejrzec!\n");

    return 0;
}

int krytyka(void)
{
    int jednostki;
    printf("Nie masz szczescia, sprobuj ponownie.\n");
    scanf("%d", &jednostki);
    return jednostki;
}