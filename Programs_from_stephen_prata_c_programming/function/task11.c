#include <stdio.h>

void Fibonacci(unsigned long number)
{
    long int fibonacci_number = 0, tmp = 0, k = 1;

    if (number > 0)
    {
        while (tmp <= number)
        {
            printf("%ld ", fibonacci_number);
            tmp = fibonacci_number;
            fibonacci_number += k;
            k = tmp;
            tmp = fibonacci_number;
        }
        printf("\n");
    }
    else
        return;
    tmp = 0;
    k = 0;
    fibonacci_number = 0;
}
int main()
{
    unsigned long number;

    printf("Enter an integer number (q finish program):\n");
    while (scanf("%ld", &number) == 1)
    {
        Fibonacci(number);
    }
    return 0;
}