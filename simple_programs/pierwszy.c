#include <stdio.h>

int main(void)
{
	int i = 0;
	printf("zmienna i=%d \n", i);
	do
	{
		printf("Witaj w pierwszym programie po raz: %d \n", i);
		i++; //i=i+1;
	} while (i < 3);

	return 1;
}