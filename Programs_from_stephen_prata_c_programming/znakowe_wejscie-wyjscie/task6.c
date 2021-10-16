#include <stdio.h>
#include <ctype.h>

char pobierz_wybor(void);
char pobierz_pierwszy(void);
int pobierz_int(void);
void liczenie(void);

int main(void)
{
    int wybor;
    void liczenie(void);

    while ((wybor = pobierz_wybor()) != 'q')
    {
        switch (wybor)
        {
        case 'a':
            printf("buy low, sell high\n");
            break;
        case 'b':
            putchar('\a');
            break;
        case 'c':
            liczenie();
            break;
        default:
            printf("Program error!\n");
            break;
        }
    }
    printf("Goodbye.\n");
    return 0;
}

void liczenie(void)
{
    int n, i;
    printf("How long do I have to count, enter an integer number:\n");
    n = pobierz_int();

    for (i = 1; i <= n; i++)
    {
        printf("%d\n", i);
    }
    while (getchar() != '\n')
        continue;
}

char pobierz_wybor(void)
{
    int ch;

    printf("Enter the desired letter:\n");
    printf("a.porada\tb.alarm\n");
    printf("c.liczenie\tq.koniec\n");

    ch = pobierz_pierwszy();

    while ((ch < 'a' || ch > 'c') && ch != 'q')
    {
        printf("Enter a, b, c or q\n");
        ch = pobierz_pierwszy();
    }
    return ch;
}

char pobierz_pierwszy(void)
{
    int ch;

    ch = getchar();
    while (getchar() != '\n')
        continue;
    if (isprint(ch))
        return ch;
}

int pobierz_int(void)
{
    int we;
    char ch;

    while (scanf("%d", &we) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not an integer number.\nPliss choose ");
        printf("Total value, np.23, -7 or 3:");
    }

    return we;
}
