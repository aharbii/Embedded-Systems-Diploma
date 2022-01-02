/******************************************************************************
 * Sheet.02
 * 
 * Problem.05:
 *      --> Wrtie a program to print the binary representation of a number, 
 *          try not to print zeros on the left (5->101);
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 31th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int number;
    printf("Enter number: ");
    scanf("%u", &number);

    int max_setted_bit = 0;
    for (int i = ((sizeof(number) * 8) - 1); (i >= 0) && (!max_setted_bit) ; i--)
    {
        unsigned int bit = 1 << i;
        bit = bit & number;
        if (bit)
        {
            max_setted_bit = i;
        }
    }

    printf("%u in binary is 0b", number);
    for (int i = max_setted_bit; i >= 0; i--)
    {
        unsigned int bit = 1 << i;
        bit = bit & number;
        bit >>= i;
        printf("%u", bit);
    }
    printf("\n");
    
    
    return 0;
}