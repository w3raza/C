#include <stdio.h>
#define SQ2(x) x *x
#define SQ3(x) (x) * (x)
#define SQ4(x) ((x) * (x))
#define PR(X) printf("kwadratem " #X " jest %d \n", X)
#define PP printf(" \n **********  \n")
#define plus_i(n) a##n

int main(void)
{
    int plus_i(1);
    a1 = 2;
    PR(SQ2(7));
    PR(SQ3(7));
    PR(SQ4(7));
    PP;
    PR(SQ2(2 + 3));
    PR(SQ3(2 + 3));
    PR(SQ4(2 + 3));
    PP;
    PR(4 / SQ2(2));
    PR(4 / SQ3(2));
    PR(4 / SQ4(2));
    PP;
    int plus_i(2);
    a2 = 2;
    PR(SQ2(++a2));
    int plus_i(3);
    a3 = 2;
    PR(SQ3(++a3));
    int plus_i(4);
    a4 = 2;
    PR(SQ4(++a4));
    return 0;
}
