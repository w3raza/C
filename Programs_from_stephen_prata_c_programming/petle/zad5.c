#include<stdio.h>

int main()
{
    char znak;
    printf("Wpisz znak\n");
    scanf("%c", &znak);

    int z = (znak-'A');

    for(int i=0; i <= z ; i++)
    {
        for(int j=0; j < (z-i); j++)
        printf(" ");

        char ch = 'A';
        char k = ch+i;
        for(ch; ch <= k ; ch++)
        {
            printf("%c", ch);
        }
        --ch;
        for(ch; ch > 'A'; ch)
        {
            printf("%c", --ch);
        }
        printf("\n");
    }
       
    return 0;
}