#include <stdio.h>
#include <string.h>
#include <windows.h>

int main(void)
{
	char tab[][2][10] = {"nowak", "405050404", "kowalski", "798456132", "zieba", "132456789"};
	int i, znal = 0;
	char nazw[10];

	printf("Podaj nazwisko \n");
	scanf("%s", &nazw);

	for (i = 0; i < 3; i++)
	{
		if (!strcmp(nazw, tab[i][10]))
		{
			printf("\n nr tel.: %s", tab[i][10]);
			znal = 0;
		}
		if (!znal)
		{
			printf("\n Podanej osoby nie ma w ksiazce");
		}
	}

	return 0;
}
