/******************************************************************************
 * FILE: SERIAL_MANIPULATION.h
 * DESCRIPTION:  C header file contains declration and documentation
 *               for the functions for SERIAL_MANIPULATION.c that performs some
 *               operations on serial array.
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

#ifndef _SERIAL_MANIPULATION_H_
#define _SERIAL_MANIPULATION_H_

#include <stdio.h>
#include <stdlib.h>

#define SERIAL_LENS 5

#define FIRST_BIGGER 1
#define SECOND_BIGGER -1
#define SERIAL_EQUAL 0

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* ========================================================================================================== */

/* =============== Queries =================== */

/******************************************************************************
 * Function: serial_print
 * DESCRIPTION:
 *          This function displays serial data to the command line.
 *
 * PARAMETERS:
 *      - serial: Array of unsigned characters with lens of SERIAL_LEN.
 ******************************************************************************/

void serial_print(unsigned char serial[SERIAL_LENS]);

/******************************************************************************
 * Function: serial_array_print
 * DESCRIPTION:
 *          This function displays array of serial data to the command line.
 *
 * PARAMETERS:
 *      - serials: Array of serial data array with lens of SERIAL_LEN.
 *      - size: Size of the array.
 ******************************************************************************/

void serial_array_print(unsigned char serials[][SERIAL_LENS], int size);

/******************************************************************************
 * FUNCTION: serial_compare
 * DESCRIPTION:
 *          This function compares two serial with each others, each element
 *          individually.
 *
 * PARAMETERS:
 *      - first_serial: Array of unsigned characters  with lens of SERIAL_LEN
 *                      represents the first serial.
 *      - second_serial: Array of unsigned characters  with lens of SERIAL_LEN
 *                      represents the second serial.
 * RETURN:
 *      - INT:
 *          --> MACRO: FIRST_BIGGER if first serial has bigger value elements.
 *          --> MACRO: SECOND_BIGGER if second serial has bigger value elements.
 *          --> MACRO: SERIAL_EQUAL if two serials has the exact same values.
 ******************************************************************************/

int serial_compare(unsigned char first_serial[SERIAL_LENS], unsigned char second_serial[SERIAL_LENS]);

/******************************************************************************
 * Function: serial_array_linear_search
 * DESCRIPTION:
 *          This function performs linear search on array of serial data and
 *          return the it's index if it is found, -1 if it is not found.
 *
 * PARAMETERS:
 *      - serials: Array of serial data array with lens of SERIAL_LEN.
 *      - size: Size of the array.
 *      - to_find: Array of unsigned characters  with lens of SERIAL_LEN
 *                 represents the serial to be found.
 * RETURN:
 *      - INT:
 *          --> Index in case the element is found.
 *          --> -1 in case the element is not found.
 ******************************************************************************/

int serial_array_linear_search(unsigned char serials[][SERIAL_LENS], int size, unsigned char to_find[SERIAL_LENS]);

/******************************************************************************
 * Function: serial_array_binary_search
 * DESCRIPTION:
 *          This function performs binary search on array of serial data and
 *          return the it's index if it is found, -1 if it is not found.
 *
 * PARAMETERS:
 *      - serials: Array of serial data array with lens of SERIAL_LEN.
 *      - size: Size of the array.
 *      - to_find: Array of unsigned characters  with lens of SERIAL_LEN
 *                 represents the serial to be found.
 * RETURN:
 *      - INT: 
 *          --> Index in case the element is found.
 *          --> -1 in case the element is not found.
 ******************************************************************************/

int serial_array_binary_search(unsigned char serials[][SERIAL_LENS], int size, unsigned char to_find[SERIAL_LENS]);

/* ========================================================================================================== */

/* =============== Manipulations =================== */

/******************************************************************************
 * FUNCTION: serials_swap
 * DESCRIPTION:
 *          This function swaps two serials with each other by swapping each
 *          element individually.
 *
 * PARAMETERS:
 *      - first_serial: Array of unsigned characters  with lens of SERIAL_LEN
 *                      represents the first serial.
 *      - second_serial: Array of unsigned characters  with lens of SERIAL_LEN
 *                      represents the second serial.
 ******************************************************************************/

void serials_swap(unsigned char first_serial[SERIAL_LENS], unsigned char second_serial[SERIAL_LENS]);

/******************************************************************************
 * FUNCTION: serial_array_bubble_sort
 * DESCRIPTION:
 *          This function performs adaptive buuble sort on an array of serial.
 *
 * PARAMETERS:
 *      - serials: Array of serial data array with lens of SERIAL_LEN.
 *      - size: Size of the array.
 ******************************************************************************/

void serial_array_bubble_sort(unsigned char serials[][SERIAL_LENS], int size);

#endif /* _SERIAL_MANIPULATION_H_ */