#include <stdio.h>
#include <stdlib.h>
#include "STRINGS.h"

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
    s[j] = '\0';
}

void char_swap(char *a, char *b)
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
        char_swap(&s[i], &s[j]);
    }
}

int string_compare(char *first_string, char *second_string)
{
    int i = 0;
    while ((first_string[i] != '\0') && (second_string[i] != '\0'))
    {
        char first_char = first_string[i];
        char second_char = second_string[i];

        char_to_lower(&first_char);
        char_to_lower(&second_char);

        if (first_char != second_char)
        {
            return 0;
        }

        i++;
    }
    if (first_string[i] || second_string[i])
    {
        return 0;
    }
    return 1;
}

int string_is_palindrome(char *s)
{
    int i = 0;
    int j = string_get_len(s) - 1;
    while (i < j)
    {
        if (s[i++] != s[j--])
        {
            return 0;
        }
    }
    return 1;
}

void string_print_duplicate(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        char first_char = s[i];
        char_to_lower(&first_char);

        for (int j = (i + 1); s[j] != '\0'; j++)
        {
            char second_char = s[j];
            char_to_lower(&second_char);

            if (first_char == second_char)
            {
                printf("%c, ", s[j]);
            }
        }
    }
    printf("\n");
}

void string_print_duplicate_hashing(char *s)
{
    int hash_table[ALPHABIT_COUNT] = {0};
    for (int i = 0; s[i] != '\0'; i++)
    {
        char current_char = s[i];
        char_to_lower(&current_char);
        hash_table[current_char - LOWER_ALPHA_START] += 1;
    }

    for (int i = 0; i < ALPHABIT_COUNT; i++)
    {
        if (hash_table[i] > 1)
        {
            printf("%c --> %d, ", (i + LOWER_ALPHA_START), hash_table[i]);
        }
    }

    printf("\n");
}

void string_print_duplicate_bitwise(char *s)
{
    int hash_values = 0;
    int bit_setter = 1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char current_char = s[i];
        char_to_lower(&current_char);

        int index = current_char - LOWER_ALPHA_START;
        int bit_state = (hash_values & (bit_setter << index)) >> index;
        if (bit_state == 1)
        {
            printf("%c, ", s[i]);
        }
        else
        {
            hash_values |= bit_setter << index;
        }
    }
    printf("\n");
}

int string_are_anagram(char *first_string, char *second_string)
{
    int first_len = string_get_len(first_string);
    int second_len = string_get_len(second_string);

    if (first_len != second_len)
    {
        return 0;
    }

    int hash_table[ALPHABIT_COUNT] = {0};
    for (int i = 0; first_string[i] != '\0'; i++)
    {
        if (char_is_lower(first_string[i]))
        {
            hash_table[first_string[i] - LOWER_ALPHA_START] += 1;
        }
        else if (char_is_upper(first_string[i]))
        {
            hash_table[first_string[i] - UPPER_ALPHA_START] += 1;
        }
    }

    for (int i = 0; second_string[i] != '\0'; i++)
    {
        if (char_is_lower(first_string[i]))
        {
            hash_table[first_string[i] - LOWER_ALPHA_START] -= 1;
        }
        else if (char_is_upper(first_string[i]))
        {
            hash_table[first_string[i] - UPPER_ALPHA_START] -= 1;
        }
    }

    for (int i = 0; i < ALPHABIT_COUNT; i++)
    {
        if (hash_table[i] > 0)
        {
            return 0;
        }
    }

    return 1;
}

void string_print_permutation(char *s, int l, int h)
{
    if (l == h)
    {
        printf("%s\n", s);
    }
    else
    {
        for (int i = l; s[i] != '\0'; i++)
        {
            char_swap(&s[l], &s[i]);
            string_print_permutation(s, l + 1, h);
            char_swap(&s[l], &s[i]);
        }
    }
}

