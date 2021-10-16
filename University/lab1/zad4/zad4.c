#include <stdio.h>

int main()
{
    char znak;

    do
    {
        printf("\nPodaj litere:");
        scanf("%c", &znak);
    } while (znak < 'A' || znak > 'Z');
    // printf("%c\n", znak);

    for (char i = znak; i >= 'A'; i--)

    {
        for (char j = 'A'; j <= i; j++)
        {
            printf(" ");
        }
        for (char j = znak; j >= i; j--)
        {
            printf("%c", j);
        }
        for (char j = i + 1; j <= znak; j++)
        {
            printf("%c", j);
        }

        printf("\n");
    }

    return 0;
}
