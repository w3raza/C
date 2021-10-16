#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 12

typedef struct lot
{
    int index;
    bool free_place;
    char *name;
    char *surname;
} LOT;

void print()
{
    printf("Enter a letter to choose the option:\n");
    printf("a) Show a number of free places\n");
    printf("b) Show a list of free places\n");
    printf("c) Show a alphabetical list of places\n");
    printf("d) Book a place for customer\n");
    printf("e) Delete a seat reservation\n");
    printf("f) Finish\n");
}

void needed(void)
{
    while (getchar() != '\n')
        continue; /*pomijanie aż do nowej lini*/
}

int is_free(const LOT tab[])
{
    int amount = 0;

    for (int i = 0; i < N; i++)
        if (tab[i].free_place == 1)
            amount++;

    return amount;
}

void is_free_list(LOT tab[])
{
    printf("\nList of free places:\n");
    for (int i = 0; i < N; i++)
        if (tab[i].free_place == 1)
            printf("%d, ", tab[i].index);
    puts("\n");
}

void print_list(const LOT tab[])
{
    for (int i = 0; i < N; i++)
        if (tab[i].free_place == 0)
            printf("Place: %d, Date: %s %s\n", tab[i].index, tab[i].name, tab[i].surname);
}

void alphabetical_list(LOT tab[])
{
    int control = 0, k = 0, j = 0;

    int ap[N];

    for (int i = 0; i < N; i++)
    {
        if (tab[i].free_place != 1) //kiedy cos jest w tab
        {
            //ap[control] = (int *)malloc(N);
            if (control > 0)
            {
                for (j; j < N;)
                    if (tab[i].name[j] > tab[k].name[j])
                    {
                        ap[control] = tab[i].index;
                        ap[control - 1] = tab[k].index;
                        j = N;
                    }
                    else if (tab[i].name[j] == tab[k].name[j])
                    {
                        j++;
                    }
                    else if (tab[i].name[j] < tab[k].name[j])
                    {
                        ap[control - 1] = tab[k].index;
                        ap[control] = tab[i].index;
                        j = N;
                    }
            }
            else
                ap[control] = tab[i].index;
            k = i;
            control++;
        }
    }
    for (int x = 0; x < control; x++)
    {
        int index = ap[x];
        printf("Place: %d, Date: %s %s\n", ap[x], tab[index].name, tab[index].surname);
    }
}

void check_alphabetical_list(LOT *wsk)
{
    if (is_free(wsk) != N)
        alphabetical_list(wsk);
    else
        printf("The list is empty.\n");
}

char *load(char *temp, int index)
{
    char *result;
    char *here;
    result = fgets(temp, N, stdin);
    if (result)
    {
        here = strchr(temp, '\n'); // szukamy nowego wiersza
        if (here)                  //jesli adres jest rozny od NULL
            *here = '\0';          //zmieniamy znak nowego wiersza na pusty
        else
            while (getchar() != '\n')
                continue;
    }
    return result;
}

void download(LOT tab[], int index)
{
    char temp[N];

    printf("Enter name: ");
    load(temp, index);
    tab[index].name = (char *)malloc(strlen(temp) + 1); //alokuje pamiec do lancucha
    strcpy(tab[index].name, temp);                      //kopjuje lancuch do zaalokowanej pamieci

    printf("Enter surname: ");
    load(temp, index);
    tab[index].surname = (char *)malloc(strlen(temp) + 1);
    strcpy(tab[index].surname, temp);
    puts("\n");
}

void booking(LOT tab[])
{
    int control = 1, place;

    printf("\nWhich place do u want book? ");
    while (control != 0)
    {
        scanf("%d", &place);
        if (tab[place - 1].free_place)
        {
            tab[place - 1].free_place = 0;
            control = 0;
        }
        else
            printf("This place is taken, choose another\n");
    }
    needed();
    download(tab, place - 1);
}

void delete_booking(LOT *wsk)
{
    int place;

    printf("Which place do u want delete the booking?\n");
    scanf("%d", &place);

    if (wsk[place - 1].free_place)
    {
        printf("Actually, this place is free\n");
    }
    else
    {
        wsk[place - 1].free_place = 1;
        free(wsk->name);
        free(wsk->surname);
    }
}

int main()
{
    LOT tab[N];
    LOT *wsk = &tab[0];
    char ch;

    for (int i = 0; i < N; i++)
        tab[i].free_place = 1;
    for (int i = 0; i < N; i++)
        tab[i].index = i + 1;

back:
    print();
    while (ch != 'f')
        switch (ch = getchar())
        {
        case 'a':
            printf("\nNumber of free places: %d\n\n", is_free(tab));
            goto back;

        case 'b':
            is_free_list(tab);

            goto back;

        case 'c':
            check_alphabetical_list(wsk);
            goto back;

        case 'd':
            booking(tab);
            goto back;

        case 'e':
            delete_booking(wsk);
            goto back;

        case 'f':
            ch = 'f';
            break;
        }
    print_list(tab);

    return 0;
}