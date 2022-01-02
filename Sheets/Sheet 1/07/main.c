/******************************************************************************
 * Sheet.01
 * 
 * Problem.07:
 *      --> Write a program that reads a positive integer and computes the 
 *          factorial.
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

    // Variable contains factorial, initialized to 1
    long long fact = 1;

    // multiply fact to current number and decrement its value by 1
    for (int i = number; i > 1; i--)
    {
        fact *= i;
    }

    printf("============================\n");

    // Printing results to user
    printf("Fact = %lld\n", fact);
    
    return 0;
}
