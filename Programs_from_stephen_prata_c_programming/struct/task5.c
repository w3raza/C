#include <stdio.h>

struct daneos
{
    char *name;
    char *surname;
};

typedef struct student
{
    struct daneos date;
    double grade[4];
    double average;
} STUDENT;

void load(STUDENT tab[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter grades for %s\n", tab[i].date.name);
        for (int j = 0; j < size; j++)
            scanf("%lf", &tab[i].grade[j]);
    }
    puts("\n");
}

void average_student(STUDENT tab[], const int size)
{
    int sum;

    for (int i = 0; i < size; i++)
    {
        sum = 0;
        for (int j = 0; j < size; j++)
            sum += tab[i].grade[j];
        tab[i].average = ((double)sum / size);
    }
}

void print(const STUDENT tab[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s %s\nGrades: ", tab[i].date.name, tab[i].date.surname);
        for (int j = 0; j < size; j++)
            printf("%g ", tab[i].grade[j]);
        printf("Average: %g\n\n", tab[i].average);
    }
}

double average_students(const STUDENT tab[], const int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += tab[i].average;
    }
    return (double)(sum / size);
}

int main()
{
    STUDENT tab[4] = {{"Kamil", "Jagoda"}, {"Michael", "Jordan"}, {"Tom", "Green"}, {"Tom", "Blue"}};
    load(tab, 4);
    average_student(tab, 4);
    print(tab, 4);
    printf("Average of all students: %g\n", average_students(tab, 4));

    return 0;
}
