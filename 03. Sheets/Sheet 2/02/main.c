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