#include <stdio.h>

int main()
{
    char ch, back = 0;
    int i = 0;
    while ((ch = getchar()) != '#')
    {
        //     switch (ch)
        //     {
        //     case 'ot':
        //         i++;
        //         break;
        //     }
        if (ch == 'o')
        {
            back = ch;
        }
        if (ch == 't' && back == 'o')
        {
            i++;
        }
    }
    printf("Number of changes: %d\n", i);
    return 0;
}