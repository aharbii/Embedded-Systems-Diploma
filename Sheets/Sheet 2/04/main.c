/******************************************************************************
 * Sheet.02
 * 
 * Problem.04:
 *      --> Write a program to count the number of 1's in an unsigned 32-bit
 *          integer.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 31th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    uint32_t number;
    printf("Enter number: ");
    scanf("%u", &number);

    printf("%u in binary is 0b", number);

    int count = 0;
    
    for (int i = 31; i >= 0; i--)
    {
        uint32_t bit = 1 << i;
        bit = bit & number;
        bit >>= i;
        
        printf("%u", bit);

        if (bit)
        {
            count++;
        }
    }
    printf("\n");

    printf("Ones in %u: %u\n", number, count);


    

    return 0;
}