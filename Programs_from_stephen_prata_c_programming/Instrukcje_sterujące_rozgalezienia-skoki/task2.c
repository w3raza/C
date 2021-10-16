#include <stdio.h>

int main()
{
    char ch;
    int i = 1;
    while ((ch = getchar()) != '#')
    {
        printf("Znak: %c, Kod: %d, ", ch, (int)ch);
        i++;
        if (i % 9 == 0)
        {
            printf("\n");
            i = 1;
        }
    }
    return 0;
}