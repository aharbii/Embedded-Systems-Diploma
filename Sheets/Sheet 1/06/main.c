/******************************************************************************
 * Sheet.01
 * 
 * Problem.06:
 *      --> Write a program to calculate the power of a number. The number and 
 *          its power are input from user.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variable entered from user contains base value
    int base;
    printf("Enter first number: ");
    scanf("%d", &base);

    // Variable entered from user contains exponent value
    int exponent;
    printf("Enter first number: ");
    scanf("%d", &exponent);

    // Variable contains power result initialized to 1
    int power = 1;

    // Multipling base to itself (exponent) times
    for (int i = 0; i < exponent; i++)
    {
        power *= base;
    }


    printf("============================\n");

    // Printing results to user
    printf("%d ^ %d = %d\n", base, exponent, power);
 

    return 0;
}