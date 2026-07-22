#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(char text[]);
int count_words(char text[]);
int count_sentences(char text[]);

int main(void)
{
    char text[1000];

    // Read input text from user
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    // Calculate letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Coleman-Liau index calculation
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print result according to grade level
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
        printf("Grade %d\n", index);
    }

    return 0;
}

int count_letters(char text[])
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(char text[])
{
    int count = 0;
    int in_word = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            in_word = 1;
            count++;
        }
    }
    return count;
}

int count_sentences(char text[])
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
