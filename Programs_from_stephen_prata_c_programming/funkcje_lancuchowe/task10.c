#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 40

void delete_space(char array[])
{
    int p = -1, q = 0;

    while (array[++p] != '\0')
        if (array[p] != ' ')
            array[q++] = array[p];
    array[q] = '\0';
}

int load(char array[])
{
    int i = 0;
    char *result;

    result = fgets(array, N, stdin);
    if (result)
    {
        while (array[i] != '\n' && array[i] != '\0')
            ++i;
        if (array[i] == '\n')
            array[i] = '\0';
    }
    else
        while (getchar() != '\n')
            continue;

    return i;
}

int contain(char container[][N], char array[])
{
    int i = 0, j = 0, max;
    char *result;

    puts("Enter words:");

    for (j; j < (max = load(array)); j++)
    {
        //delete_space(array);
        strcpy(container[j], array);
    }

    return j;
}

void print(char container[][N], int max)
{
    for (int j = 0; j < max; j++)
        puts(container[j]);
}

void delete_space(char container[][N], int max)
{
    int p, q;
    for (int i = 0; i < max; i++)
    {
        p = -1, q = 0;
        while (container[i][++p] != '\0')
            if (container[i][p] != ' ')
                container[i][q++] = container[i][p];
        container[i][q] = '\0';

        // for (int j = 0; j < strlen(container[i]); j++)
        // {
        //     //printf("%c\n", container[i][j]);
        //     if (isspace(container[i][j]))
        //         container[i][j++] = container[i][p];

        //
        // }
    }
}

int main()
{
    char container[N][N];
    char array[N];

    int max = contain(container, array);

    //print(container, max);
    delete_space(container, max);

    puts("Without space:");
    print(container, max);

    return 0;
}