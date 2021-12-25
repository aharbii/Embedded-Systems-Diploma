/******************************************************************************
 * Sheet.01
 * 
 * Problem.04:
 *      --> Write a program that take two numbers and multiply them without 
 *          using * operation.
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

    // Variable contains multiplication result initialized to 0
    int product = 0;

    // Adding first_number to itself (second_number) times
    for (int i = 0; i < second_number; i++)
    {
        product += first_number;
    }

    printf("============================\n");

    // Printing results to user
    printf("%d x %d = %d\n", first_number, second_number, product);
    
    return 0;
}