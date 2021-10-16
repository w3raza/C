#include <stdio.h>

double power(double x, int y)
{
    double result;

    if (x == 0)
        return 0;
    if (y == 0)
        return 1;

    if (y > 0)
    {
        result = x;

        for (int i = 1; i < y; i++)
        {
            result *= x;
        }
    }
    else
    {
        x = (1 / x);
        y = y * (-1);
        result = x;

        for (int i = 1; i < y; i++)
        {
            result *= x;
        }
    }

    return result;
}
int main()
{
    double x;
    int y;

    printf("Enter numbers:\n");
    scanf("%lf", &x);
    scanf("%d", &y);

    printf("%g\n", power(x, y));

    return 0;
}