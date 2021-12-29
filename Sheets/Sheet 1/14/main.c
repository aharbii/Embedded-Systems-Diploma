/******************************************************************************
 * Sheet.01
 * 
 * Problem.14:
 *      --> Write a program that reads n and prints n prime numbers.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 29th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variable contains number of prime numbers, User's Input
    int n;
    printf("Enter number of primes: ");
    scanf("%d", &n);

    // Variable contains number which is checked to be prime or not
    unsigned int i;

    // Printing first two primes (1, 2)
    for (i = 1; (i <= 2) && (i <= n); i++)
    {
        printf("%u\n", i);
    }

    // Decrement n by 2 printed numbers (1, 2)
    n -= 2;

    // Boolian variables contains current i state prime or not prime, initialized to true
    unsigned char is_prime = 1;

    // Loop counting n printed prime numbers
    while (n > 0)
    {
        // reinitializing i state at each loop
        is_prime = 1;

        // Variable contains numbers to check if i is divisble by it or not, 
        // if it's divisble by any j the loop with is_prime state false, 
        // if j == i then it's a prime number
        for (int j = 2; (j < i) && is_prime; j++)
        {
            if ((i % j) == 0)
            {
                // Changing is_prime i state to false, and break the loop
                is_prime = 0;
            }
        }

        if (is_prime)
        {
            // Printing prime number value and decrementing n
            printf("%u\n", i);
            n--;
        }

        // Incrementing i for next check
        i++;
    }
    
    

    return 0;
}