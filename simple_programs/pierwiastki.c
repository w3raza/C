#include <stdio.h>
#include <math.h>

int main(void)
{
	float a, b, c;
	float delta, x, z, v;
	printf("Podaj liczbe a \n");
	scanf("%f", &a);
	printf("Podaj liczbe b \n");
	scanf("%f", &b);
	printf("Podaj liczbe c \n");
	scanf("%f", &c);
	delta = (b * b) - 4 * a * c;
	printf("delta = %f \n", delta);
	if (delta < 0)
	{
		printf("Delta mniejsza od 0, brak miejsc zerowych \n");
	}
	else if (delta == 0)
	{
		x = (-b) / (2 * a);
		printf("Delta rowna 0, x = %f \n", x);
	}
	else
	{
		z = ((-b) - sqrt(delta)) / (2 * a);
		v = ((-b) + sqrt(delta)) / (2 * a);
		printf("Delta wieksza od 0, z = %f, v = %f \n", z, v);
	}

	return 1;
}