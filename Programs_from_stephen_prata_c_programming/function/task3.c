#include <stdio.h>

void fun(char ch, int column, int row)
{
    printf("character table:\n");
    for (int i = 0; i < column; i++)
    {
        for (int j; j < row; j++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
}

int main()
{
    char ch;
    int column, row;

    printf("Enter a char:\n");
    scanf("%c", &ch);
    printf("Enter a number of column:\n");
    scanf("%d", &column);
    printf("Enter a number of row:\n");
    scanf("%d", &row);

    fun(ch, column, row);

    return 0;
}