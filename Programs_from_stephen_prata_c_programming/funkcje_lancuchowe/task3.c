#include <stdio.h>
#include <ctype.h>

#define N 20

char *load(char array[])
{
    int i = 0;
    puts("Enter word:");

    while ((*array = getchar()) != '\n')
    {
        if (array[0] == ' ')
            array[0] = '\0';

        if (array[i] == ' ')
        {
            for (i; i < N; i++)
                array[i] = '\0';
            return array;
        }

        while (array[i] != '\n' && array[i] != '\0')
            i++;

        if (i > N)
        {
            puts("Too long word. It's doesn't exist\n");
            break;
        }
    }
}

void word(char *array)
{
    puts("Enter word:");

    const char *end = array + N - 1; // -1 aby '0' się zmieścił
    for (int space = 1; (array < end) && ((*array = getchar()) != EOF); *array = '\0')
    {
        if (!isspace(*array))
            space = !(++array);
        else if (!space)
            break;
    }
}

int main(void)
{
    char array[N] = {};

    load(array);
    puts("Your word: ");
    puts(array);

    //second version, have to comment the code
    // word(array);
    // puts("Your word: ");
    // puts(array);

    return 0;
}