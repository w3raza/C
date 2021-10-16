#include <stdio.h>
#include <string.h>

#define N 20

void *reverse(char *chain)
{
    char ch, *tail, *pointer;

    for (pointer = chain, tail = strlen(i) + pointer - 1; pointer < tail; pointer++, tail--)
    {
        ch = *pointer;
        *pointer = *tail;
        *tail = ch;
    }
}

int main()
{
    char chain[20] = "\n";

    printf("Enter some words, I will reverse that: ");
    fgets(chain, 20, stdin);
    chain[strlen(chain) - 1] = 0;

    reverse(chain);
    puts(chain);

    return 0;
}