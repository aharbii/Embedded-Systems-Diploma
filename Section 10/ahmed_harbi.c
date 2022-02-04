/* file name: modifiers.h */

void take_number(int num);
int get_max(void);
int get_min(void);

/* file name: modifiers.c */

#include <stdio.h>
#include <stdlib.h>
#include "modifiers.h"

static int max = INT32_MIN;
static int min = INT32_MAX;

void take_number(int num)
{
    if (num > max)
    {
        max = num;
    }

    if (num < min)
    {
        min = num;
    }
}

int get_max(void)
{
    return max;
}

int get_min(void)
{
    return min;
}

/* file name: main.c */

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