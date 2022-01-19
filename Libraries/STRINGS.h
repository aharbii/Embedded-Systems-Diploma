#ifndef _STRINGS_H_
#define _STRINGS_H_

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
void swap(char *a, char *b);
void string_reverse_swap(char *s);
int string_are_anagram(char *first_string, char *second_string);

#endif