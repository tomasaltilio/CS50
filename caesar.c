//Cifrado de Caesar: Corremos el programa con una key que es la que hace que se cambien las letras esa cantidad de veces

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int key;
string text;
char c;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //Loop que chequea que solo pongamos numeros
        for (int i = 0, n = strlen(argv [1]); i < n; i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        key = atoi(argv[1]);
        text = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int i = 0, n = strlen(text); i < n; i++)
        {
            if (isalpha(text[i]) != 0)
            {
                if (isupper(text[i]) != 0)
                {
                    //Para que la formula funcione hay que convertir el ASCII a una escala del 0 al 25, para que no se vaya del rango de letras.
                    //Por eso le restamos 65 (el valor para A) y despues se lo volvemos a sumar para convertir otra vez a ASCII.
                    c = ((text[i] - 65 + key) % 26) + 65;
                    printf("%c", c);
                }
                else if (isupper(text[i]) == 0)
                {
                    //Para que la formula funcione hay que convertir el ASCII a una escala del 0 al 25, para que no se vaya del rango de letras.
                    //Por eso le restamos 65 (el valor para a) y despues se lo volvemos a sumar para convertir otra vez a ASCII.
                    c = ((text[i] - 97 + key) % 26) + 97;
                    printf("%c", c);
                }
            }
            else
            {
                printf("%c", text[i]);
            }
        }
        printf("\n");

    }

    return 0;
}
