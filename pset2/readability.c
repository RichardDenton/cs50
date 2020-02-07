#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int get_letter_count(string text);
int get_word_count(string text);
int get_sentence_count(string text);
int get_grade(int letter_count, int word_count, int sentence_count);

int main(void)
{
    string text = get_string("Text: ");

    int index = get_grade(get_letter_count(text), get_word_count(text), get_sentence_count(text));

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int get_letter_count(string text)
{
    int letter_count = 0;

    for (int i = 0, j = strlen(text); i < j; i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
    }
    return letter_count;
}

int get_word_count(string text)
{
    int word_count = 0;

    if (strlen(text) > 0)
    {
        word_count++;
    }

    for (int i = 0, j = strlen(text); i < j; i++)
    {
        if (text[i] == ' ')
        {
            word_count++;
        }
    }
    return word_count;
}

int get_sentence_count(string text)
{
    int sentence_count = 0;

    for (int i = 0, j = strlen(text); i < j; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
    }
    return sentence_count;
}

int get_grade(int letter_count, int word_count, int sentence_count)
{
    float L = ((float) letter_count / word_count) * 100;
    float S = ((float) sentence_count / word_count) * 100;
    return round((float) 0.0588 * L - 0.296 * S - 15.8);
}