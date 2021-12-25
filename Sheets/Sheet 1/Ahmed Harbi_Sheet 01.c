/******************************************************************************
 * Sheet.01
 * 
 * Problem.01:
 *      --> Write a program to take 2 numbers from user and calculate sum of 
 *          all numbers between them.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Input variable from user
    int first_number;
    printf("Enter first number: ");
    scanf("%d", &first_number);

    // Input variable from user
    int second_number;
    printf("Enter first number: ");
    scanf("%d", &second_number);

    // Variable contains result, initialized to 0
    int sum = 0;

    // Getting largest and smallest variables
    if (first_number > second_number)
    {
        // Getting numbers between them in ascending order
        for (int i = (second_number + 1); i < first_number; i++)
        {
            // Adding current value to sum 
            sum += i;
        }
    }
    else if (second_number > first_number)
    {
        // Getting numbers between them in ascending order
        for (int i = (first_number + 1); i < second_number; i++)
        {
            // Adding current value to sum
            sum += i;
        }
    }

    printf("============================\n");

    // Printing final results
    if((second_number == first_number) || (abs(first_number - second_number) == 1))
    {
        // Equlaity case, or difference is equal to 1
        printf("There's no numbers between %d and %d\n", first_number, second_number);
    }
    else
    {
        // Printing sum value.
        printf("Sum = %d\n", sum);
    }
    
    return 0;
}

/******************************************************************************
 * Sheet.01
 * 
 * Problem.02:
 *      --> Write a program to take numbers from user and find the max and min 
 *          from them (let users choose the No of numbers).
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>  // Module contains INT32_MIN and INT32_MAX

int main()
{
    // Number of user input
    int number_of_inputs;
    printf("Enter size of numbers: ");
    scanf("%d", &number_of_inputs);

    // Variable contains maximum value initialized to INT32_MIN
    int max = INT32_MIN;

    // Variable contains minimum value initialized to INT32_MAX
    int min = INT32_MAX;
    
    // Getting input numbers from user
    for (int i = 0; i < number_of_inputs; i++)
    {
        // Variable contains input value from user.
        int number;
        printf("Enter number[%d]: ", i);
        scanf("%d", &number);

        // Comparing input value to maximum value
        if (number > max)
        {
            max = number;
        }

        // Comparing input value to minimum value
        if (number < min)
        {
            min = number;
        }
        
    }

    printf("============================\n");

    // Printing results to user
    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);

    return 0;
}

/******************************************************************************
 * Sheet.01
 * 
 * Problem.03:
 *      --> Write a program to take numbers from user and calculate the sum of 
 *          them (let users choose the No of numbers).
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Number of user inputs
    int number_of_inputs;
    printf("Enter size of numbers: ");
    scanf("%d", &number_of_inputs);

    // Variable contains result, initialized to 0
    int sum = 0;

    // Getting input numbers from user
    for (int i = 0; i < number_of_inputs; i++)
    {
        // Variable contains input value from user.
        int number;
        printf("Enter number[%d]: ", i);
        scanf("%d", &number);

        // Adding entered value to sum
        sum += number;
        
    }

    printf("============================\n");

    // Printing results to user
    printf("Sum = %d\n", sum);

    return 0;
}

/******************************************************************************
 * Sheet.01
 * 
 * Problem.04:
 *      --> Write a program that take two numbers and multiply them without 
 *          using * operation.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Input variable from user
    int first_number;
    printf("Enter first number: ");
    scanf("%d", &first_number);

    // Input variable from user
    int second_number;
    printf("Enter first number: ");
    scanf("%d", &second_number);

    // Variable contains multiplication result initialized to 0
    int product = 0;

    // Adding first_number to itself (second_number) times
    for (int i = 0; i < second_number; i++)
    {
        product += first_number;
    }

    printf("============================\n");

    // Printing results to user
    printf("%d x %d = %d\n", first_number, second_number, product);
    
    return 0;
}

/******************************************************************************
 * Sheet.01
 * 
 * Problem.05:
 *      --> Write a program that take two numbers and calculate the reminder 
 *          without using % operation.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Input variable from user
    int first_number;
    printf("Enter first number: ");
    scanf("%d", &first_number);

    // Input variable from user
    int second_number;
    printf("Enter first number: ");
    scanf("%d", &second_number);

    // Getting largest number and always save it to first_number
    if (first_number > second_number)
    {
        
    }
    else
    {
        // Swap variables to make first number contains largest value
        int temp = first_number;
        first_number = second_number;
        second_number = temp;
    }
    
    // Variable contains division value
    int division = first_number / second_number;

    // Variable contains reminder value
    int reminder = first_number - (second_number * division);


    printf("============================\n");

    // Printing results to user
    printf("%d %% %d = %d\n", first_number, second_number, reminder);
    
    return 0;
}

/******************************************************************************
 * Sheet.01
 * 
 * Problem.06:
 *      --> Write a program to calculate the power of a number. The number and 
 *          its power are input from user.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variable entered from user contains base value
    int base;
    printf("Enter first number: ");
    scanf("%d", &base);

    // Variable entered from user contains exponent value
    int exponent;
    printf("Enter first number: ");
    scanf("%d", &exponent);

    // Variable contains power result initialized to 1
    int power = 1;

    // Multipling base to itself (exponent) times
    for (int i = 0; i < exponent; i++)
    {
        power *= base;
    }


    printf("============================\n");

    // Printing results to user
    printf("%d ^ %d = %d\n", base, exponent, power);
 

    return 0;
}

/******************************************************************************
 * Sheet.01
 * 
 * Problem.07:
 *      --> Write a program that reads a positive integer and computes the 
 *          factorial.
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

    // Variable contains factorial, initialized to 1
    long long fact = 1;

    // multiply fact to current number and decrement its value by 1
    for (int i = number; i > 1; i--)
    {
        fact *= i;
    }

    printf("============================\n");

    // Printing results to user
    printf("Fact = %lld\n", fact);
    
    return 0;
}


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

/******************************************************************************
 * Sheet.01
 * 
 * Problem.09:
 *      --> Write a program that reads a positive integer and checks if it is 
 *          a perfect square.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    // Variable containts positive integer entered from user
    unsigned int number;
    printf("Enter number: ");
    scanf("%d", &number);

    // boolian variable contains if number is prime, Initialized to false
    unsigned char is_perfect_square = 0;


    // --> perfect_square is perfect square initialized to 0
    int perfect_square = 0;
    
    // first check i*i = perfect_square | i = {1, 2, 3, 4, ....., 1000}
    for (int i = 1; i < INT32_MAX; i++)
    {
        perfect_square = i * i;
        if (number == perfect_square)
        {
            is_perfect_square = 1;
            break;
        }
    }
    
    if (is_perfect_square)
    {
        printf("%d is perfect square number.\n", number);
    }
    else
    {
        printf("%d is not perfect square number.\n", number);

    }

    return 0;
}

/******************************************************************************
 * Sheet.01
 * 
 * Problem.10:
 *      --> Write a program that reads a positive integer and check if this 
 *          number is a base of 2 like 1,2,4,8,16,32, 64...
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

    // Boolian variable contains 0 if number is base two or 1 if number is not base two, Initialized to true
    unsigned char is_not_base_two = 1;


    // Copy of entered number
    int number_copy = number;
    
    // Getting reminder of smallest prime number
    while (number_copy > 1)
    {
        is_not_base_two = number_copy % 2;
        number_copy /= 2;
    }
    
    // Printing result to user
    if (is_not_base_two)
    {
        printf("%d is not base 2 number.\n", number);
    }
    else
    {
        printf("%d is base 2 number.\n", number);

    }

    return 0;
}

/******************************************************************************
 * Sheet.01
 * 
 * Problem.11:
 *      --> Write a program to sum the digits in a decimal number
 *          145 -> 1+4+5=10.
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

    // Getting reminder of division number by 10 to get digit, then divide it by 10 to remove this digit.
    while (number > 0)
    {
        unsigned char digit = number % 10;
        // Adding this digit to sum
        sum += digit;
        number /= 10;
    }

    // Printing result to user
    printf("Sum = %d\n", sum);
    

    return 0;
}

/******************************************************************************
 * Sheet.01
 * 
 * Problem.12:
 *      --> write a program to take even numbers from user and print the sum 
 *          of them after each entry if the user enters 2 odd number the 
 *          program print "bye" and stopped.
 * 
 * @author: Ahmed Harbi
 * @date:   Dec 25th, 2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variable contains sum result, initialized to 0
    int sum = 0;

    // Varibale contains numbers of entering odd numbers, initialized to zero
    int error_counter = 0;

    // Running condition
    while (error_counter < 2)
    {
        // Variables contains user's input
        int number;
        printf("Enter number: ");
        scanf("%d", &number);

        // Checking for input error
        if (number % 2)
        {
            error_counter += 1;
        }
        else
        {
            // Reseting error counter to 0
            error_counter = 0;
            sum += number;
            printf("Sum = %d\n", number);
        }
    }

    // Program's ending sign
    printf("bye\n");
    

    return 0;
}

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
