#include <stdio.h>
#include <stdlib.h>

typedef struct ListElement
{
    int data;
    struct ListElement *prev;
    struct ListElement *next;
} List_Element;

void show(List_Element *head);
void show_reverse(List_Element *head);                             //wyświetla listę od końca
int list_size(List_Element *head);                                 // podaje ilość elementów na liście
void push_front(List_Element **head, int number);                  //umieszcza element na początku listy
void push_back(List_Element **head, int number);                   //umieszcza element na końcu listy
void push_by_index(List_Element **head, int number, int position); //dodaje element we wskazanym miejscu na liście
void pop_front(List_Element **head);                               //usuwa element na początku
void pop_back(List_Element **head);                                //usuwa element na końcu
void pop_by_index(List_Element **head, int position);              // usuwa element na wskazanej pozycji
void odwroc(List_Element **head);                                  // odwraca kolejność elementów na liście
void CzyscListe(List_Element *head);                               // zwalnia listę

void show(List_Element *head)
{
    printf("\n");
    if (head == NULL)
        printf("List is empty");
    else
    {
        List_Element *temp = head;
        do
        {
            printf("%d", temp->data);
            printf("\n");
            temp = temp->next;
        } while (temp != NULL);
    }
}

void show_reverse(List_Element *head)
{
    printf("\n");
    if (head == NULL)
        printf("Lista jest pusta");
    else
    {
        List_Element *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        do
        {
            printf("%d", temp->data);
            printf("\n");
            temp = temp->prev;
        } while (temp != NULL);
    }
}

int list_size(List_Element *head)
{
    int counter = 0;
    if (head == NULL)
        return counter;
    else
    {
        List_Element *temp = head;
        do
        {
            counter++;
            temp = temp->next;
        } while (temp != NULL);
    }
    return counter;
}

void push_front(List_Element **head, int number)
{

    if (*head == NULL)
    {
        *head = (List_Element *)malloc(sizeof(List_Element));
        (*head)->data = number;
        (*head)->prev = NULL;
        (*head)->next = NULL;
    }
    else
    {
        List_Element *temp;
        temp = (List_Element *)malloc(sizeof(List_Element));
        temp->data = number;
        temp->prev = NULL;
        temp->next = (*head);
        (*head)->prev = temp;
        *head = temp;
    }
}

void push_back(List_Element **head, int number)
{

    if (*head == NULL)
    {
        *head = (List_Element *)malloc(sizeof(List_Element));
        (*head)->data = number;
        (*head)->prev = NULL;
        (*head)->next = NULL;
    }
    else
    {
        List_Element *temp = *head;
        List_Element *new_element;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = (List_Element *)malloc(sizeof(List_Element));
        temp->next->data = number;
        temp->next->prev = temp;
        temp->next->next = NULL;
    }
}

void push_by_index(List_Element **head, int number, int position)
{
    if (position == 0)
        push_front(head, number);
    else
    {
        if (position == list_size(*head))
            push_back(head, number);
        else
        {
            List_Element *temp = *head;
            List_Element *tmp;

            int i = 0;
            while (temp->next != NULL && i < position - 1)
            {
                temp = temp->next;
                i++;
            }

            tmp = temp->next;
            temp->next = (List_Element *)malloc(sizeof(List_Element));
            temp->next->data = number;
            temp->next->prev = temp;
            tmp->prev = temp->next;
            temp->next->next = tmp;
        }
    }
}

void pop_front(List_Element **head)
{

    if (*head != NULL)
    {
        if ((*head)->next == NULL)
        {
            *head = NULL;
        }
        else
        {
            List_Element *tmp;
            tmp = (*head)->next;
            free(*head);
            *head = tmp;
            (*head)->prev = NULL;
        }
    }
}

void pop_back(List_Element **head)
{

    if ((*head)->next == NULL)
    {
        *head = NULL;
    }
    else
    {
        List_Element *temp = *head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}
void pop_by_index(List_Element **head, int position)
{
    if (position == 0)
        pop_front(head);
    else
    {
        List_Element *temp = *head;
        List_Element *tmp;

        int i = 0;
        while (temp->next != NULL && i < position - 1)
        {
            temp = temp->next;
            i++;
        }

        tmp = temp->next;
        temp->next = tmp->next;
        temp->next->prev = temp;
        free(tmp);
    }
}

void odwroc(List_Element **head)
{
    List_Element *prev = NULL;
    List_Element *temp = *head;
    List_Element *next = NULL;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    *head = prev;
}

void CzyscListe(List_Element *head)
{
    List_Element *wsk = head;
    while (wsk)
    {
        List_Element *temp = wsk->next;
        free(wsk);
        wsk = temp;
    }
}

int main()
{
    List_Element *head;
    head = (List_Element *)malloc(sizeof(List_Element));
    head = NULL;

    int tab[] = {15, 5, 16, 20, 3, 12, 18, 23, 10, 13, 6, 7};
    int size = sizeof(tab) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        push_front(&head, tab[i]);
    }
    printf("Lista\n");
    show(head);

    int n = -1;
    int number;
    int position;

    while (n != 0)
    {
        printf("\nCo chcesz zrobić?\n");
        printf("0 - konczy program\n");
        printf("1 - wyawietl listę\n");
        printf("2 - wyswietl listę od konca\n");
        printf("3 - podaj ile elmentow\n");
        printf("4 - umiesc element na poczatku listy\n");
        printf("5 - umiesc element na koncu listy\n");
        printf("6 - dadaje element we wskazanym miejscu na liscie\n");
        printf("7 - usuwa element na poczatku listy\n");
        printf("8 - usuwa element na koncu listy\n");
        printf("9 - usuwa element we wskazanym miejscu na liscie\n");
        printf("10 - odwaraca kolejnosc elementow na liscie\n\n");

        scanf("%d", &n);

        switch (n)
        {
        case 0:
            return 0;
            break;

        case 1:
            printf("Lista:\n");
            show(head);
            break;

        case 2:
            printf("Lista od tylu:\n");
            show_reverse(head);
            break;

        case 3:
            printf("ilosc elementow:");
            int k = list_size(head);
            printf("%d\n", k);
            break;

        case 4:
            printf("Wpisz liczbe jaka chcesz dodac: ");
            scanf("%d", &number);
            push_front(&head, number);
            break;

        case 5:
            printf("Wpisz liczbe jaka chcesz dodac: ");
            scanf("%d", &number);
            push_back(&head, number);
            break;

        case 6:
            printf("Wpisz liczbe jaka chcesz dodac: ");
            scanf("%d", &number);
            printf("Wpisz pozycje: ");
            scanf("%d", &position);
            push_by_index(&head, number, position);
            break;
        case 7:
            pop_front(&head);
            break;
        case 8:
            pop_back(&head);
            break;

        case 9:
            printf("Wypisz pozycje: ");
            scanf("%d", &position);
            pop_by_index(&head, position);
            break;

        case 10:
            odwroc(&head);
            break;

        default:
            printf("Podano zla opcje");
            break;
        }
    }
    CzyscListe(head);
    return 0;
}