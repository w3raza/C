#include <stdio.h>
#define N 20

char *strncpy(char *s1, char *s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        s1[i] = s2[i];
    }
    return s1;
}

int main()
{
    int n = 10;
    char s1[N];
    char s2[N] = {"Hi it me"};

    printf("%s\n", strncpy(s1, s2, n));

    return 0;
}