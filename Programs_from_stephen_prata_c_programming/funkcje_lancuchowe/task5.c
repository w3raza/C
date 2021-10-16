#include <stdio.h>

#define N 20

char *character(char *array)
{
    char ch;
    char *wsk;
    int i = 0;

    puts("character you are looking for:");
    ch = getchar();
    wsk = &ch;

    for (i; i < N; i++)
    {
        if (array[i] == ch)
        {
            return wsk;
        }
    }
    return NULL;
}

char *word(char *array)
{
    char *result;
    int i = 0;

    puts("Enter word:");

    result = fgets(array, N, stdin);
    if (result)
    {
        while (array[i] != '\n' && array[i] != '\0')
            i++;
        if (array[i] == '\n')
            array[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return array;
}

int main(void)
{
    char array[N];

    word(array);
    printf("Character: %s\n", character(array));

    return 0;
}