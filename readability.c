#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int letters = 0;
int words = 0;
int sentences = 0;
int count_letters(string letras);
int count_words(string palabras);
int count_sentences(string oraciones);
string text;

int main(void)
{
    text = get_string("Text: ");

    //Aca uso funciones para contar las distintas variables

    count_letters(text);
    count_words(text);
    count_sentences(text);

    //printf("Letras: %i\n", letters);
    //printf("Oraciones: %i\n", sentences);
    //printf("Palabras: %i\n", words);


    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    float grade = 0.0588 * L - 0.296 * S - 15.8;

    if (round(grade) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (round(grade) >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(grade));
    }

}

int count_letters(string letras)
{
    for (int i = 0, n = strlen(text); i < n; i++)

        //Letras esta comprendido entre a y z, y entre A y Z
        if ((text [i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters ++;
        }

    return letters;
}

int count_words(string palabras)
{
    for (int i = 0, n = strlen(text); i < n + 1; i++)

        //Palabras son letras seguidas por espacios o signos de puntuacion
        if (((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) && (text[i + 1] == ' ' || text[i + 1] == '.' ||
                text[i + 1] == ',' || text[i + 1] == ';' || text[i + 1] == '?' || text[i + 1] == '!'))
        {
            words ++;
        }

    return words;
}

int count_sentences(string oraciones)
{
    for (int i = 0, n = strlen(text); i < n + 1; i++)

        //Oraciones son arrays que empiezan '.', '?' y '!'
        if ((text [i] == '.' || text[i] == '?' || text[i] == '!'))

        {
            sentences ++;
        }

    return sentences;


}
