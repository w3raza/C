#include <stdio.h>

int main(void)
{
	int i = 1, a;
	int N = 10;
	int l = 0;
	printf("podaj wartosc N \n");
	scanf("%d", &N);
	a = N;
	for (i = 1; i <= N; i++)
	{
		for (a = N; a > i; a--)
		{
			printf(" ");
		}

		for (l = 1; l < (i * 2); l++)
		{
			printf("*");
		}

		printf("\n");
	}
	return 1;
}