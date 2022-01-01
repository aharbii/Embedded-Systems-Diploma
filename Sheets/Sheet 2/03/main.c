/******************************************************************************
 * Sheet.02
 * 
 * Problem.03:
 *      --> Write a program to reverse a number in decimal representation
 *          (1205->5021).
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 31th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter number: ");
    scanf("%d", &number);

    int reversed = 0;
    int number_copy = number;
    _Bool is_negative = 0;
    if (number_copy < 0)
    {
        is_negative = 1;
        number_copy *= -1;
    }
    
    while (number_copy > 0)
    {
        reversed *= 10;
        int digit = number_copy % 10;
        reversed += digit;
        number_copy /= 10;
    }

    if (is_negative)
    {
        reversed *= -1;
    }
    
    
    printf("%d --> %d\n", number, reversed);


    return 0;
}