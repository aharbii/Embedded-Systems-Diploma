#include <stdio.h>
#include <stdlib.h>
void array_append(int *arr, int *size, int x)
{
    /* O(1) */
    arr[*size] = x;
    *size += 1;
    printf("%d --> ", *size);
}

void array_pop(int *arr, int *size)
{
    /* O(1) */
    *size -= 1;
    printf("%d --> ", *size);
}

void array_print(int *array_ptr, int size)
{
    printf("Array: \n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%2d, ", array_ptr[i]);
    }
    printf("\n");
}

void array_swap(int *first_array, int *first_size, int *second_array, int *second_size)
{
    int temp[100] = {0};
    int temp_size = 0;

    if (*first_size > *second_size)
    {
        int diff = *first_size - *second_size;
        temp_size = *first_size;
        for (int i = 0; i < *first_size; i++)
        {
            temp[i] = first_array[i];
        }
        for (int i = 0; i < diff; i++)
        {
            array_pop(first_array, first_size);
        }

        for (int j = 0; j < *second_size; j++)
        {
            first_array[j] = second_array[j];
        }
        array_print(first_array, *first_size);
        int i = 0;
        for (i; i < *second_size; i++)
        {
            second_array[i] = temp[i];
        }

        for (int j = 0; j < diff; j++)
        {
            array_append(second_array, second_size, temp[j + i]);
        }
    }
}

int main()
{
    int first_array[100] = {2, 3, 5, 12, 4, 7, 8, 9};
    int first_size = 8;
    int second_array[100] = {1, 10, 13, -4, 8};
    int second_size = 5;
    array_swap(first_array, &first_size, second_array, &second_size);
    array_print(first_array, first_size);
    array_print(second_array, second_size);
    return 0;
}