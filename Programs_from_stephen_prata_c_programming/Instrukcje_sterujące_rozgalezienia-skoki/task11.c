#include <stdio.h>
#define W 1.25
#define B 0.65
#define O 0.89

void print()
{
    printf("**************************************\n");
    printf("Co chcesz zamówić:\n");
    printf("A arbuzy 1,25 zl/kg \tB buraki 0,65 zl/kg \tC cebula 0,89 zl/kg \tK wyjscie\n");
}
double price(int fruit, double price)
{
    return fruit * price;
}

double discount(int sum)
{
    if (sum > 100)
        return 0.05;
    else
        return 0.0;
}

double deliver(int weight)
{
    if (weight < 5)
        return 3.5;
    else if (weight < 20)
        return 10.0;
    else
        return 8.0 + (weight - 20) * 0.1;
}

double results(double sum, double discount, double delivery)
{
    return sum - (sum * discount) + delivery;
}

int main()
{
    int watermelon = 0, beetroot = 0, onion = 0;
    int amount = 0;
    char choice = 0;
    double w_price = 0, b_price = 0, o_price = 0;

back:
    print();
    while (choice != EOF)
        switch (choice = getchar())
        {
        case 'A':
            printf("Podaj ilość arbuzwów w kg:");
            scanf("%d", &amount);
            w_price += price(amount, W);
            watermelon += amount;
            goto back;
        case 'B':
            printf("Podaj ilość buraków w kg:");
            scanf("%d", &amount);
            b_price += price(amount, B);
            beetroot += amount;
            goto back;
        case 'C':
            printf("Podaj ilość cebuli w kg:");
            scanf("%d", &amount);
            o_price += price(amount, O);
            onion += amount;
            goto back;
        case 'K':
            choice = EOF;
            break;
        }

    printf("Podsumowanie:\n");
    printf("Cana produktów: arbuzy 1,25 zl/kg \tB buraki 0,65 zl/kg \tC cebula 0,89 zl/kg\n");
    printf("Zamowiles: arbuzow: %d kg cena: %g zl, burakow: %d kg cena: %g zl, cebuli: %d kg cena: %g zl\n", watermelon, w_price, beetroot, b_price, onion, o_price);
    double sum = w_price + b_price + o_price;
    double dis = discount(sum);
    double delivery = deliver(watermelon + onion + beetroot);
    printf("Opłaty %g, naliczony rabat: %g % , koszt wysyłki:%g, co zapłaty: %g\n", sum, dis, delivery, results(sum, dis, delivery));

    return 0;
}