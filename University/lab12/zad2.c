#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    int value;
    struct tnode *next;
};

struct tnode *dodaj_na_poczatek(struct tnode *head, int val)
{
    struct tnode *newElement = malloc(sizeof(struct tnode *));
    newElement->value = val;
    newElement->next = head;
    return newElement;
}

struct tnode *dodaj_na_koniec(struct tnode *head, int val)
{
    struct tnode *wsk = head;
    if (!head)
    {
        return dodaj_na_poczatek(head, val);
    }

    while (wsk->next)
    {
        wsk = wsk->next;
    };
    struct tnode *newElement = malloc(sizeof(struct tnode *));
    newElement->value = val;
    newElement->next = NULL;

    wsk->next = newElement;
    return head;
}

void wypelnij(struct tnode *head)
{
    struct tnode *wsk = head;

    while (wsk)
    {
        printf("%d\n", wsk->value);
        wsk = wsk->next;
    }
}

void zwolnij_pamiec(struct tnode *head)
{
    struct tnode *wsk = head;
    while (wsk)
    {
        struct tnode *temp = wsk->next;
        free(wsk);
        wsk = temp;
    }
}

int main()
{
    struct tnode *headPoczatek = NULL;
    struct tnode *headKoniec = NULL;

    int tab1[] = {23, 12, 67, 3, 123};

    for (int i = 0; i < sizeof(tab1) / sizeof(int); i++)
    {
        headPoczatek = dodaj_na_poczatek(headPoczatek, tab1[i]);
    }

    int tab2[] = {233, 213, 267, 323};
    for (int i = 0; i < sizeof(tab2) / sizeof(int); i++)
    {
        headKoniec = dodaj_na_poczatek(headKoniec, tab2[i]);
    }

    printf("\nLista: \n");
    wypelnij(headPoczatek);
    zwolnij_pamiec(headPoczatek);
    wypelnij(headKoniec);
    zwolnij_pamiec(headKoniec);

    return 0;
}