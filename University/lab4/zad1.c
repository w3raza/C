#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void swap(float *n, float *m)
{
    float tmp = *n;
    *n = *m;
    *m = tmp;
}

void bubble_sort(float *tab1, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (tab1[j] > tab1[j + 1])
            {
                swap(tab1 + j, tab1 + j + 1);
            }
        }
    }
}

void print(float *tab1, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%g ", tab1[i]);
    }
    printf("\n");
}

void maksimum(float *tab1)
{
    float max = 0;
    float maks = 0;
    float tab2[SIZE];
    float tab3[SIZE];

    for (int i = 0; i <= SIZE - 1; i++)
    {
        max = tab1[i];

        if (max > 0)
        {
            tab2[i] = tab1[i];
        }
        else
        {
            tab2[i] = 0;
        }

        if (max < 0)
        {
            tab3[i] = tab1[i];
        }
        else
        {
            tab3[i] = 0;
        }

        maks = tab2[i] + maks;
        max = tab3[i];
    }

    if (maks > max)
    {
        printf("Maksymalna suma to: %f\n", maks);
    }
    if (maks == 0)
    {
        printf("Maksymalna suma to: %f\n", max);
    }
}

int main()
{
    float a = -10;
    float b = 100;
    float tab[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        printf("Podaj liczbe:");
        scanf("%f", &tab[i]);
        while (tab[i] < a || tab[i] > b)
        {
            if (tab[i] < a)
            {
                printf("Liczba ta jest za mała, najmniejsza to %g\nPodaj inna liczbe:", a);
                scanf("%f", &tab[i]);
            }

            if (tab[i] > b)
            {
                printf("Liczba ta jest za duża, najwieksza to %g\nPodaj inna liczbe:", b);
                scanf("%f", &tab[i]);
            }
        }
    }
    print(tab, SIZE);
    bubble_sort(tab, SIZE);
    print(tab, SIZE);
    maksimum(tab);

    return 0;
}