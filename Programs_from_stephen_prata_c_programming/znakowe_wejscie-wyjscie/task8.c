#include <stdio.h>
#include <ctype.h>

void needed(void)
{
    while (getchar() != '\n')
        continue; /*pomijanie aż do nowej lini*/
}

void print()
{
    printf("**************************************\n");
    printf("Choose one from action\n");
    printf("a addition\tb subtraction\nc multiplication\td division\nq exit\n");
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
    print();
    ch = download_first();

    while ((ch < 'a' || ch > 'd') && ch != 'q')
    {
        printf("Enter a, b, c, d or q\n");
        ch = download_first();
    }
    return ch;
}

float download_float(void)
{
    float number;
    char ch;

    printf("Enter number ");
    while (scanf("%f", &number) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a flaot number.\nPliss choose ");
        printf("Total value, np.23\n");
    }

    return number;
}
float download_float_division(float number)
{
    while (number == 0)
    {
        printf("enter a number other than %f: ", number);
        scanf("%f", &number);
    }
    return number;
}

float addition(float first, float second)
{
    needed();
    return first + second;
}

float subtraction(float first, float second)
{
    needed();
    return first - second;
}
float multiplication(float first, float second)
{
    needed();
    return first * second;
}
float division(float first, float second)
{
    needed();
    return first / second;
}
int main()
{
    float first, second;
    int n, choice;

    while ((choice = download()) != 'q')
    {
        switch (choice)
        {
        case 'a':
            first = download_float();
            second = download_float();
            printf("%g + %g = %g\n", first, second, addition(first, second));

            break;
        case 'b':
            first = download_float();
            second = download_float();
            printf("%g - %g = %g\n", first, second, subtraction(first, second));

            break;
        case 'c':
            first = download_float();
            second = download_float();
            printf("%g * %g = %g\n", first, second, multiplication(first, second));

            break;
        case 'd':
            first = download_float();
            second = download_float_division(download_float());
            printf("%g / %g = %g\n", first, second, division(first, second));

            break;
        case 'q':
            printf("Finish!\n");
            break;
        default:
            printf("Program error!\n");
            break;
        }
    }
    return 0;
}