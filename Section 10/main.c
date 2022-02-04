#include <stdio.h>
#include <stdlib.h>
#include "modifiers.h"

int func(int num)
{
    static int max = INT32_MIN;
    if (num > max)
    {
        max = num;
    }
    return max;
}

int main()
{
    printf("Welcome.\n");
    printf("Enter 1.to get maximum \n");
    printf("Enter 2.to get minimum \n");
    printf("Enter any other value to process it \n\n");
    int num = 0;
    while (1)
    {
        printf("Your value: ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            printf("max = %d\n", get_max());
            break;
        case 2:
            printf("min = %d\n", get_min());
            break;
        default:
            take_number(num);
            break;
        }
    }

    return 0;
}