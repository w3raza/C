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

int is_leap_year(int index, int year)
{
    if (index > 3 && year % 4 == 0)
        return 1;
    else
        return 0;
}

int count(int day, char month[], int year)
{
    int index = 0, sum = 0, max;
    int mon;
    if (month[1] == 48 || month[1] == 49 || month[1] == 50)
        mon = 10 + month[1] - 48;
    else
        mon = month[0] - 48;

    while (index < 12)
    {
        if (strcmp(month, Months[index].name) == 0 || strcmp(month, Months[index].shortcut) == 0 || (mon < 13 && mon > 0))
        {
            if (mon > 0 && mon < 13)
                max = mon;
            else
                max = Months[index].month_number;

            for (int i = 0; i < max - 1; i++)
            {
                sum += Months[i].days;
            }

            return sum + day + is_leap_year(max, year);
        }
        else
            index++;
    }
    return (-1);
}

int main()
{
    extern struct Month Months[];
    int day;
    char month[N];
    int year;

    puts("Enter the day");
    scanf("%d", &day);
    puts("Enter the month");
    scanf("%s", month);
    printf("Liczba %d\n", month[0]);
    puts("Enter the year");
    scanf("%d", &year);

    printf("Number of days: %d\n", count(day, month, year));

    return 0;
}
