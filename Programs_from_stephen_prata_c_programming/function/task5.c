#include <stdio.h>

void max(double *x, double *y)
{
    if (*x > *y)
        *y = *x;
    else
        *x = *y;
}

int main()
{
    double x, y;

    printf("Enter numbers:\n");
    scanf("%lf", &x);
    scanf("%lf", &y);

    max(&x, &y);

    printf("%g, %g\n", x, y);

    return 0;
}