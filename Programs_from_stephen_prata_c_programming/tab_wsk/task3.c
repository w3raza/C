#include <stdio.h>

int max(int tab[])
{
    int max_value = 0;

    for (int i = 0; i < sizeof(*tab); i++)
    {
        if (tab[i] > max_value)
            max_value = tab[i];
    }

    return max_value;
}

int main()
{
    int tab[6] = {4, 12, 7, 89, 1, 78};
    printf("Max: %d\n", max(tab));

    return 0;
}