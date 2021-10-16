#include <stdio.h>

int main()
{
    int n;

    do
    {
        printf("Podaj wysokość:");
        scanf("%d", &n);
    } while (n <= 0);
    printf("%d\n", n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("/");
        }
        printf("|");
        for (int j = 0; j < i; j++)
        {
            printf("\\");
        }

        printf("\n");
    }

    return 0;
}
