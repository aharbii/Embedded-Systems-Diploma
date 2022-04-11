/******************************************************************************
 * FILE: STRINGS.h
 * DESCRIPTION:  C header file contains declration and documentation
 *               for the functions for STRINGS.c that perform operations on
 *               strings and characters.
 *
 *              Queries:
 *                  CHAR:
 *                      --> Is Digit
 *                      --> Is Lower Case
 *                      --> Is Upper Case
 *                      --> Is Letter
 *                      --> Is Vowel
 *                      --> Is Consonant
 *                  STRING:
 *                      --> Print String
 *                      --> Is Valid (Letters and Digits)
 *                      --> Is Palindrome
 *                      --> Two Strings are Anagram
 *                      --> Get Length
 *                      --> Count Vowels and Consonents
 *                      --> Compare Two Strings
 *                      --> Print Duplicates
 *                      --> Print Permutation
 *                      --> Find Substring
 *
 *              Manipulations:
 *                  CHAR:
 *                      --> To Lower
 *                      --> To Upper
 *                      --> Swap Two Characters
 *                  STRING:
 *                      --> Scan String
 *                      --> Letters To Lower
 *                      --> Letters To Upper
 *                      --> Toggle Letters
 *                      --> String Reverse
 *                      --> Reverse Words Order
 *                      --> Shift Word
 *                      --> String Copy
 *                      --> String to Integer
 *                      --> Is Lower Case
 *                      --> Replace Substring
 *                      --> String Separate
 *
 * AUTHOR: Ahmed Harbi
 * DATE: Jan 2022
 *****************************************************************************/

#ifndef _STRINGS_H_
#define _STRINGS_H_

#include <stdio.h>
#include <stdlib.h>

#include "ARRAY.h"
#include "BIT_MATH.h"
#include "MATH.h"
#include "SORTING.h"

#define LOWER_TO_UPPER_DIFF 'a' - 'A'
#define LOWER_ALPHA_START 'a'
#define UPPER_ALPHA_START 'A'
#define DIGIT_START '0'
#define ALPHABIT_COUNT 'z' - 'a' + 1
#define DIGIT_COUNT '9' - '0' + 1
#define MAX_ASCII 128
#define DECIMAL_BASE 10
#define FLOAT_PRECISION 6
#define ORDERIAL_NUMBER(NUMBER) ((NUMBER) == 1 ? "st" : (NUMBER) == 2 ? "nd" \
                                                    : (NUMBER) == 3   ? "rd" \
                                                                      : "th")

int char_is_digit(char c);
int char_is_lower(char c);
int char_is_upper(char c);
int char_is_alpha(char c);
int char_is_vowel(char c);
int char_is_consonant(char c);

int string_is_valid(char *s);
int string_is_palindrome(char *s);
int string_are_anagram(char *first_string, char *second_string);
int string_get_len(char *s);
void string_count_vowels_consonents(char *s);
int string_count_words(char *s);
int string_compare(char *first_string, char *second_string);
void string_print_duplicate(char *s);
void string_print_duplicate_hashing(char *s);
void string_print_duplicate_bitwise(char *s);
void string_print_permutation(char *s, int l, int h);
void string_print_permutation_recursive(char *s, int k);
void string_print(char *s);
int string_find(char *main_string, char *find);
void string_array_print(char **array_ptr, int size);

void char_to_lower(char *c);
void char_to_upper(char *c);
void char_swap(char *a, char *b);

void string_to_lower(char *s);
void string_to_upper(char *s);
void string_toggle(char *s);
void string_reverse(char *s);
void string_reverse_swap(char *s);
void string_reverse_words(char *s);
void string_scan(char *s, int size);
int string_shift_word(char *s, int length, int shift_position);
void string_copy(char *first_string, char *second_string);
void string_to_lengths(char *s, int *length_array);
int string_replace(char *main_string, char *find, char *replace);
int string_to_integer(char *s);
void string_separate(char *text, char text_separated[4][1000]);
void string_array_sort(char **array_ptr, int size);
void string_swap(char **first_ptr, char **second_ptr);

#endif /* _STRINGS_H_ */