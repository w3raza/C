#include <stdio.h>

int main(void)
{
	float zm1;
	printf("Podaj liczbe \n");
	scanf("%f", &zm1);

	printf("Podales liczbe %f \n", zm1);
	if (zm1 > 10)
	{
		printf("Podales liczbe wieksza od 10 \n");
	}
	else
	{
		printf("Podales liczbe mniesza od 10 \n");
	}
}