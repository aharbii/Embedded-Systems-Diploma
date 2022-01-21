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

void swap(int *a, int *b)
{
    *b += *a;
    *a = *b - *a;
    *b = *b - *a;
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
    int s;
    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int get_most_repeated_mono(void)
{
    int zero = 0;
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;
    int six = 0;
    int seven = 0;
    int eight = 0;
    int nine = 0;

    int max = 0;
    printf("Enter 10 mono numbers (0 -> 9): ");
    int n = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &n);

        switch (n)
        {
        case 0:
            zero++;
            if (zero > max)
                max = zero;
            break;
        case 1:
            one++;
            if (one > max)
            {
                max = one;
            }
            break;
        case 2:
            two++;
            if (two > max)
            {
                max = two;
            }
            break;
        case 3:
            three++;
            if (three > max)
            {
                max = three;
            }
            break;
        case 4:
            four++;
            if (four > max)
            {
                max = four;
            }
            break;
        case 5:
            five++;
            if (five > max)
            {
                max = five;
            }
            break;
        case 6:
            six++;
            if (six > max)
            {
                max = six;
            }
            break;
        case 7:
            seven++;
            if (seven > max)
            {
                max = seven;
            }
            break;
        case 8:
            eight++;
            if (eight > max)
            {
                max = eight;
            }
            break;
        case 9:
            nine++;
            if (nine > max)
            {
                max = nine;
            }
            break;
        default:
            return -1;
        }
    }
    return max;
}