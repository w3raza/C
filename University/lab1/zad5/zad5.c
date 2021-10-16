#include <stdio.h>

void funkcja(char *lancuch)
{
    char *znak = lancuch;
    int i = 0;
    while (*znak != '\0')
    {
        if (*znak > 33 && *znak < 127)
        {
            lancuch[i] = *znak;
            i++;
        }
        znak++;
    }
    lancuch[i] = '\0';
}

int main()
{
    char tab[] = "To jest TESTOWY    lancuch";
    printf("PRZED:%s\n", tab);
    funkcja(tab);
    printf("PO:%s\n", tab);

    return 0;
}