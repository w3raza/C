#include <stdio.h>
#include <string.h>

#define N 30
#define n 5

char *contain_chain(char *array, char *chain)
{
    int j = 0;
    int i = 0;

    for (i; i < N; i++)
    {
        while (array[i] == chain[j] && j < n && array[i] != '\0')
            j++;
    }

    if (j == strlen(chain))
        return chain;

    return NULL;
}

int main()
{
    char array[N] = {"What is up. It is fine"};
    char chain[n] = {"fion"};

    printf("%p\n", contain_chain(array, chain));

    return 0;
}