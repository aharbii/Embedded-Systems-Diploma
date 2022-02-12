#include "SORTING.h"

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
    for (int i = 0; i < size; i++)
    {
        int new_size = size - i;
        int index = array_get_max_index(arr, &new_size);
        swap(&arr[index], &arr[size - i - 1]);
    }
}