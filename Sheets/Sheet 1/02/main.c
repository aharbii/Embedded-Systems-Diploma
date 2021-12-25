/******************************************************************************
 * Sheet.01
 * 
 * Problem.02:
 *      --> Write a program to take numbers from user and find the max and min 
 *          from them (let users choose the No of numbers).
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>  // Module contains INT32_MIN and INT32_MAX

int main()
{
    // Number of user input
    int number_of_inputs;
    printf("Enter size of numbers: ");
    scanf("%d", &number_of_inputs);

    // Variable contains maximum value initialized to INT32_MIN
    int max = INT32_MIN;

    // Variable contains minimum value initialized to INT32_MAX
    int min = INT32_MAX;
    
    // Getting input numbers from user
    for (int i = 0; i < number_of_inputs; i++)
    {
        // Variable contains input value from user.
        int number;
        printf("Enter number[%d]: ", i);
        scanf("%d", &number);

        // Comparing input value to maximum value
        if (number > max)
        {
            max = number;
        }

        // Comparing input value to minimum value
        if (number < min)
        {
            min = number;
        }
        
    }

    printf("============================\n");

    // Printing results to user
    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);

    return 0;
}