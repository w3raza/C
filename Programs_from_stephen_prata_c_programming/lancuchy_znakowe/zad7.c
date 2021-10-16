#include<stdio.h>
#include<float.h>

int main()
{
    double n=1.0/3.0;
    float m=1.0/3.0;
    printf("%-.4f\n%-.12f\n%-.16f\n", n, n, n);
    printf("%-.4f\n%-.12f\n%-.16f\n", m, m, m);
    printf("%d\n %d\n", FLT_DIG, DBL_DIG);
    return 0;
}