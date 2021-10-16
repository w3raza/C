/* ptrfn.c */
/* Tablica wskaznikow do funkcji */
#include <stdio.h>
#include <math.h>

double ff(double x)
{
	return 1 + x * x;
}

double xx(int x)
{
	return x ^ -2;
}

/*double cos(double x)
{
    return cos(x);
}

double sin(double x)
{
    return sin(x);
}*/

int main(void)
{
	double (*p[])(double) = {sin, cos, ff, xx, NULL};
	double (**q)(double) = p;

	for (int i = 2; i <= 20; i += 2)
	{
		printf("i = %d\n", i);

		while (*q)
		{
			printf("%.4f\n", (*(*q++))((double)i));
		}
		q = p;
		printf("\n");
	}
	return 0;
}