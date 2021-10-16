#include <stdio.h>
#include <string.h>
#define N 20
#define n 3

struct Date
{
    char name[N];
    char second_name[N];
    char surname[N];
};

typedef struct Class
{
    long int pesel;
    struct Date person;
} CLASS;

void print(const CLASS tab[], int max)
{
    char dot;

    for (int i = 0; i < n; i++)
    {
        if (strlen(tab[i].person.second_name) != 0)
            dot = '.';
        else
            dot = ' ';
        printf("%s, %s %c%c --%ld\n", tab[i].person.surname, tab[i].person.name, tab[i].person.second_name[0], dot, tab[i].pesel);
    }
}

int main()
{
    CLASS tab[n] = {{910607481, "Kamil", "Adam", "Komiwojazer"}, {1060748146464, "Patric", "", "Sodone"}};
    print(tab, n);

    return 0;
}