#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include "MATH.h"
#include "SORTING.h"
#include "STRINGS.h"

#define ARRAY_SIZE(array) sizeof((array)) / sizeof((array)[0])

void array_print(const int *array_ptr, const int *size);
void matrix_print_2d(const int *array_ptr, const int *rows, const int *cols);
int array_scan(int *array_ptr, int *size);
int array_get_index_first(const int *array_ptr, const int *size, int key);
int array_get_index_last(const int *array_ptr, const int *size, int key);
void array_get_max_min(const int *array_ptr, const int *size, int max_min[2][2]);
int array_get_between(int a, int b, int *array_ptr);
void array_print_primes(const int *array_ptr, const int *size);
int array_get_most_repeated(const int *array_ptr, const int *size);
void array_reverse(int *array_ptr, const int *size);
void array_reverse_swap(int *array_ptr, const int *size);
void array_append(int *array_ptr, int *size, const int key);
void array_pop(int *array_ptr, int *size);
int array_delete(int *array_ptr, int *size, int index);
int array_delete_primes(int *array_ptr, int *size);
void array_swap(int *first_array, int *first_size, int *second_array, int *second_size);
int array_longest_consecutive(int *array_ptr, int *size, int number);
void array_most_repeated_consecutive(int *array_ptr, int *size, int *value, int *repeats);
void array_merge(int *first_array, int first_size, int *second_array, int second_size, int *merged, int *merged_size);
void array_insert(int *array_ptr, int *size, int index, int key);
int array_linear_search(const int *array_ptr, const int *size, int key);
int array_improved_linear_search(int *array_ptr, int *size, int key);
int array_binary_search(const int *array_ptr, const int *size, int key);
int array_binary_search_recursive(const int *array_ptr, const int *size, int l, int h, int key);
int array_at(const int *array_ptr, const int *size, int index);
void array_set(int *array_ptr, int *size, int index, int key);
int array_get_max(const int *array_ptr, const int *size);
int array_get_min(const int *array_ptr, const int *size);
int array_get_sum(const int *array_ptr, const int *size);
int array_get_sum_recursive(const int *array_ptr, const int *size, int n);
double array_get_average(const int *array_ptr, const int *size);
void array_insert_sorted(int *array_ptr, int *size, int value);
int array_is_sorted(int *array_ptr, int *size);
void array_rearrange(int *array_ptr, int *size);
void array_union(const int *first_array, const int *first_size, const int *second_array, const int *second_size, int *array_ptr, int *size);
void array_union_sorted(const int *first_array, const int *first_size, const int *second_array, const int *second_size, int *array_ptr, int *size);
void array_intersection(const int *first_array, const int *first_size, const int *second_array, const int *second_size, int *array_ptr, int *size);
void array_intersection_sorted(const int *first_array, const int *first_size, const int *second_array, const int *second_size, int *array_ptr, int *size);
void array_difference(const int *first_array, const int *first_size, const int *second_array, const int *second_size, int *array_ptr, int *size);
void array_difference_sorted(const int *first_array, const int *first_size, const int *second_array, const int *second_size, int *array_ptr, int *size);
int array_get_sum_sequence(const int *array_ptr, const int *size);
int array_get_missing_sorted(const int *array_ptr, const int *size);
int array_get_missing_diff(const int *array_ptr, const int *size);
void array_get_missing_unsorted(const int *array_ptr, const int *size);
void array_get_duplicate_sorted(const int *array_ptr, const int *size);
void array_get_duplicate_hash(const int *array_ptr, const int *size);
void array_pair_with_sum(const int *array_ptr, const int *size, int sum);
void array_pair_with_sum_hashing(const int *array_ptr, const int *size, int sum);
void array_pair_with_sum_sorted(const int *array_ptr, const int *size, int sum);
void array_remove_duplicate_sorted(int *array_ptr, int *size);
void array_swap_after_zero(int *array_ptr);
int array_get_greatest_difference(const int *array_ptr, const int *size);
int array_get_max_index(const int *array_ptr, const int *size);
char array_get_most_repeated_character(const char *array_ptr, const int *size);
int array_get_most_repeated_mono(const int *array_ptr, const int *size);

#endif