#include<stdio.h>

int main()
{
    char ch=0;
    char z = 0;
    char j=0;

    for(int i=0; i < 6; i++)
    {
        ch = ('A'+j);
        z = ch + i;

        for(ch ; ch <= z ; ch++)
        {
            printf("%c", ch);
            j++;
        }
        printf("\n");
    }
    
    return 0;
}