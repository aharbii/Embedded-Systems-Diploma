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