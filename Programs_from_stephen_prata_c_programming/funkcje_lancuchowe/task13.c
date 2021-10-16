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

void reverse(char array[])
{
    char temp[N];
    char ch;
    int p = 0, i = strlen(array) - 1, back = 0, j = 0, h;

    while (array[p++] != '\0')
    {

        if (isspace(array[p]) || array[p] == '\0')
        {
            i = strlen(array) - 1 - p;
            h = i;

            if (i != 0)
                temp[i - 1] = ' ';

            for (i, j; i < (h + p - back); i++, j++)
            {
                ch = array[j];
                temp[i] = ch;
            }
            back = p + 1;
            j++;
        }
    }
    temp[p] = '\0';
    strncpy(array, temp, p);
}

int main()
{
    char array[N];

    load(array);
    reverse(array);
    puts("\nwords in reverse order");
    puts(array);

    return 0;
}