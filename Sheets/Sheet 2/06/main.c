/******************************************************************************
 * Sheet.02
 * 
 * Problem.06:
 *      --> Write c code to reverse bits in an 8-bit number,
 *          (149->1001010 return 169->10101001),
 *          (5->00000101  return 160->10100000)
 * 
 * @author: Ahmed Harbi
 * @date:   Jan 1st, 2022
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    uint8_t number;
    printf("Enter number: ");
    scanf("%u", &number);

    printf("%u --> 0b", number);
    uint8_t reversed = 0;
    for (int i = 7; i >= 0; i--)
    {
        uint8_t bit = 1 << 7;
        bit &= number;
        reversed >>= 1;
        reversed |= bit;
        bit >>= 7;
        printf("%u", bit);
        number <<= 1;
    }
    printf("\n");

    printf("%u --> 0b", reversed);

    
    for (int i = 7; i >= 0; i--)
    {
        uint8_t bit = 1 << i;
        bit = bit & reversed;
        bit >>= i;
        
        printf("%u", bit);
    }
    printf("\n");

    return 0;
}