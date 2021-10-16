#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fun0(double x) { return log(x); }
double fun1(double x) { return x * x; }
double fun2(double x) { return sin(x); }
double fun3(double x) { return cos(x); }

int main()
{
    int i = 0;
    char *nazwy[] = {"log", "pow", "sin", "cos"};

    double *TAB_FUN[5];
    double data[8] = {0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0};

    TAB_FUN[0] = fun0;
    TAB_FUN[1] = fun1;
    TAB_FUN[2] = fun2;
    TAB_FUN[3] = fun3;
    TAB_FUN[4] = NULL;

    char *str;
    double *wsk_fun;

    for (int i = 0; i < 4; i++)
    {
        wsk_fun = TAB_FUN[i];
        str = nazwy[i];
        for (int i = 0; i < 8; i++)
        {
            printf("%s(%.1f) = %g\t ", str, data[i], *(wsk_fun + *(data + i)));
        }
        printf("\n------------------------------------------\n");
    }
    return 0;
}