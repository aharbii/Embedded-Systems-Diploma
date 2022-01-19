#include <stdio.h>
#include <stdlib.h>

#define LOWER_TO_UPPER_DIFF 'a' - 'A'
#define LOWER_CHAR_START 97

int char_is_digit(char c)
{
    if ((c >= '0') && (c <= '9'))
    {
        return 1;
    }
    return 0;
}

int char_is_lower(char c)
{
    if ((c >= 'a') && (c <= 'z'))
    {
        return 1;
    }
    return 0;
}

int char_is_upper(char c)
{
    if ((c >= 'A') && (c <= 'Z'))
    {
        return 1;
    }
    return 0;
}

int char_is_alpha(char c)
{
    if (char_is_lower(c) || char_is_upper(c))
    {
        return 1;
    }
    return 0;
}

int char_is_vowel(char c)
{
    if (char_is_lower(c))
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return 1;
        }
    }
    else if (char_is_upper(c))
    {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            return 1;
        }
    }
    return 0;
}

int char_is_consonant(char c)
{
    if (char_is_alpha(c) && !char_is_vowel(c))
    {
        return 1;
    }
    return 0;
}

void char_to_lower(char *c)
{
    if (char_is_upper(*c))
    {
        *c += LOWER_TO_UPPER_DIFF;
    }
}

void char_to_upper(char *c)
{
    if (char_is_lower(*c))
    {
        *c -= LOWER_TO_UPPER_DIFF;
    }
}

int string_get_len(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

void string_to_lower(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        char_to_lower(&s[i]);
    }
}

void string_to_upper(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        char_to_upper(&s[i]);
    }
}

void string_toggle(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (char_is_lower(s[i]))
        {
            char_to_upper(&s[i]);
        }
        else if (char_is_upper(s[i]))
        {
            char_to_lower(&s[i]);
        }
    }
}

int string_count_words(char *s)
{
    int words = 1;
    for (int i = 1; s[i] != '\0'; i++)
    {
        if ((s[i] == ' ') && s[i - 1] != '\0')
        {
            words++;
        }
    }

    return words;
}

int string_is_valid(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((!char_is_alpha(s[i])) && (!char_is_digit(s[i])))
        {
            return 0;
        }
    }
    return 1;
}

void string_count_vowels_consonents(char *s)
{
    int vowels = 0;
    int consonants = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (char_is_vowel(s[i]))
        {
            vowels++;
        }
        else if (char_is_consonant(s[i]))
        {
            consonants++;
        }
    }
    printf("Vowels = %d\n", vowels);
    printf("Consonants = %d\n", consonants);
}

void string_reverse(char *s)
{
    char c[100];
    int j = 0;
    int i = string_get_len(s) - 1;
    while (s[i] != '\0')
    {
        c[j++] = s[i--];
    }
    c[j] = '\0';
    for (int i = 0; c[i] != '\0'; i++)
    {
        s[i] = c[i];
    }
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void string_reverse_swap(char *s)
{
    int j = string_get_len(s) - 1;
    for (int i = 0; i < j; i++, j--)
    {
        swap(&s[i], &s[j]);
    }
}

int string_are_anagram(char *first_string, char *second_string)
{
    int first_len = string_get_len(first_string);
    int second_len = string_get_len(second_string);

    if (first_len != second_len)
    {
        return 0;
    }

    int hash_table[26] = {0};
    for (int i = 0; first_string[i] != '\0'; i++)
    {
        hash_table[first_string[i] - LOWER_CHAR_START] += 1;
    }

    for (int i = 0; second_string[i] != '\0'; i++)
    {
        hash_table[second_string[i] - LOWER_CHAR_START] -= 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (hash_table[i] > 0)
        {
            return 0;
        }
    }

    return 1;
}
