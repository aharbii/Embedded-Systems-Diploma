/******************************************************************************
 * Sheet.01
 * 
 * Problem.12:
 *      --> write a program to take even numbers from user and print the sum 
 *          of them after each entry if the user enters 2 odd number the 
 *          program print "bye" and stopped.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variable contains sum result, initialized to 0
    int sum = 0;

    // Varibale contains numbers of entering odd numbers, initialized to zero
    int error_counter = 0;

    // Running condition
    while (error_counter < 2)
    {
        // Variables contains user's input
        int number;
        printf("Enter number: ");
        scanf("%d", &number);

        // Checking for input error
        if (number % 2)
        {
            error_counter += 1;
        }
        else
        {
            // Reseting error counter to 0
            error_counter = 0;
            sum += number;
            printf("Sum = %d\n", number);
        }
    }

    // Program's ending sign
    printf("bye\n");
    

    return 0;
}