#include <stdio.h>

int main(void)
{
	int i = 1, a;
	int N = 10;
	int l = 1;
	printf("podaj wartosc N \n");
	scanf("%d", &N);
	a = N;

	do
	{
		while (a > i)
		{
			printf(" ");
			a--;
		};
		a = N;

		while (l < (i * 2))
		{
			printf("*");
			l++;
		};
		l = 1;
		printf("\n");
		i++; //i=i+1;
	} while (i <= N);

	return 1;
}