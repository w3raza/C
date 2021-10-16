#include <stdio.h>

int main()
{
    char ch;
    int space = 0, n = 0, another = 0;
    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
            space++;
        else if (ch == '\n')
            n++;
        else
            another++;
    }
    printf("Ilość spacji: %d, Ilość znaków nowej lini: %d, Ilość pozostałych znaków: %d \n", space, n, another);
    return 0;
}