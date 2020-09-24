// Substitution: Cifrado donde se pone la clave en el commandline de acuerdo al orden que se le da a
// las 26 letras. El lugar que ocupa cada letra es la letra que representa.

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string text;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    else
    {
        //Loop que chequea que solo pongamos letras
        for (int i = 0; i < 25; i++)
        {
            if (isalpha(argv[1][i]) == false)
            {
                printf("Key must be alphabetical\n");
                return 1;
            }
        }
        //Loop para que ninguna letra dentro de la key se repita
        for (int i = 0; i < 25; i++)
        {
            for (int j = 1 + i; j < 26; j++)
            {
                if (tolower(argv[1][i]) == tolower(argv[1][j]))

                {
                    printf("Values in the key must be different to each other\n");
                    return 1;
                }
            }
        }
    }


    text = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (!isalpha(text[i]))
        {
            printf("%c", text[i]);
        }

// Quiero que me busque la primera letra de text y la compare con el lugar que ocupa entre las 26
// de la key.
// Para eso hay que pasar del codigo ASCII al rango de 0 a 25, y despues usar el array de la key para
// ubicar la letra que corresponderia.

        else if (isupper(text[i]))
        {
            text[i] = toupper(argv[1][text[i] - 65]);
            printf("%c", text[i]);
        }

        else if (islower(text[i]))
        {
            text[i] = tolower(argv[1][text[i] - 97]);
            printf("%c", text[i]);
        }
    }

    printf("\n");
    return 0;
}
