#include <stdio.h>
#include <math.h>

float d;
float kwadrat(float y)
{
	float loc;
	loc = y * y;

	return (loc);
}

float delta(float a, float b, float c)
{
	return kwadrat(b) - 4 * a * c;
}

int main(void)
{

	float a, b, c;
	float x, z, v;
	printf("Podaj liczbe a \n");
	scanf("%f", &a);
	printf("Podaj liczbe b \n");
	scanf("%f", &b);
	printf("Podaj liczbe c \n");
	scanf("%f", &c);
	d = delta(a, b, c);
	printf("delta = %f \n", d);
	if (d < 0)
	{
		printf("Delta mniejsza od 0, brak miejsc zerowych \n");
	}
	else if (d == 0)
	{
		x = (-b) / (2 * a);
		printf("Delta rowna 0, x = %f \n", x);
	}
	else
	{
		z = ((-b) - sqrt(d)) / (2 * a);
		v = ((-b) + sqrt(d)) / (2 * a);
		printf("Delta wieksza od 0, z = %f, v = %f \n", z, v);
	}

	return 1;
}