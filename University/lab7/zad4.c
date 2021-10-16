#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *((int *)b) - *((int *)a);
}

int main()
{
    srand(time(NULL));

    size_t num = 1000;
    int tab[num];
    int *base;

    int a, b;
    printf("Podaj zakres\n");
    scanf("%d %d", &a, &b);

    if (a == b)
    {
        for (base = tab; base < tab + num; base++)
        {
            *base = 0;
            printf("%d\n", *base);
        }
        exit(-1);
    }

    for (base = tab; base < tab + num; base++)
    {
        *base = rand() % (b - a) + a;
        printf("%d\n", *base);
    }

    printf("Posortowane:\n");

    qsort(tab, num, sizeof(int), &compare);

    for (base = tab; base < tab + num; base++)
    {
        printf("%d\n", *base);
    }

    return 0;
}