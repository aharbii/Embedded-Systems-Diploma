/******************************************************************************
 * Sheet.01
 * 
 * Problem.10:
 *      --> Write a program that reads a positive integer and check if this 
 *          number is a base of 2 like 1,2,4,8,16,32, 64...
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

    // Boolian variable contains 0 if number is base two or 1 if number is not base two, Initialized to true
    unsigned char is_not_base_two = 1;


    // Copy of entered number
    int number_copy = number;
    
    // Getting reminder of smallest prime number
    while (number_copy > 1)
    {
        is_not_base_two = number_copy % 2;
        number_copy /= 2;
    }
    
    // Printing result to user
    if (is_not_base_two)
    {
        printf("%d is not base 2 number.\n", number);
    }
    else
    {
        printf("%d is base 2 number.\n", number);

    }

    return 0;
}