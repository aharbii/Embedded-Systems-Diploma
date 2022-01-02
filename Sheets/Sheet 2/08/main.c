/******************************************************************************
 * Sheet.02
 * 
 * Problem.08:
 *      --> Write a full C program to take 4 choose from user:
 *          1.Set bit.
 *          2.Clear bit.
 *          3.Toggle bit.
 *          4.Read bit.
 * 
 *          Then take number, and bit number.
 *          print the number after set, clear, or toggle if 1, 2, or 3 is
 *          selected. print the bit value if 4 is selected.
 * 
 * @author: Ahmed Harbi
 * @date:   Jan 1st, 2022
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    _Bool run = 1;
    while (run)
    {
        printf("1.Set bit.\n");
        printf("2.Clear bit.\n");
        printf("3.Toggle bit.\n");
        printf("4.Read bit.\n");
        printf("5.Quit.\n");
        int mode;
        printf("Please select mode: ");
        scanf("%d", &mode);
        if (mode == 5)
        {
            run = 0;
            continue;
        }
        unsigned int number;
        printf("Enter number: ");
        scanf("%u", &number);

        int bit_position;
        printf("Enter bit position: ");
        scanf("%d", &bit_position);
        unsigned int bit = 0;
        switch (mode)
        {
            case 1:
                /* Setting bit */
                printf("%d -> 0b", number);
                for (int i = 31; i >= 0; i--)
                {
                    bit = 1 << i;
                    bit = bit & number;
                    bit >>= i;
                    printf("%d", bit);
                }
                printf("\n");

                printf("Setting bit.....\n");
                bit = 1 << bit_position;
                number |= bit;

                printf("%d -> 0b", number);
                for (int i = 31; i >= 0; i--)
                {
                    bit = 1 << i;
                    bit = bit & number;
                    bit >>= i;
                    printf("%d", bit);

                }
                printf("\n");

                break;
            case 2:
                /* Clear bit */
                printf("%d -> 0b", number);
                for (int i = 31; i >= 0; i--)
                {
                    bit = 1 << i;
                    bit = bit & number;
                    bit >>= i;
                    printf("%d", bit);
                }
                printf("\n");

                printf("Clearing bit.....\n");
                bit = ~(1 << bit_position);
                number &= bit;
                
                printf("%d -> 0b", number);
                for (int i = 31; i >= 0; i--)
                {
                    bit = 1 << i;
                    bit = bit & number;
                    bit >>= i;
                    printf("%d", bit);
                }
                printf("\n");

                break;
            case 3:
                /* Toggle bit */
                printf("%d -> 0b", number);
                for (int i = 31; i >= 0; i--)
                {
                    bit = 1 << i;
                    bit = bit & number;
                    bit >>= i;
                    printf("%d", bit);
                }
                printf("\n");

                printf("Toggling bit.....\n");
                bit = 1 << bit_position;
                number ^= bit;

                printf("%d -> 0b", number);
                for (int i = 31; i >= 0; i--)
                {
                    bit = 1 << i;
                    bit = bit & number;
                    bit >>= i;
                    printf("%d", bit);
                }
                printf("\n");

                break;
            case 4:
                /* Read bit */
                bit = 1 << bit_position;
                bit &= number;
                bit >>= bit_position;
                printf("%d bit is %d\n", bit_position, bit);
                break;
            default:
                printf("Unvalid Choice!\n");
                break;
        }
    }
    printf("Goodbye!\n");
    
    return 0;
}