#ifndef _STRINGS_H_
#define _STRINGS_H_

#define LOWER_TO_UPPER_DIFF 'a' - 'A'
#define LOWER_ALPHA_START 'a'
#define UPPER_ALPHA_START 'A'
#define DIGIT_START '0'
#define ALPHABIT_COUNT 'z' - 'a' + 1
#define DIGIT_COUNT '9' - '0' + 1
#define MAX_ASCII 128
#define DECIMAL_BASE 10
#define FLOAT_PRECISION 6



int char_is_digit(char c);
int char_is_lower(char c);
int char_is_upper(char c);
int char_is_alpha(char c);
int char_is_vowel(char c);
int char_is_consonant(char c);
void char_to_lower(char *c);
void char_to_upper(char *c);
int string_get_len(char *s);
void string_to_lower(char *s);
void string_to_upper(char *s);
void string_toggle(char *s);
int string_count_words(char *s);
int string_is_valid(char *s);
void string_count_vowels_consonents(char *s);
void string_reverse(char *s);
void char_swap(char *a, char *b);
void string_reverse_swap(char *s);
int string_compare(char *first_string, char *second_string);
int string_is_palindrome(char *s);
void string_print_duplicate(char *s);
void string_print_duplicate_hashing(char *s);
void string_print_duplicate_bitwise(char *s);
int string_are_anagram(char *first_string, char *second_string);
void string_print_permutation(char *s, int l, int h);
void string_print_permutation_recursive(char *s, int k);
void string_print(char *s);
void string_scan(char *s, int size);
void string_reverse_words(char *s);
int string_shift_word(char *s, int length, int shift_position);
void string_copy(char *first_string, char *second_string);
void string_to_lengths(char *s, int *length_array);
int string_find(char *main_string, char *find);
int string_replace(char *main_string, char *find, char *replace);
int string_to_integer(char *s);
void string_separate(char *text, char text_separated[4][1000]);

#endif