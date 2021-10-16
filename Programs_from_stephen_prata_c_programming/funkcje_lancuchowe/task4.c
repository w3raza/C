#include <stdio.h>
#include <ctype.h>

#define N 20

int number()
{
    int limit;

    puts("Character limit:");
    scanf("%d", &limit);

    while (scanf("%d", &limit) != 1)
    {
        while (getchar() != '\n')
            continue;
        printf("It is not a number.\n");
    }

    return limit;
}

void word(char *array)
{
    int i, limit = number();

    puts("Enter word:");

    const char *end = array + N - 1; // -1 aby '0' się zmieścił

    for (int space = 1; (array < end) && ((*array = getchar()) != EOF) && i < limit; *array = '\0')
    {
        if (!isspace(*array))
            space = !(++array);
        else if (!space)
            break;
        i++;
    }
}

int main(void)
{
    char array[N] = {};

    word(array);
    puts("Your word: ");
    puts(array);

    return 0;
}