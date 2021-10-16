#include <stdio.h>

char fun(char ch)
{

    if (97 <= ch && ch <= 122)
    {
        return ch - 97;
    }
    else if (65 <= ch && ch <= 90)
    {
        return ch - 65;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char ch;
    while ((ch = getchar()) != EOF)
    {
        printf("%d ", fun(ch));
    }

    return 0;
}