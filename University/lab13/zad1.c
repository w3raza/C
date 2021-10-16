#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int value;
    struct tnode *next;
} node;

node *dodaj_na_poczatek(node *head, int val)
{
    node *newElement = malloc(sizeof(node));
    newElement->value = val;
    newElement->next = head;
    return newElement;
}

node *dodaj_na_koniec(node *head, int val)
{
    node *wsk = head;
    if (!head)
    {
        return dodaj_na_poczatek(head, val);
    }

    while (wsk->next)
    {
        wsk = wsk->next;
    };
    node *newElement = malloc(sizeof(node));
    newElement->value = val;
    newElement->next = NULL;

    wsk->next = newElement;
    return head;
}

node *malejaco(node *head, int val)
{
    if (!head || head->value < val)
    {
        return dodaj_na_poczatek(head, val);
    }

    node *wsk = head;
    node *nextWsk = head->next;

    while (wsk->next && wsk->value > val)
    {
        wsk = wsk->next;
        nextWsk = wsk->next;
    }

    node *newElement = malloc(sizeof(node));
    newElement->value = val;
    newElement->next = nextWsk;

    wsk->next = newElement;

    return head;
}

node *rosnaco(node *head, int val)
{
    if (!head || head->value > val)
    {
        return dodaj_na_poczatek(head, val);
    }

    node *wsk = head;
    node *nextWsk = head->next;

    while (wsk->next && wsk->value < val)
    {
        wsk = wsk->next;
        nextWsk = wsk->next;
    }

    node *newElement = malloc(sizeof(node));
    newElement->value = val;
    newElement->next = nextWsk;

    wsk->next = newElement;

    return head;
}

void wypisz(node *head)
{
    node *wsk = head;

    while (wsk)
    {
        printf("%d\n", wsk->value);
        wsk = wsk->next;
    }
}

void find(node *head, int val)
{
    while (head->next && head->value != val)
    {
        head = head->next;
    }

    if (head != NULL && head->value == val)
    {
        printf("Znaleziona liczbe:%d, adres: %p\n", val, head);
    }
    else
    {
        printf("Nie znaleziono takiej liczby\n");
    }
}

node *del(node *head, int val)
{
    node *prevWsk = NULL;
    node *wsk = head;
    node *nextWsk = head->next;
    while (wsk->next && wsk->value != val)
    {
        prevWsk = head;
        wsk = wsk->next;
        nextWsk = wsk->next;
    }

    if (wsk != NULL && wsk->value == val)
    {
        if (wsk == head)
        {
            free(wsk);
            return nextWsk;
        }
        prevWsk->next = nextWsk;
        free(wsk);
    }
    else
    {
        printf("Nie znaleziono wartosci\n");
    }
    return head;
}

void zwolnij_pamiec(node *head)
{
    node *wsk = head;
    while (wsk)
    {
        node *temp = wsk->next;
        free(wsk);
        wsk = temp;
    }
}

int main(int argc, char const *argv[])
{
    node *headPoczatek = NULL;
    node *headKoniec = NULL;
    node *headSortM = NULL;
    node *headSortR = NULL;

    int tab[] = {23, 12, 67, 3, 123};

    for (int i = 0; i < sizeof(tab) / sizeof(int); i++)
    {
        headPoczatek = dodaj_na_poczatek(headPoczatek, tab[i]);
        headKoniec = dodaj_na_koniec(headKoniec, tab[i]);
        headSortM = malejaco(headSortM, tab[i]);
        headSortR = rosnaco(headSortR, tab[i]);
    }

    printf("Lista: \n");
    wypisz(headPoczatek);
    printf("-----\n");
    wypisz(headKoniec);

    //D
    printf("\nLista malejaco: \n");
    wypisz(headSortM);
    zwolnij_pamiec(headSortM);
    printf("\nLista rosnaco: \n");
    wypisz(headSortR);
    //E
    int liczba = 0;
    char odp;
    int n = 1;
    int k = 1;

    while (n == 1)
    {
        printf("--------------------------\n");
        printf("Chcesz szukac liczb? (y/n)\n");
        scanf("%s", &odp);
        printf("--------------------------\n");

        if (odp == 'y')
        {
            printf("Podaj liczbe, ktora chcesz znalezc:");
            scanf("%d", &liczba);
            printf("\npodano: %d\n------------------------------------\n", liczba);
            find(headKoniec, liczba);
        }
        else
        {
            n--;
        }
    }
    while (k == 1)
    {
        int liczba = 0;
        printf("Chcesz usunac liczbe? (y/n)\n");
        scanf("%s", &odp);
        printf("--------------------------\n");

        if (odp == 'y')
        {
            printf("Podaj liczbe, ktora chcesz usunac:");
            scanf("%d", &liczba);
            printf("\npodano: %d\n------------------------------------\n", liczba);
            headSortR = del(headSortR, liczba);

            printf("Lista po usunieciu: \n");
            wypisz(headSortR);
            printf("--------------------------\n");
        }
        else
        {
            k--;
        }
    }
    zwolnij_pamiec(headPoczatek);
    zwolnij_pamiec(headKoniec);
    zwolnij_pamiec(headSortR);

    return 0;
}