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