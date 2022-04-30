/******************************************************************************
 * FILE: MATH.h
 * DESCRIPTION:  C header file contains declration and documentation
 *               for the functions for MATH.c that perform mathematical
 *               operations.
 *
 *              Queries:
 *                  --> Is Power of Two
 *                  --> Is Power of Three
 *                  --> Is Prime
 *
 *              Manipulations:
 *                  --> Swapping Two Integers
 *                  --> Swapping Two Pointers
 *
 *                  --> Power
 *                  --> Summation
 *                  --> Get Fibonacci of Integer
 *                  --> Reversing an Integer
 *
 * AUTHOR: Ahmed Harbi
 * DATE: Jan 2022
 *****************************************************************************/

#ifndef _MATH_H_
#define _MATH_H_

#include <stdio.h>
#include <stdlib.h>

#include "ARRAY.h"
#include "BIT_MATH.h"
#include "SORTING.h"
#include "STRINGS.h"

#define SIZE_OF(x) (char *)(&(x) + 1) - (char *)&(x)

int is_power_of_three(int number);
int is_prime(int number);

void swap_int(int *x, int *y);
void swap_ptr(int **first_ptr, int **second_ptr);

int get_power(int base, int exponent);
int sum_formula(int n);
int fibonacci_iter(int n);
int reverse_int(int x);

#endif /* _MATH_H_ */