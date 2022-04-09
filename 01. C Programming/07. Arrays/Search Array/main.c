#include <stdio.h>
#include <stdlib.h>
#include "ARRAY.h"

int main()
{
    int array[10] = {1, 5, 7, 4, 3, 6, 9, 2, 8, 0};
    int to_find;
    printf("Enter number to find: ");
    scanf("%d", &to_find);

    int is_found = array_search(array, 10, to_find);

    if (is_found >= 0)
    {
        printf("%d is in the array at index: %d\n", to_find, is_found);
    }
    else
    {
        printf("%d is not in the array\n", to_find);
    }
    

    return 0;
}