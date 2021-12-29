/******************************************************************************
 * Sheet.01
 * 
 * Problem.13:
 *      --> You are designing a poster which prints out numbers with a unique 
 *          style applied to each of them. The styling is based on the number 
 *          of closed paths or holes present in a giver number. The number of 
 *          holes that each of the digits from 0 to 9 have are equal to the 
 *          number of closed paths in the digit. Their values are:
 *                  --> 1, 2, 3, 5 and 7 = 0 holes.
 *                  --> 0, 4, 6, and 9 = 1 hole.
 *                  --> 8 = 2 holes.
 * 
 * Example:
 *      --> if number 3824
 *              -> 3 has 0 holes
 *              -> 8 has 2 holes
 *              -> 4 has 1hole 
 *              -> sum=0+2+1=3.
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

    // Variable contains final result, initialized to 0
    int sum = 0;

    if (number == 0)
    {
        int holes_value = 1;
        sum += holes_value;
    }
    // Getting reminder of division number by 10 to get digit, then divide it by 10 to remove this digit.
    while (number > 0)
    {
        unsigned char digit = number % 10;
        
        // Variable contains number of holes in this digit, initialized to 0
        int holes_value = 0;
        
        // Getting number of holes
        switch (digit)
        {
        case 1:
            holes_value = 0;
            break;
        case 2:
            holes_value = 0;
            break;
        case 3:
            holes_value = 0;
            break;
        case 4:
            holes_value = 1;
            break;
        case 5:
            holes_value = 0;
            break;
        case 6:
            holes_value = 1;
            break;
        case 7:
            holes_value = 0;
            break;
        case 8:
            holes_value = 2;
            break;
        case 9:
            holes_value = 1;
            break;
        case 0:
            holes_value = 1;
            break;
        }

        sum += holes_value;
        number /= 10;
    }

    // Printing result to user
    printf("Sum = %d\n", sum);
    return 0;
}
