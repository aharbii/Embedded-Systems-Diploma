#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include "STRINGS.h"
#include "ARRAY.h"
#include "MATH.h"

void bubble_sort(int *array_ptr, int size);
void insertion_sort(int *array_ptr, int size);
void selection_sort(int *array_ptr, int size);
void quick_sort(int *array_ptr, int size);
void merge_sort(int *array_ptr, int size);
void count_sort(int *array_ptr, int size);
void bucket_sort(int *array_ptr, int size);
void radix_sort(int *array_ptr, int size);
void shell_sort(int *array_ptr, int size);

#endif