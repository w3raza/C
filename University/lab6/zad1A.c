#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("Argument[%d] - %s\n", i, argv[i]);
    }

    int integerNumber = atoi(argv[1]);
    float floatNumber = atof(argv[2]);

    printf("Integer: %d, Float: %0.2f\n", integerNumber, floatNumber);

    return 0;
}