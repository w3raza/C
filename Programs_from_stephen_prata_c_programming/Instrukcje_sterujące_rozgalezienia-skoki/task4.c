#include <stdio.h>

int main()
{
    char ch;
    int i = 0;
    while ((ch = getchar()) != '#')
    {
        if (ch == '!')
        {
            i++;
            ch = ':';
        }
        if (ch == '.')
        {
            i++;
            ch = '!';
        }
        printf("%c", ch);
    }
    printf("Number of changes: %d\n", i);
    return 0;
}