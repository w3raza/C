void f_tab_1d_stat(char arg[]) {}

void f_tab_1d_dyn(char *arg) {}

void f_tab_2d_stat(char arg[][3]) {}

void f_tab_2d_dyn(char **arg) {}

int main()
{
    char tab_1d_stat[30], *tab_1d_dyn;
    char tab_2d_stat[2][3], **tab_2d_dyn;
    tab_1d_dyn = new char[15];

    tab_2d_dyn = new char *[15];
    for (unsigned i = 0; i < 15; ++i)
        tab_2d_dyn[i] = new char[3];

    // dla jednowymiarowej tablicy nie ma znaczenia, czy tablica jest dynamiczna czy statyczna
    f_tab_1d_stat(tab_1d_stat);
    f_tab_1d_stat(tab_1d_dyn);

    f_tab_1d_dyn(tab_1d_stat);
    f_tab_1d_dyn(tab_1d_dyn);

    // ale dla liczby wymiarów > 1 już ma...
    f_tab_2d_dyn(tab_2d_dyn);
    f_tab_2d_stat(tab_2d_stat);

    // błąd kompilacji:
    //f_tab_2d_dyn(tab_2d_stat);
    //f_tab_2d_stat(tab_2d_dyn);

    delete[] tab_1d_dyn;
    for (unsigned i = 0; i < 15; ++i)
        delete[] tab_2d_dyn[i];
    delete[] tab_2d_dyn;
    return 0;
}