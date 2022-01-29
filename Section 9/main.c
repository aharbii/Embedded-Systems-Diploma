#include <stdio.h>
#include <stdlib.h>

#define LOWER_TO_UPPER_DIFF 'a' - 'A'

int string_get_len(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

void string_reverse(char *s)
{
    char c[10000];
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

void string_print(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}

void string_scan(char *s, int size)
{
    printf("Enter string, maximum length is %d: ", size);
    int i = 0;
    do 
    {
        scanf("%c", &s[i]);
    } while(s[i++] != '\n');
    s[i] = '\0';
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

void string_to_lower(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        char_to_lower(&s[i]);
    }
}

int string_compare(char *first_string, char *second_string)
{
    int i;
    for (i = 0; (first_string[i] != '\0') && (second_string[i] != '\0'); i++)
    {
        if (first_string[i] != second_string[i])
        {
            return 0;
        }
    }

    if (first_string[i] || second_string[i])
    {
        return 0;
    }

    return 1;
}

int main()
{
    char text[1000] = {0};
    string_scan(text, 1000);
    string_print(text);
    return 0;
}