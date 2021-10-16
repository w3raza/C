#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 20

void file(char array[])
{
    char ch;
    int i = 0;

    FILE *fp;
    char nazwplik[40];
    char *result;

    printf("Podaj nazwe pliku: ");
    scanf("%s", nazwplik);
    fp = fopen(nazwplik, "r");

    if (fp == NULL)
    {
        printf("Blad przy probie otwarcia pliku\n");
        exit(1);
    }

    while ((ch = getc(fp)) != EOF)
    {
        *(array + i) = ch;
        i++;
    }
    fclose(fp);
}

void print()
{
    printf("**************************************\n");
    printf("Choose one from action\n");
    printf("-p) display data\n-u) convert all letters to uppercase\t-l) convert all letters to lowercase\n-q) exit\n");
    printf("**************************************\n");
}

char download_first(void)
{
    int ch;
    ch = getchar();
    while (getchar() != '\n')
        continue;
    if (isprint(ch))
        return ch;
}

char download(void)
{
    int ch;

    ch = download_first();

    while (ch != 'p' && ch != 'u' && ch != 'l' && ch != 'q')
    {
        printf("Enter p, u, l or q\n");
        ch = download_first();
    }
    return ch;
}

void uppercase(char array[])
{
    int p = -1;

    while (array[++p] != '\0')
    {
        array[p] = toupper(array[p]);
    }
}

void lowercase(char array[])
{
    int p = -1;

    while (array[++p] != '\0')
    {
        array[p] = tolower(array[p]);
    }
}

int main(void)
{
    char array[N];
    int choice;

    file(array);
    print();
    while ((choice = download()) != 'q')
    {
        switch (choice)
        {
        case 'p':
            puts(array);
            break;
        case 'u':
            uppercase(array);
            break;
        case 'l':
            lowercase(array);
            break;
        }
    }

    return 0;
}