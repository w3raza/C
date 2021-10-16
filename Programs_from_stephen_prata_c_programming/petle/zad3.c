#include<stdio.h>

int main()
{
    const int rzedy = 6;
    const int znaki = 6;
    char ch;

    for(int i=0; i < rzedy ; i++)
    {
        for(ch = 'F'; ch >= ('F'- i); ch--)
        printf("%c", ch);
        printf("\n");
    }
    return 0;
}