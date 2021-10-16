/* ptrfn.c */
/* Tablica wskaznikow do funkcji */
#include <stdio.h>
#include <math.h>

double ff(double x)
{
	return 1 + x * x;
}

int main(void)
{
	double (*p[])(double) = {sin, cos, ff, NULL};
	double (**q)(double) = p;
	while (*q)
		printf("%.4f\n", (*(*q++))(1.0));
	return 0;
}
