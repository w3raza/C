#include <stdio.h>

int main()
{
    const int stala = 14;
    int day = 1, week;

    printf("Podaj day\n");

    while (day > 0)
    {
        scanf("%d", &day);
        while (day > 1)
        {
            printf("%d is %d weeks, %d days\n", day, day / stala, day % stala);
            day -= day++;
        }
    }
    return 0;
}