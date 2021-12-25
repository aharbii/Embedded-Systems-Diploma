/******************************************************************************
 * Sheet.01
 * 
 * Problem.11:
 *      --> Write a program to sum the digits in a decimal number
 *          145 -> 1+4+5=10.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Variable containts positive integer entered from user
    unsigned int number;
    printf("Enter number: ");
    scanf("%d", &number);

    // Variable contains final result, initialized to 0
    int sum = 0;

    // Getting reminder of division number by 10 to get digit, then divide it by 10 to remove this digit.
    while (number > 0)
    {
        unsigned char digit = number % 10;
        // Adding this digit to sum
        sum += digit;
        number /= 10;
    }

    // Printing result to user
    printf("Sum = %d\n", sum);
    

    return 0;
}