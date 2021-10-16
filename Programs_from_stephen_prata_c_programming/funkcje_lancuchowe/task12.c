#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 40

void load(char array[])
{
    int i = 0;
    char *result;

    puts("Enter words:");

    result = fgets(array, N, stdin);
    if (result)
    {
        while (array[i] != '\0')
            ++i;
        if (array[i] == '\n')
            array[i] = '\0';
    }
    else
        while (getchar() != '\n')
            continue;
}

int words_number(char array[])
{
    int p = 0, i = 0;

    while (array[p++] != '\0')
        if (isspace(array[p]) && !isspace(array[p + 1]) && array[p + 1] != '\0')
            ++i;
    if (*array == '\n')
        return 0;
    return i + 1;
}

int uppercase(char array[])
{
    int p = -1, i = 0, j = 0;

    while (array[++p] != '\0')
        if (isupper(array[p]))
            ++i;

    return i;
}

int lowercase(char array[])
{
    int p = -1, i = 0, j = 0;

    while (array[++p] != '\0')
        if (97 < array[p] && array[p] < 123)
            ++i;

    return i;
}

int punctuation(char array[])
{
    int p = -1, i = 0, j = 0;

    while (array[++p] != '\0')
        if (ispunct(array[p]))
            ++i;

    return i;
}

int digits(char array[])
{
    int p = -1, i = 0, j = 0;

    while (array[++p] != '\0')
        if (isdigit(array[p]))
            ++i;

    return i;
}

int main()
{
    char array[N];

    load(array);

    printf("Number of words: %d\n", words_number(array));
    printf("Number of upper cases: %d\n", uppercase(array));
    printf("Number of lower cases: %d\n", lowercase(array));
    printf("Number of punctuation mark: %d\n", punctuation(array));
    printf("Number of digits: %d\n", digits(array));

    return 0;
}