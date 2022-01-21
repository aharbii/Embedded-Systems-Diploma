#include <stdio.h>
#include <stdlib.h>
#include "ARRAY.h"

int main()
{

    printf("\n==============================================\n\n");

    int a_swap[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a_swap_size = ARRAY_SIZE(a_swap);
    int b_swap[10] = {100, 200, 300, 400, 500};
    int b_swap_size = 5;
    array_swap(a_swap, &a_swap_size, b_swap, &b_swap_size);
    array_print(a_swap, &a_swap_size);
    array_print(b_swap, &b_swap_size);
    
    printf("\n==============================================\n\n");

    int a_most_repeats[] = {1, 2, 3, 4, 5, 6, 7, 8, 1, 1, 1, 1, 1, 2, 3, 4};
    int a_most_repeats_size = ARRAY_SIZE(a_most_repeats);
    int value_most_repeats = 0;
    int repeats_most_repeats = 0;
    array_most_repeated_consecutive(a_most_repeats, &a_most_repeats_size, &value_most_repeats, &repeats_most_repeats);
    printf("%d --> %d\n", value_most_repeats, repeats_most_repeats);
    
    printf("\n==============================================\n\n");

    return 0;
}