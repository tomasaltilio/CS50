#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    int cents, coins;
    do
    {
        dollars = get_float("Change owed:");
    }
    while (dollars < 0);

    //Pasar dollars a cents para evitar la impresicion por float
    //Contador de monedas que se necesitan para dar cambio
    cents = round(dollars * 100);
    coins = 0;

    //El loop se hace con while porque no necesitas inventar variables para que funcione
    while (cents >= 25)
    {
        coins ++;
        cents = cents - 25;
    }
    while (cents >= 10)
    {
        coins++;
        cents = cents - 10;
    }
    while (cents >= 5)
    {
        coins++;
        cents = cents - 5;
    }
    while (cents >= 1)
    {
        coins++;
        cents = cents - 1;
    }

    //Tira la cantidad de monedas que necesito
    printf("%i\n", coins);
}
