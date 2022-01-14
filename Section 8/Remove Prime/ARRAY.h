#ifndef _ARRAY_H_
#define _ARRAY_H_

#define ARRAY_SIZE(array) sizeof((array))/ sizeof((array)[0])


void array_print(int *array_ptr, int size);
int array_search(int *array_ptr, int size, int to_find);
void array_print_primes(int *array_ptr, int size);
int array_delete_prime(int *array_ptr, int size);
int array_scan(int *array_ptr, int size);

#endif