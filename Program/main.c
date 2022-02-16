#include <stdio.h>
#include <stdlib.h>
#include "ARRAY.h"
#include "MATH.h"
#include "STRINGS.h"
#include "SORTING.h"

int main()
{
    int arr[] = {5, 32, 12, 54, 64, 312, 654, 52, 34, 134, 4134, 526, 6145, 64, 524, 513, 5, 51, 5, 13};
    int size = ARRAY_SIZE(arr);
    count_sort(arr, size);
    array_print(arr, &size);
    return 0;
}