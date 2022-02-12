#include <stdio.h>
#include <stdlib.h>
#include "ARRAY.h"
#include "STRINGS.h"
#include "MATH.h"
#include "SORTING.h"

int main()
{
    int arr[] = {4, 3, 12, 545, 213, 41, 532, 451, 342, 5, -12, -1012, 14, 23};
    int size = ARRAY_SIZE(arr);
    selection_sort(arr, size);
    array_print(arr, &size);
    return 0;
}
