/******************************************************************************
 * FILE: SERIAL_MANIPULATION.c
 * DESCRIPTION:  C program that performs some operations on serial array.
 *
 *              Queries:
 *                  --> Print Serial
 *                  --> Print Array of Serials
 *                  --> Linear Search <For Not-Sorted Arrays>
 *                  --> Binary Search <For Sorted Arrays>
 *                  --> Compare Two Serials
 *
 *              Manipulations:
 *                  --> Swapping Two Serials
 *                  --> Sorting Array of Serials <Adaptive Bubble Sort>
 *
 *                  --> Power
 *                  --> Summation
 *                  --> Get Fibonacci of Integer
 *                  --> Reversing an Integer
 *
 * AUTHOR: Ahmed Harbi
 * DATE: March 2022
 *****************************************************************************/

#include "SERIALS_MANIPULATION.h"

void serial_print(unsigned char serial[SERIAL_LENS])
{
        for (int i = 0; i < SERIAL_LENS; i++)
        {
                printf("0x%02X ", serial[i]);
        }
        printf("\n");
}

void serial_array_print(unsigned char serials[][SERIAL_LENS], int size)
{
        for (int i = 0; i < size; i++)
        {
                serial_print(serials[i]);
        }
}

int serial_compare(unsigned char first_serial[SERIAL_LENS], unsigned char second_serial[SERIAL_LENS])
{
        for (int i = 0; i < SERIAL_LENS; i++)
        {
                if (first_serial[i] != second_serial[i])
                {
                        if (first_serial[i] > second_serial[i])
                        {
                                return FIRST_BIGGER;
                        }
                        else
                        {
                                return SECOND_BIGGER;
                        }
                }
        }
        return SERIAL_EQUAL;
}

int serial_array_linear_search(unsigned char serials[][SERIAL_LENS], int size, unsigned char to_find[SERIAL_LENS])
{
        for (int i = 0; i < size; i++)
        {
                if (serial_compare(serials[i], to_find) == SERIAL_EQUAL)
                {
                        return i;
                }
        }
        return -1;
}

int serial_array_binary_search(unsigned char serials[][SERIAL_LENS], int size, unsigned char to_find[SERIAL_LENS])
{
        int l = 0;
        int h = size - 1;
        while (l < h)
        {
                int mid = (l + h) / 2;
                if (serial_compare(serials[mid], to_find) == SERIAL_EQUAL)
                {
                        return mid;
                }
                else if (serial_compare(serials[mid], to_find) == FIRST_BIGGER)
                {
                        h = mid - 1;
                }
                else
                {
                        l = mid + 1;
                }
        }
        return -1;
}

void char_swap(unsigned char *x, unsigned char *y)
{
        unsigned char temp = *x;
        *x = *y;
        *y = temp;
}

void serials_swap(unsigned char first_serial[SERIAL_LENS], unsigned char second_serial[SERIAL_LENS])
{
        for (int i = 0; i < SERIAL_LENS; i++)
        {
                char_swap(&first_serial[i], &second_serial[i]);
        }
}

void serial_array_bubble_sort(unsigned char serials[][SERIAL_LENS], int size)
{
        int is_not_sorted = 1;

        for (int i = 1; (i < size) && (is_not_sorted); i++)
        {
                is_not_sorted = 0;

                for (int j = 0; j < (size - i); j++)
                {
                        if (serial_compare(serials[j], serials[j + 1]) == FIRST_BIGGER)
                        {
                                swap_serials(serials[j], serials[j + 1]);
                                is_not_sorted = 1;
                        }
                }
        }
}
