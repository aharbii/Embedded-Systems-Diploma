/******************************************************************************
 * Sheet.02
 * 
 * Problem.10:
 *      --> Write c function to count the max number of zeros between two ones
 *          in the binary representation of a number
 *          (296384 -> 1001000010111000000 return 4).
 * 
 * @author: Ahmed Harbi
 * @date:   Jan 1st, 2022
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int number;
    printf("Enter number: ");
    scanf("%d", &number);

    int max = 0;
    int count = 0;
    _Bool start_count = 0;
    printf("%d --> 0b", number);
    for (int i = 31; i >= 0; i--)
    {
        unsigned int bit = 1 << i;
        bit = bit & number;
        bit >>= i;
        printf("%d", bit);
        if (bit)
        {
            start_count = 1;
        }

        if (start_count)
        {
            if (!bit)
            {
                count++;
            }
            if (bit)
            {
                if (count > max)
                {
                    max = count;
                    count = 0;
                }
            }
        }       
    }

    printf("\n");
    printf("max ones = %d\n", max);
    return 0;
}