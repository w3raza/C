#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

double d_rand(double min, double max)
{
    double r = (double)rand() / RAND_MAX;
    return r * (max - min) + min;
}

void sprawdz(void *a)
{
    if (a == NULL)
    {
        puts("ERROR");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    FILE *f1, *f2;
    f1 = fopen("plik.txt", "w");
    f2 = fopen("plik.bin", "wb");
    sprawdz(f1);
    sprawdz(f2);

    float tab[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tab[i][j] = d_rand(0, 100);
            fprintf(f1, "%f\t", tab[i][j]);
            fprintf(f2, "%f\t", tab[i][j]);
        }
        fprintf(f1, "\n");
        fprintf(f2, "\n");
    }
    long ilosc = sizeof(tab) / sizeof(float);
    printf("%ld\n", ilosc);
    fwrite(tab, sizeof(float), sizeof(tab) / sizeof(float), f2);
    printf("----------------------------------------------------------\n");

    fclose(f1);
    fclose(f2);

    f1 = fopen("plik.txt", "r");

    fseek(f1, 0L, SEEK_END);
    long size_txt = ftell(f1);
    printf("Size .txt = %ld\n", size_txt);
    fseek(f1, 0, SEEK_SET);

    char tab1[size_txt];

    for (int i = 0; i < N; i++)
    {
        fgets(tab1, size_txt - 1, f1);
        printf("%s", tab1);
    }
    printf("----------------------------------------------------------\n");
    fclose(f1);

    f2 = fopen("plik.bin", "rb+");

    fseek(f2, 0L, SEEK_END);
    long int size_bin = ftell(f2);
    printf("Size .bin = %ld\n", size_bin);
    fseek(f2, 0, SEEK_SET);

    char tab2[100];

    for (int i = 0; i < N; i++)
    {
        fgets(tab2, size_bin - 1, f2);
        printf("%s", tab2);
    }
    printf("----------------------------------------------------------\n");
    fclose(f2);

    f2 = fopen("plik.bin", "ab+");
    float zero = 0.00000;

    for (int i = 0; i < ilosc; i++)
    {
        fseek(f2, sizeof(float) * 4L, SEEK_CUR);
        fwrite(&zero, sizeof(float), 1, f2);
    }

    fclose(f2);

    f2 = fopen("plik.bin", "rb+");
    char tab3[100];

    fread(tab3, sizeof(char), 0, f2);

    for (int i = 0; i < N; i++)
    {
        fgets(tab3, size_bin - 1, f2);
        printf("%s", tab3);
    }
    printf("----------------------------------------------------------\n");

    fclose(f2);

    return 0;
}