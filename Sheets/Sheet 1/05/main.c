/******************************************************************************
 * Sheet.01
 * 
 * Problem.05:
 *      --> Write a program that take two numbers and calculate the reminder 
 *          without using % operation.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Input variable from user
    int first_number;
    printf("Enter first number: ");
    scanf("%d", &first_number);

    // Input variable from user
    int second_number;
    printf("Enter first number: ");
    scanf("%d", &second_number);

    // Getting largest number and always save it to first_number
    if (first_number > second_number)
    {
        
    }
    else
    {
        // Swap variables to make first number contains largest value
        int temp = first_number;
        first_number = second_number;
        second_number = temp;
    }
    
    // Variable contains division value
    int division = first_number / second_number;

    // Variable contains reminder value
    int reminder = first_number - (second_number * division);


    printf("============================\n");

    // Printing results to user
    printf("%d %% %d = %d\n", first_number, second_number, reminder);
    
    return 0;
}