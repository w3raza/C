#include<stdio.h>
#include<string.h>

int main()
{
    char word[12];

    scanf("%s", word);
    printf("Podane: %s\n", word);
    int l = strlen(word);
    printf("%d\n", l);

    for(int i=0; i <= strlen(word); i++)
    {
        printf("%c", word[l--]);
    }
    printf("\n");
    
    return 0;
}