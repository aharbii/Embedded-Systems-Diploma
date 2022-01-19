#include <stdio.h>
#include <stdlib.h>
#include "MATH.h"
#include "ARRAY.h"

int main()
{
    // int array_save[100] = {0};
    // int max_min[2][2] = {{0, 0}, {0, 0}};
    // int size = array_between(-5, 5, array_save);
    // array_get_max_min(array_save, size, max_min);
    // array_print(array_save, size);
    // array_print_2d(&max_min[0][0], 2, 2);
    // printf("%d\n", is_powerof_three(0));

    // int a[] = {-1, 4, 3, 7, 12, -9, 4, 0};
    // printf("%d\n", array_most_repeated(a, 8));
    // array_reverse(a, 8);
    // array_print(a, 8);

    // int Array[] = {1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3};
    // int x = array_longest_consecutive(Array, ARRAY_SIZE(Array), 2);
    // printf("%d\n", x);
    // int a[] = {1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 3, 3, 3};
    // int value = 0;
    // int repeats = 0;
    // array_most_repeated_consecutive(a, ARRAY_SIZE(a), &value, &repeats);
    // printf("%d -> %d\n", repeats, value);

    // int first_array[] = {1, 2, 3, 4, 5};
    // int second_array[] = {11, 12, 13, 14, 15};
    // int merged[100] = {0};
    // int merged_size = 0;
    // merge_array(first_array, ARRAY_SIZE(first_array), second_array, ARRAY_SIZE(second_array), merged, &merged_size);
    // array_print(merged, merged_size);

    // int array[] = {1, 2, 2, 3, 3, 3, 3 , 4, 4, 4, 4, 3, 3};
    // int size = 13;
    // array_remove_duplicate_sorted(array, &size);
    // array_print(array, &size);

    int x = 0;
    int *p = &x;
    int y = 1;
    int *t = &y;
    printf("%d\n", p);
    printf("%d\n", *p);
    printf("%d\n", t);
    printf("%d\n", *t);

    swap_ptr(&p, &t);
    printf("%d\n", p);
    printf("%d\n", *p);
    printf("%d\n", t);
    printf("%d\n", *t);


    return 0;
}