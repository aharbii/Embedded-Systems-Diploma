#include <stdio.h>
#include <stdlib.h>
#include "MATH.h"
#include "ARRAY.h"

int get_power(int base, int exponent)
{
    int power = 1;
    for (int i = 0; i < exponent; i++)
    {
        power *= base;
    }
    return power;
}

int is_prime(int number)
{
    int is_prime = 1;
    for (int i = 2; (i < number) && (is_prime); i++)
    {
        if ((number % i) == 0)
        {
            is_prime = 0;
        }
    }

    if ((number == 0) || (number == 1))
    {
        is_prime = 0;
    }

    return is_prime;
}

void swap_int(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int is_powerof_three(int number)
{
    int reminder = 0;
    while (number > 1)
    {
        reminder = number % 3;
        number /= 3;
    }

    if ((reminder == 0) && (number != 0))
    {
        return 1;
    }

    return 0;
}

int sum_formula(int n)
{
    /* O(1) */
    int sum = (n * (n + 1)) / 2;
    return sum;
}

void swap_ptr(int **first_ptr, int **second_ptr)
{
    int *temp = *first_ptr;
    *first_ptr = *second_ptr;
    *second_ptr = temp;
}

int fibonacci_iter(int n)
{
    /* O(n) */
    int t0 = 0;
    int t1 = 1;
    if (n <= 1)
    {
        return n;
    }
    int s = 0;
    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}
