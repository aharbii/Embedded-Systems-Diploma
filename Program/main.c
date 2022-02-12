#include <stdio.h>
#include <stdlib.h>
#include "ARRAY.h"
#include "STRINGS.h"
#include "MATH.h"

void bubble_sort(int *arr, int size)
{
    int not_sorted = 1;
    for (int i = 1; (i < size) && not_sorted; i++)
    {
        not_sorted = 0;
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                not_sorted = 1;
            }
        }
    }
}

int main()
{
    int arr[] = {10, 9, 8, 7, 5, 4, 2, 1};
    int size = ARRAY_SIZE(arr);
    bubble_sort(arr, size);
    array_print(arr, &size);
    return 0;
}
