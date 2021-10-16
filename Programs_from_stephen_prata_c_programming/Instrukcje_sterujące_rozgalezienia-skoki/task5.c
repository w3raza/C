#include <stdio.h>

int main()
{
    char ch;
    int i = 0;
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
        case '!':
            ch = ':';
            i++;
            break;
        case '.':
            ch = '!';
            i++;
            break;
        }
        printf("%c", ch);
    }
    printf("Number of changes: %d\n", i);
    return 0;
}