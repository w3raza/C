#include <stdio.h>

int main(void)
{
	int ready = 0;
	float array[420] = {0};
	int counter = 0;
	char c;
	do
	{
		printf("Podaj liczbe: ");
		scanf("%f", &array[counter]);
		counter++;
		printf("Czy chcesz podac nastepne liczby? t/n ");
		scanf(" %c", &c);
		if (c == 'n')
		{
			ready = 1;
		}

	} while (ready != 1);
	float sum = 0;
	int i;
	for (i = 0; i < counter; i++)
	{
		sum += array[i];
	}
	float avg = sum / counter;
	printf("Srednia wynosi: %f", avg);
	printf("\nIlosc wprowadzonych liczb: %d", counter);
	printf("\nSuma podanych liczb: %f\n", sum);
}
