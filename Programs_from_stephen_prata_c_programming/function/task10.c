#include <stdio.h>

void converter(unsigned long n, int convert)
{

    int r;
    r = n % convert;

    if (n >= convert)
    {
        converter(n / convert, convert);
    }
    if (r == 0)
        putchar('0');
    else if (r == 1)
        putchar('1');
    else if (r == 2)
        putchar('2');
    else if (r == 3)
        putchar('3');
    else if (r == 4)
        putchar('4');
    else if (r == 5)
        putchar('5');
    else if (r == 6)
        putchar('6');
    else if (r == 7)
        putchar('7');
    else if (r == 8)
        putchar('8');
    else if (r == 9)
        putchar('9');
    return;
}

int main(void)
{
    unsigned long number;
    int convert;

    printf("Enter an integer number (q finish program):\n");
    while (scanf("%ld", &number) == 1)
    {
        printf("Enter an integer number from 2 to 10 (q finish program):\n");
        (scanf("%d", &convert) == 1);

        if (convert >= 2 && convert <= 10)
        {
            printf("Convert number:");
            converter(number, convert);
            putchar('\n');
            printf("Enter an integer number (q finish program):\n");
        }
        else
            printf("Wrong number!\n");
    }
    printf("Finished.\n");

    return 0;
}