/******************************************************************************
 * Sheet.01
 * 
 * Problem.08:
 *      --> Write a program that reads a positive integer and checks if 
 *          it is a prime.
 * 
 * @ps: could not check numbers larger than 199
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

    // Boolian variable contains if number is prime, Initialized to false
    unsigned char is_prime = 0;


    // --> p is prime number initialized to 0
    int p = 0;
    
    // First check 6n+1 = p or 6n-1, when p is less than 41 and more than 3 | --> n = {0, 1, 2, .....}
    for (int n = 0; p < 41; n++)
    {
        p = (6 * n) + 1;
        if (number == p)
        {
            is_prime = 1;
            break;
        }

        p = (6 * n) - 1;
        if (number == p)
        {
            is_prime = 1;
            break;
        }
    }

    if(!is_prime)
    {
        // Second check n2 + n + 41 = p, when p is larger than or eual to 41 | --> n = {0, 1, 2, ....., 39}
        for (size_t n = 0; n < 40; n++)
        {
            p = (n * n) + n + 41;
            if (number == p)
            {
                is_prime = 1;
                break;
            }

        }
    }

    // Printing result to user
    if (is_prime)
    {
        printf("%d is prime number.\n", number);
    }
    else if ((number == 2) || (number == 3))
    {
        printf("%d is prime number.\n", number);
    }
    else
    {
        printf("%d is not prime number.\n", number);

    }
    

    return 0;
}