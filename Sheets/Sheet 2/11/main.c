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