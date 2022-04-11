/******************************************************************************
 * FILE: SORTING.h
 * DESCRIPTION:  C header file contains declration and documentation
 *               for the functions for SORTING.c that perform sorting algorithms.
 *
 *              O(N^2):
 *                  --> Bubble Sorting
 *                  --> Insertion Sorting
 *                  --> Selection Sorting
 *
 *              O(nlog(n)):
 *                  --> Quick Sorting
 *                  --> Heap Sorting
 *                  --> Merge Sorting
 *                  --> Shell Sorting
 *
 *              O(n+k):
 *                  --> Count Sorting
 *                  --> Radix Sorting
 *                  --> Bucket Sorting
 *
 * AUTHOR: Ahmed Harbi
 * DATE: Jan 2022
 *****************************************************************************/

#ifndef _SORTING_H_
#define _SORTING_H_

#include <stdio.h>
#include <stdlib.h>

#include "ARRAY.h"
#include "BIT_MATH.h"
#include "MATH.h"
#include "STRINGS.h"

void bubble_sort(int *array_ptr, int size);
void insertion_sort(int *array_ptr, int size);
void selection_sort(int *array_ptr, int size);

void quick_sort(int *array_ptr, int size);
void heap_sort(int *array, int size);
void merge_sort(int *array_ptr, int size);
void shell_sort(int *array_ptr, int size);

void count_sort(int *array_ptr, int size);
void bucket_sort(int *array_ptr, int size);
void radix_sort(int *array_ptr, int size);

#endif /* _SORTING_H_ */