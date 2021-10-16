#include <stdio.h>
#include <stdlib.h> //biblioteki kt�re trzeba dolaczyc aby dzialala
#include <time.h>	// funkcja random() i time()
int main(void)
{
	int liczba_wylosowana;
	int i = 0;
	int N;
	srand(time(NULL));				 // inicjacja systemu losuj�cego
	liczba_wylosowana = random(100); // losowanie liczby z zakresu 0 - 100
	printf("Podaj liczbe \n");
	scanf("%d", &N);
	do
	{
		if (N < liczba_wylosowana)
		{
			printf("Liczba ktora podales jest za mala \n");
			i++;
			scanf("%d \n", &N);
		}
		if (N > liczba_wylosowana)
		{
			printf("Liczba ktora podales jest za duza \n");
			i++;
			scanf("%d \n", &N);
		}
	} while ((N == liczba_wylosowana) && (i <= 10));
	printf("Brawo, oto ukryta liczba", liczba_wylosowana);
	return 1;
	if (i > 10)
	{
		printf("GAME OVER");
	}

	return 1;
}