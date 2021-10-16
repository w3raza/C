#include<stdio.h>

int main()
{
    int x = 5, n = 1;
    for(int n=1; x < 150; n++)
    {
        x -=n;
        x *= 2;
        printf("%d, %d\n", x, n);
    }
    
    return 0;
}