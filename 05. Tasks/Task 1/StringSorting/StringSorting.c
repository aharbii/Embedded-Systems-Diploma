#include <stdio.h>
#include <stdlib.h>

#define LOWER_TO_UPPER_DIFF 'a' - 'A'
#define FIRST_BIGGER 1
#define SECOND_BIGGER -1
#define STRING_EQUAL 0

void swap_string(char **first_ptr, char **second_ptr)
{
    char *temp = *first_ptr;
    *first_ptr = *second_ptr;
    *second_ptr = temp;
}

int char_is_upper(char c)
{
    if ((c >= 'A') && (c <= 'Z'))
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
            if (first_char > second_char)
            {
                return FIRST_BIGGER;
            }
            else
            {
                return SECOND_BIGGER;
            }
        }

        i++;
    }
    if (first_string[i] || second_string[i])
    {
        if (first_string[i])
        {
            return FIRST_BIGGER;
        }
        else
        {
            return SECOND_BIGGER;
        }
    }
    return STRING_EQUAL;
}

void string_print(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}

void string_array_sort(char **array_ptr, int size)
{
    int not_sorted = 1;
    for (int i = 1; i < size && not_sorted; i++)
    {
        not_sorted = 0;
        for (int j = 0; j < size - i; j++)
        {
            if (string_compare(array_ptr[j], array_ptr[j + 1]) == FIRST_BIGGER)
            {
                swap_string(&array_ptr[j], &array_ptr[j + 1]);
                not_sorted = 1;
            }
        }
    }
}

void string_array_print(char **array_ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        string_print(array_ptr[i]);
    }
}

int main()
{
    char *arr[10] = {"Embedded", "Systems", "Ahmed", "Harbi", "Hello", "Computer", "Software Development", "Engineering", "ATmega32", "C Programming"};
    string_array_sort(arr, 10);
    string_array_print(arr, 10);
    return 0;
}