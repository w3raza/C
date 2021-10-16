#include <stdio.h>

double average(int s, int amount)
{
    return (double)s / amount;
}

int main()
{
    int integer = 0;
    int j = 0;
    int k = 0;
    int sum_even = 0;
    int sum_odd = 0;

    do
    {
        scanf("%d", &integer);
        //even
        if (integer % 2 == 0 && integer != 0)
        {
            j++;
            sum_even += integer;
        }
        //odd
        if (integer % 2 == 1)
        {
            k++;
            sum_odd += integer;
        }
    } while (integer != 0);

    printf("Number of even numbers:%d: , Average: %g , \n", j, average(sum_even, j));
    printf("Number of odd numbers:%d: , Average: %g , \n", k, average(sum_odd, k));
    return 0;
}