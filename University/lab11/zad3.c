#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct zxy
{
    char znak;
    struct zxy *wsk;
} a, b, c;

struct zxy *wsk_file(FILE *f2)
{
    fseek(f2, 0, SEEK_END);
    long s = ftell(f2);
    fseek(f2, 0, SEEK_SET);
    struct zxy *tab;
    tab = malloc(s);
    sprawdz(tab);
    fread(tab, sizeof(struct zxy), s / sizeof(struct zxy), f2);

    return tab;
}

int i_rand(int min, int max)
{
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}

void sprawdz(void *a)
{
    if (a == NULL)
    {
        puts("ERROR");
        exit(EXIT_FAILURE);
    }
}

int main()
{
    a.wsk = &b;
    b.wsk = &c;
    c.wsk = &a;

    a.znak = 'a';
    a.wsk->znak = 'b';
    a.wsk->wsk->znak = 'c';

    printf("%c %c %c \n", b.wsk->wsk->znak, b.znak, b.wsk->znak);

    c.znak = toupper(c.znak);
    c.wsk->znak = toupper(c.wsk->znak);
    c.wsk->wsk->znak = toupper(c.wsk->wsk->znak);
    printf("%c %c %c \n", c.wsk->znak, c.wsk->wsk->znak, c.znak);

    FILE *f1 = fopen("dane.txt", "w");
    sprawdz(f1);
    FILE *f2 = fopen("dane.bin", "wb");
    sprawdz(f2);

    int n = i_rand(0, 5);
    printf("%d\n", n);

    for (int i = 0; i < n; i++)
    {
        fwrite(&a, sizeof(struct zxy), 1, f1);
        fwrite(&b, sizeof(struct zxy), 1, f1);
        fwrite(&c, sizeof(struct zxy), 1, f1);
        fwrite(&a, sizeof(struct zxy), 1, f2);
        fwrite(&b, sizeof(struct zxy), 1, f2);
        fwrite(&c, sizeof(struct zxy), 1, f2);
    }

    fclose(f1);
    fclose(f2);

    f2 = fopen("dane.bin", "rb");
    sprawdz(f2);
    struct zxy *tab;
    tab = wsk_file(f2);
    fseek(f2, 0, SEEK_END);
    int s = ftell(f2);
    fclose(f2);

    for (int i = 0; i < s / sizeof(struct zxy); i++)
    {
        printf("%c ", tab[i].znak);
    }
    printf("\n");

    free(tab);
    return 0;
}