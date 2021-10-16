#include <stdio.h>
float tablica_liczb[10];

void wyswietl_tablice(float *tablica, int ilosc)
{
	int i;
	for (i = 0; i < ilosc; i++)
	{
		printf("El %d to: %5.2f \n", i + 1, tablica[i]);
	}
};

int main(void)
{

	int e, ilosc;
	float N, suma, srednia;
	int d;
	//float suma;
	//suma=(N/10);
	for (e = 0; e < 10; e++)

	{
		printf(" podaj wartosc %d tablicy: \n ", e);
		scanf("%f", &N);

		tablica_liczb[e] = N;
	}

	printf("Podaj ilosc elementow do wyswietlania: \n");
	scanf("%d", &ilosc);
	wyswietl_tablice(tablica_liczb, ilosc);
	//printf("Srednia liczb wynosi %f \n" ,suma);

	for (d = 0; d <= ilosc; d++)
	{

		suma = suma + tablica_liczb[d];
	}

	printf("suma = %f \n", suma);
	srednia = suma / ilosc;
	printf("srednia = %f", srednia);

	return 0;
}
