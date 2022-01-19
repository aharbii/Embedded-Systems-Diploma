#include <stdio.h>
#include <stdlib.h>
#include "MATH.h"

void array_print(const int *array_ptr, const int *size)
{
    printf("Array: ");
    for (size_t i = 0; i < *size; i++)
    {
        printf("%2d, ", array_ptr[i]);
    }
    printf("\n");
}

int array_get_index_first(const int *array_ptr, const int *size, const int key)
{
    for (size_t i = 0; i < *size; i++)
    {
        if (array_ptr[i] == key)
        {
            return i;
        }
        
    }
    return -1;
}

int array_delete_primes(int *array_ptr, int *size)
{
    int counter = 0;
    for (size_t i = 0; i < *size; i++)
    {
        /* code */
    }
    
}