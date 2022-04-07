/******************************************************************************
 * Sheet.01
 * 
 * Problem.03:
 *      --> Write a program to take numbers from user and calculate the sum of 
 *          them (let users choose the No of numbers).
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Number of user inputs
    int number_of_inputs;
    printf("Enter size of numbers: ");
    scanf("%d", &number_of_inputs);

    // Variable contains result, initialized to 0
    int sum = 0;

    // Getting input numbers from user
    for (int i = 0; i < number_of_inputs; i++)
    {
        // Variable contains input value from user.
        int number;
        printf("Enter number[%d]: ", i);
        scanf("%d", &number);

        // Adding entered value to sum
        sum += number;
        
    }

    printf("============================\n");

    // Printing results to user
    printf("Sum = %d\n", sum);

    return 0;
}