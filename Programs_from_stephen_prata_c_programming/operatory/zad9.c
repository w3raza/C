#include <stdio.h>

void temperatura(double temp_F)
{
    double temp_C, temp_K;
    temp_C = 5.0 / 9.0 * (temp_F - 32.0);
    temp_K = temp_C + 273.16;

    printf("Stopnie w Farenheita: %.2f,\nw Celsujszach: %.2f,\nw Kelwinach: %.2f\n", temp_F, temp_C, temp_K);
}

int main()
{
    double temp_F;
    printf("Podaj temperature w stopniach Fahrenheita:\n");

    while (scanf("%f", temp_F) == 1)
    {
        temperatura(temp_F);
    }
    printf("koniec!\n");
    return 0;
}