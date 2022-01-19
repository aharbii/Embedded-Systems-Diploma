#ifndef _ARRAY_H_
#define _ARRAY_H_

#define ARRAY_SIZE(array) sizeof((array)) / sizeof((array)[0])

void array_print(int *array_ptr, int size);
int array_search(int *array_ptr, int size, int to_find);
void array_print_primes(int *array_ptr, int size);
int array_delete_prime(int *array_ptr, int size);
void array_scan(int *array_ptr, int size);
int array_find_last(int *array_ptr, int size, int to_find);
void array_get_max_min(int *array_ptr, int size, int max_min[2][2]);
int array_between(int a, int b, int *array_ptr);
void array_print_2d(int *array_ptr, int rows, int cols);
int array_most_repeated(int *array, const int size);
void array_reverse(int *array, int size);
void array_swap(int *first_array, int *first_size, int *second_array, int *second_size);
void array_pop(int *arr, int *size);
void array_append(int *arr, int *size, int x);
int array_longest_consecutive(int *array, int size, int number);
void array_most_repeated_consecutive(int *array, int size, int *value, int *repeats);
void merge_array(int *first_array, int first_size, int *second_array, int second_size, int *merged, int *merged_size);

#endif