void string_print_permutation_recursive(char *s, int k)
{
    static int A[10] = {0};
    static char res[10];
    if (s[k] == '\0')
    {
        res[k] = '\0';
        printf("%s\n", s);
    }
    else
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                res[k] = s[i];
                A[i] = 1;
                string_print_permutation_recursive(s, k + 1);
                A[i] = 0;
            }
        }
    }
}

void string_scan(char *s, int size)
{
    printf("Enter string, maximum length is %d: ", size);
    int i = 0;
    do
    {
        scanf("%c", &s[i]);
    } while (s[i++] != '\n');
    s[i - 1] = '\0';
}

void string_print(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}

int string_shift_word(char *s, int length, int shift_position)
{
    int i = length;
    char terminator = ' ';
    int counter = shift_position;
    do
    {
        char char_to_shift = s[i];
        counter++;
        for (int j = i; j >= shift_position; j--)
        {
            s[j + 1] = s[j];
        }
        s[shift_position] = char_to_shift;
    } while (s[i] != terminator);
    shift_position = counter;
    return shift_position;
}

void string_reverse_words(char *s)
{
    int string_length = string_get_len(s);
    int word_count = string_count_words(s);
    s[string_length] = ' ';
    s[string_length + 1] = '\0';
    int shift_position = 0;
    while (word_count > 1)
    {
        shift_position = string_shift_word(s, string_length, shift_position);
        word_count--;
    }

    s[string_length] = '\0';
}

void string_to_lengths(char *s, int *length_array)
{
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        int current_digit = 0;
        if (char_is_digit(s[i]))
        {
            current_digit = s[i] - DIGIT_START;
            length_array[j] *= DECIMAL_BASE;
            length_array[j] += current_digit;
        }
        else
        {
            j++;
        }
    }
}

void string_copy(char *first_string, char *second_string)
{
    int i;
    for (i = 0; second_string[i] != '\0'; i++)
    {
        first_string[i] = second_string[i];
    }
    first_string[i] = '\0';
}

int string_find(char *main_string, char *find)
{
    int index = -1;
    int j = 0;
    int find_len = string_get_len(find);
    for (int i = 0; main_string[i] != '\0'; i++)
    {
        char in_word = main_string[i];
        char to_compare = find[j];

        char_to_lower(&in_word);
        char_to_lower(&to_compare);

        if (in_word == to_compare)
        {
            j++;
            if (j == find_len)
            {
                index = i - find_len + 1;
                return index;
            }
        }
        else
        {
            j = 0;
        }
    }
    return index;
}

int string_replace(char *main_string, char *find, char *replace)
{
    int main_len = string_get_len(main_string);
    int find_len = string_get_len(find);
    int replace_len = string_get_len(replace);

    int replace_index = string_find(main_string, find);
    int diff = replace_len - find_len;

    if (replace_index >= 0)
    {
        if (diff > 0)
        {
            for (int i = main_len; i >= replace_index; i--)
            {
                main_string[i + diff] = main_string[i];
            }
        }
        else if (diff < 0)
        {
            diff *= -1;
            for (int i = replace_index; i <= (main_len - diff); i++)
            {
                main_string[i] = main_string[i + diff];
            }
        }

        int j = 0;
        int i = replace_index;

        while (i < (replace_len + replace_index))
        {
            main_string[i++] = replace[j++];
        }
        return 1;
    }
    return 0;
}

void string_separate(char *text, char text_separated[4][1000])
{
    char terminator = ',';
    int j = 0;
    int k = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == terminator)
        {
            text_separated[j][k] = '\0';
            k = 0;
            j++;
        }
        else
        {
            text_separated[j][k++] = text[i];
        }
    }
}

int string_to_integer(char *s)
{
    int value = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        int current_digit = 0;
        if (char_is_digit(s[i]))
        {
            current_digit = s[i] - DIGIT_START;
            value *= DECIMAL_BASE;
            value += current_digit;
        }
    }
    return value;
}