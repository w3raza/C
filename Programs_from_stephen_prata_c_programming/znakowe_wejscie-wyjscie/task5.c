#include <stdio.h>

int main(void)
{
    int t;

    printf("choose a number from 1 to 100");
    printf("\nif I was successful, enter y\nif not, enter n");
    printf("Let me some clue\nwhether your number was more than 50?\n");

    if (getchar() == 'y')
    {
        printf("Let me some clue\nwhether your number was more than 75?\n");
        while (getchar() != '\n')
            continue;
        if (getchar() == 'y')
        {
            while (getchar() != '\n')
                continue;
            t = 76;
            printf("Hm... whether yours number is %d?\n", t);
            while (getchar() != 'y')
            {
                printf("Hm... whether yours number is %d?\n", ++t);
                while (getchar() != '\n')
                    continue;
            }
        }
        else
        {
            while (getchar() != '\n')
                continue;
            t = 51;
            printf("Hm... whether yours number is %d?\n", t);
            while (getchar() != 'y')
            {
                printf("Hm... whether yours number is %d?\n", ++t);
                while (getchar() != '\n')
                    continue;
            }
        }
    }
    else
    {
        printf("Let me some clue\nwhether your number was more than 25?\n");
        while (getchar() != '\n')
            continue;
        if (getchar() == 'y')
        {
            while (getchar() != '\n')
                continue;
            t = 26;
            printf("Hm... whether yours number is %d?\n", t);
            while (getchar() != 'y')
            {
                printf("Hm... whether yours number is %d?\n", ++t);
                while (getchar() != '\n')
                    continue;
            }
        }
        else
        {
            while (getchar() != '\n')
                continue;
            t = 1;
            printf("Hm... whether yours number is %d?\n", t);
            while (getchar() != 'y')
            {
                printf("Hm... whether yours number is %d?\n", ++t);
                while (getchar() != '\n')
                    continue;
            }
        }
    }
    printf("Winner, thanks^^\n");
    printf("Your number:%d\n", t);
    return 0;
}
