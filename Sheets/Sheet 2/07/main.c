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