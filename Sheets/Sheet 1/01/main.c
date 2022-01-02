/******************************************************************************
 * Sheet.01
 * 
 * Problem.01:
 *      --> Write a program to take 2 numbers from user and calculate sum of 
 *          all numbers between them.
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

    // Variable contains result, initialized to 0
    int sum = 0;

    // Getting largest and smallest variables
    if (first_number > second_number)
    {
        // Getting numbers between them in ascending order
        for (int i = (second_number + 1); i < first_number; i++)
        {
            // Adding current value to sum 
            sum += i;
        }
    }
    else if (second_number > first_number)
    {
        // Getting numbers between them in ascending order
        for (int i = (first_number + 1); i < second_number; i++)
        {
            // Adding current value to sum
            sum += i;
        }
    }

    printf("============================\n");

    // Printing final results
    if((second_number == first_number) || (abs(first_number - second_number) == 1))
    {
        // Equlaity case, or difference is equal to 1
        printf("There's no numbers between %d and %d\n", first_number, second_number);
    }
    else
    {
        // Printing sum value.
        printf("Sum = %d\n", sum);
    }
    
    return 0;
}