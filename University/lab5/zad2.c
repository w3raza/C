#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a, b, c, tmp;

    printf("Podaj a:\n");
    scanf("%d", &a);

    printf("Podaj b:\n");
    scanf("%d", &b);

    printf("Podaj c:\n");
    scanf("%d", &c);

    printf("1. a = %d, b = %d, c = %d\n", a, b, c);
    if (a > b)
    {
        tmp = b;
        b = a;
        a = tmp;

        printf("2. a = %d, b = %d, c = %d\n", a, b, c);
    }
    if (b > c)
    {
        tmp = c;
        c = b;
        b = tmp;
    }
    if (c < a)
    {
        tmp = c;
        c = a;
        a = tmp;
        printf("3. a = %d, b = %d, c = %d\n", a, b, c);
    }
    else
    {
        printf("4. a = %d, b = %d, c = %d\n", a, b, c);
    }

    return 0;
}