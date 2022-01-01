/******************************************************************************
 * Sheet.02
 * 
 * Problem.01:
 *      --> Write a program that reads the radius of a circle and calculates
 *          the area and circumference.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 31th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

int main()
{
    double radius;
    printf("Enter radius of the circle: ");
    scanf("%lf", &radius);

    double circumference = 2 * PI * radius;
    double area = PI * radius * radius;

    printf("Area          = %.4lf square units\n", area);
    printf("Circumference = %.4lf units\n", circumference);
    return 0;
}

/******************************************************************************
 * Sheet.02
 * 
 * Problem.02:
 *      --> Write a C program to take a number and a chracter from user,
 *          if the number is even print the same character, if the number is
 *          odd print the other case of the character. (a->A, B->b)
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

    char character;
    printf("Enter character: ");
    scanf(" %c", &character);

    if (number % 2)
    {
        int diff = ('a' - 'A');
        
        if ((character >= 'a') && (character <= 'z'))
        {
            character -= diff;
        }
        else if ((character >= 'A') && (character <= 'Z'))
        {
            character += diff;
        }
    }

    printf("Character: %c\n", character);
    

    return 0;
}

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

/******************************************************************************
 * Sheet.02
 * 
 * Problem.07:
 *      --> Write c code to sum numbers from 1 to 100 (without loop).
 * 
 * @author: Ahmed Harbi
 * @date:   Jan 1st, 2022
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* 0 + 100 = 100
       1 + 99  = 100
       2 + 98  = 100
       ....
       49 + 51 = 100
       50 = 50 */

    
    int sum = ((0 + 100) * 50) + (int) (100 / 2);
    printf("sum 1 : 100 = %d\n", sum);
    return 0;
}

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

/******************************************************************************
 * Sheet.02
 * 
 * Problem.09:
 *      --> Write c function to take number of lines and draw
 *          pattern with '*'.
 * 
 * @author: Ahmed Harbi
 * @date:   Jan 1st, 2022
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int number;
    printf("Enter number: ");
    scanf("%d", &number);

    /* Pattern 1 */
    int counter = number;
    while (counter > 0)
    {
        for (int i = 0; i < counter; i++)
        {
            printf("*");
        }
        printf("\n");
        counter--;
    }
    printf("========================\n");

    /* Pattern 2 */
    counter = 1;
    while (counter <= number)
    {
        for (int i = 0; i < counter; i++)
        {
            printf("*");
        }
        printf("\n");
        counter++;
    }
    printf("========================\n");

    /* Pattern 3 */
    

    /* Pattern 4 */
    
    
    return 0;
}

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

/******************************************************************************
 * Sheet.02
 * 
 * Problem.11:
 *      --> Given two integers: L and R, Find the maximal value of A xor B
 *          where A and B satisfy the condition (L =< A <= B <= R)
 *          constrains: 1 <= L <= R <= 100, input format: The input contains 
 *          two lines first line contains L and next line contains R.
 *          Output format: The maximum value of A xor B.
 * 
 * @author: Ahmed Harbi
 * @date:   Jan 1st, 2022
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l;
    printf("L: ");
    scanf("%d", &l);

    int r;
    printf("R: ");
    scanf("%d", &r);

    int max_xor = 0;

    for (int i = l; i <= r; i++)
    {
        for (int j = l++; j <= r; j++)
        {
            int xor = i ^ j;
            if (xor > max_xor)
            {
                max_xor = xor;
            }
            printf("%d ^ %d = %d\n", i, j, xor);
        }
        printf("\n");
    }

    printf("Maximum XOR value = %d\n", max_xor);
    

    return 0;
}

