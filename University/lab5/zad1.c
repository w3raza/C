#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 5;
    int size = 1;
    int *pas;
    for (int i = 0; i < N + 1; i++)
    {
        pas = realloc(pas, (i + 1) * sizeof(int));
        pas[0] = 1;
        pas[i] = 1;

        for (int j = 0; j < N - i; j++)
        {
            printf(" ");
        }
        printf("%d ", pas[0]);
        for (int j = i - 1; j >= 0; j--)
        {
            pas[j] = pas[j - 1] + pas[j];
            printf("%d ", pas[j]);
        }
        // printf("%d ", pas[i]);
        printf("\n");
    }
    free(pas);

    return 0;
}