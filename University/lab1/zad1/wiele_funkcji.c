#include <stdio.h>
void raz_trzy(void);

int main()
{
    printf("zaczynamy:\n");
    raz_trzy();
    printf("koniec\n");
    return 0;
}

void raz_trzy(void)
{
    printf("raz\ndwa\ntrzy\n");
}