#include <stdio.h>
#include <stdarg.h>

struct pair
{
    double x;
    char z;
};

char max_ch(int n, ...)
{
    if (n == 0)
        return 0;

    struct pair thebiggest;
    thebiggest.x = 0;
    thebiggest.z = 'a';

    struct pair next;
    va_list ap;
    va_start(ap, n);

    for (int i = n; i >= 0; i = i - 2)
    {
        next = va_arg(ap, struct pair);

        if (next.x > thebiggest.x)
        {
            thebiggest.x = next.x;
            thebiggest.z = next.z;
        }
    }
    va_end(ap);
    return thebiggest.z;
}

int main()
{
    struct pair pair1, pair2, pair3, pair4;

    pair1.x = 11.34;
    pair1.z = 'a';
    pair2.x = 122.0;
    pair2.z = 'f';
    pair3.x = 10.12;
    pair3.z = 'x';
    pair4.x = 1.67;
    pair4.z = 'd';

    char znak = max_ch(4, pair1, pair2, pair3, pair4);
    printf("Znak o najwiekszym polu: %c\n", znak);

    return 0;
}