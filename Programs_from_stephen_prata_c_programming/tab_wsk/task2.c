#include <stdio.h>
void copy_tab(double source[], double cel1[], int n)
{
    printf("Copy_tab: ");
    for (int i = 0; i < n; i++)
    {
        cel1[i] = source[i];
        printf("%g ", cel1[i]);
    }
    printf("\n");
}
void copy_wsk(double source[], double cel1[], int n)
{
    printf("Copy_wsk: ");
    for (int i = 0; i < n; i++)
    {
        *(cel1 + i) = *(source + i);
        printf("%g ", *(cel1 + i));
    }
    printf("\n");
}
void copy_wsk2(double source[], double cel2[], double *last)
{
    printf("Copy_wsk2: ");
    for (int i = 0; i < sizeof(*last) - 3; i++)
    {
        *(cel2 + i) = *(source + i) - *last;
        printf("%g ", *(cel2 + i));
    }
    printf("\n");
}

int main()
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double cel1[5];
    double cel2[5];

    copy_tab(source, cel1, 5);
    copy_wsk(source, cel1, 5);
    copy_wsk2(source, cel2, source + 5);

    return 0;
}