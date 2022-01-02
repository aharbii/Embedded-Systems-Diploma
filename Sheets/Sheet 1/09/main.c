/******************************************************************************
 * Sheet.01
 * 
 * Problem.09:
 *      --> Write a program that reads a positive integer and checks if it is 
 *          a perfect square.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    // Variable containts positive integer entered from user
    unsigned int number;
    printf("Enter number: ");
    scanf("%d", &number);

    // boolian variable contains if number is prime, Initialized to false
    unsigned char is_perfect_square = 0;


    // --> perfect_square is perfect square initialized to 0
    int perfect_square = 0;
    
    // first check i*i = perfect_square | i = {1, 2, 3, 4, ....., 1000}
    for (int i = 1; i < INT32_MAX; i++)
    {
        perfect_square = i * i;
        if (number == perfect_square)
        {
            is_perfect_square = 1;
            break;
        }
    }
    
    if (is_perfect_square)
    {
        printf("%d is perfect square number.\n", number);
    }
    else
    {
        printf("%d is not perfect square number.\n", number);

    }

    return 0;
}