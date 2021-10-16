#include <stdio.h>

bool check(int n)
{
    int i, flag = 0;
    for (i = 2; i <= n / 2; ++i)
    {
        // condition for non-prime
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }

    if (n == 1)
    {
        return 0;
    }
    else
    {
        if (flag == 0)
            return 1;
        else
            return 0;
    }
}
int main()
{
    int n;

back:
    printf("Enter a range\n");
    scanf("%d", &n);

    if (n > 0)
    {
        for (int j = 2; j <= n; j++)
        {
            if (check(j))
                printf("%d ", j);
        }
        printf("\n");
    }
    else
    {
        goto back;
    }

    return 0;
}