#include <stdio.h>
#include <stdlib.h>
#include "ARRAY.h"
#include "STRINGS.h"
#include "MATH.h"

void bubble_sort(int *arr, int size)
{
    int not_sorted = 1;
    for (int i = 1; (i < size) && (not_sorted); i++)
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

void selection_sort(int *arr, int size)
{
    int max = arr[0];
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        max = arr[0];
        index = 0;
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > max)
            {
                max = arr[j];
                index = j;
            }
        }
        swap(&arr[index], &arr[size - i - 1]);
    }
    
}

int main()
{
    int arr[] = {4, 3, 12, 545, 213, 41, 532, 451, 342, 5, -12, -1012, 14, 23};
    int size = ARRAY_SIZE(arr);
    selection_sort(arr, size);
    array_print(arr, &size);
    return 0;
}
