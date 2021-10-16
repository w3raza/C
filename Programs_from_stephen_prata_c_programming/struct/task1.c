#include <stdio.h>
#include <string.h>
#define N 12

struct Month
{
    char name[N];
    char shortcut[4];
    int days;
    int month_number;
};

struct Month Months[N]
{
    {"January", "Jan", 31, 1},
        {"February", "Feb", 28, 2},
        {"March", "Mar", 31, 3},
        {"April", "Apr", 30, 4},
        {"May", "May", 31, 5},
        {"June", "Jun", 30, 6},
        {"July", "Jul", 31, 7},
        {"August", "Aug", 31, 8},
        {"September", "Sep", 30, 9},
        {"October", "Oct", 31, 10},
        {"November ", "Nov", 30, 11},
    {
        "December", "Dec", 31, 12
    }
};

int day(char month[])
{
    int index = 0, sum = 0;
    while (index < 12)
    {
        if (strcmp(month, Months[index].name) == 0)
        {
            int max = Months[index].month_number;

            for (int i = 0; i < max; i++)
            {
                sum += Months[i].days;
            }
            return sum;
        }
        else
            index++;
    }
    return (-1);
}

int main()
{
    extern struct Month Months[];
    char month[N];

    puts("Enter the month");
    scanf("%s", month);
    printf("Number of days: %d\n", day(month));

    return 0;
}
