#define LOWER_TO_UPPER_DIFF 'a' - 'A'
#define LOWER_ALPHA_START 'a'
#define UPPER_ALPHA_START 'A'
#define DIGIT_START '0'
#define ALPHABIT_COUNT 'z' - 'a' + 1
#define DIGIT_COUNT '9' - '0' + 1
#define MAX_ASCII 128
#define DECIMAL_BASE 10
#define FLOAT_PRECISION 6

int digits[DIGIT_COUNT] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

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

void string_copy(char *first_string, char *second_string)
{
    int i;
    for (i = 0; second_string[i] != '\0'; i++)
    {
        first_string[i] = second_string[i];
    }
    first_string[i] = '\0';
}

/******************************************************************************
 * Sheet.04
 *
 * Problem.00:
 *      --> String compare not case sensitive
 *
 * @author: Ahmed Harbi
 * @date:   Jan 29th, 2022
 ******************************************************************************/

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

/******************************************************************************
 * Sheet.04
 *
 * Problem.00:
 *      --> Strings are anagram "Listen" --> "Silent"
 *
 * @author: Ahmed Harbi
 * @date:   Jan 29th, 2022
 ******************************************************************************/

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

/******************************************************************************
 * Sheet.04
 *
 * Problem.01:
 *      --> Write c function to reverse string  "Ahmed salem"->melas demhA".
 *
 * @author: Ahmed Harbi
 * @date:   Jan 29th, 2022
 ******************************************************************************/

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

/******************************************************************************
 * Sheet.04
 *
 * Problem.02:
 *      --> Write c function to check if string is mirror or not "SalaS",
 *          "SalelaS".
 *
 * @author: Ahmed Harbi
 * @date:   Jan 29th, 2022
 ******************************************************************************/

int string_is_palindrome(char *s)
{
    int i = 0;
    int j = string_get_len(s) - 1;
    while (i < j)
    {
        char first_char = s[i++];
        char second_char = s[j--];

        char_to_lower(&first_char);
        char_to_lower(&second_char);

        if (first_char != second_char)
        {
            return 0;
        }
    }
    return 1;
}

/******************************************************************************
 * Sheet.04
 *
 * Problem.03:
 *      --> Write c function to reverse words in sentence
 *          (without using external arrays)
 *
 * @author: Ahmed Harbi
 * @date:   Jan 29th, 2022
 ******************************************************************************/

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

/******************************************************************************
 * Sheet.04
 *
 * Problem.04:
 *      --> Write C function to take string contain three numbers separated
 *          by space, check what type of triangle this number could make, and
 *          return string
 *          "12 23 21 "
 *          "Equilateral triangle "     "Isosceles triangle"
 *          "Scalene triangle"            "Not triangle"
 *
 * @author: Ahmed Harbi
 * @date:   Jan 29th, 2022
 ******************************************************************************/

void string_to_lengths(char *s, int *length_array)
{
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        int current_digit = 0;
        if (char_is_digit(s[i]))
        {
            current_digit = digits[s[i] - DIGIT_START];
            length_array[j] *= DECIMAL_BASE;
            length_array[j] += current_digit;
        }
        else
        {
            j++;
        }
    }
}

int triangle_is_valid(int *length_array)
{
    int a = length_array[0];
    int b = length_array[1];
    int c = length_array[2];

    if ((a + b > c) && (a + c > b) && (b + c > a))
    {
        return 1;
    }
    return 0;
}

void triangle_get_type(int *length_array, char *triangle_type)
{
    if (triangle_is_valid(length_array))
    {
        if ((length_array[0] == length_array[1]) && (length_array[1] == length_array[2]))
        {
            string_copy(triangle_type, "Equilateral triangle");
        }
        else if ((length_array[0] == length_array[1]) || (length_array[1] == length_array[2]) || (length_array[0] == length_array[2]))
        {
            string_copy(triangle_type, "Isosceles triangle");
        }
        else
        {
            string_copy(triangle_type, "Scalene triangle");
        }
    }
    else
    {
        string_copy(triangle_type, "Not a triangle");
    }
}

/******************************************************************************
 * Sheet.04
 *
 * Problem.05:
 *      --> Write a C function to convert float number to string
 *
 * @author: Ahmed Harbi
 * @date:   Jan 29th, 2022
 ******************************************************************************/

void float_to_string(double float_number, char *string_number)
{
    int integer_part = float_number;
    double float_part = float_number - integer_part;

    int len = 0;
    if (integer_part == 0)
    {
        string_number[0] = '0';
        len++;
    }

    while (integer_part)
    {
        int current_digit = integer_part % DECIMAL_BASE;
        int i;
        len++;
        for (i = len; i >= 0; i--)
        {
            string_number[i + 1] = string_number[i];
        }
        string_number[i + 1] = current_digit + '0';
        integer_part /= DECIMAL_BASE;
    }

    string_number[len] = '.';

    int precision = FLOAT_PRECISION;
    while (precision > 0)
    {
        float_part *= DECIMAL_BASE;
        precision--;
    }
    int float_part_as_integer = (int)float_part;

    while (float_part_as_integer)
    {
        int current_digit = float_part_as_integer % DECIMAL_BASE;
        int i;
        len++;
        for (i = len; string_number[i] != '.'; i--)
        {
            string_number[i + 1] = string_number[i];
        }
        string_number[i + 1] = current_digit + '0';
        string_number[len] = '\0';
        float_part_as_integer /= DECIMAL_BASE;
    }
}

/******************************************************************************
 * Sheet.04
 *
 * Problem.06:
 *      --> Write a C function to take 3 strings, “main string”, “find”, and
 *          “replace”, if you find the second string inside the first one
 *          replaces it with the third and return new string, if u didn’t find
 *          it return the first string without change Main
 *          string->”ahmed mohamed ali kamel”.
 *          Find->”ali”.
 *          Replace->”ayman”.
 *          Return new string ->”ahmed mohamed ayman kamel”.
 *
 * @author: Ahmed Harbi
 * @date:   Jan 29th, 2022
 ******************************************************************************/

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

/******************************************************************************
 * Sheet.04
 *
 * Problem.07:
 *      --> Write a C code to take string “hi,5,hello,12” and print the first 
 *          word number of times as the first number ,and second word as the 
 *          second number.
 * 
 * @author: Ahmed Harbi
 * @date:   Jan 29th, 2022
 ******************************************************************************/

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
    int j = 0;
    int value = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        int current_digit = 0;
        if (char_is_digit(s[i]))
        {
            current_digit = digits[s[i] - DIGIT_START];
            value *= DECIMAL_BASE;
            value += current_digit;
        }
        else
        {
            j++;
        }
    }
    return value;
}

int main()
{
    char text[] = "hi,5,hello,12";
    char text_separated[4][1000] =
        {
            {0},
            {0},
            {0},
            {0}};
    string_separate(text, text_separated);

    int first_times = string_to_integer(text_separated[1]);
    int second_times = string_to_integer(text_separated[3]);

    for (int i = 0; i < first_times; i++)
    {
        printf("[%d] %s\n", i + 1, text_separated[0]);
    }

    for (int i = 0; i < second_times; i++)
    {
        printf("[%d] %s\n", i + 1, text_separated[2]);
    }

    return 0;
}