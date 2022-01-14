#include <stdio.h>
#include <stdlib.h>
#include "MATH.h"

void array_print(int *array_ptr, int size)
{
    printf("Array: \n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%2d, ", array_ptr[i]);
    }
    printf("\n");
}

int array_search(int *array_ptr, int size, int to_find)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array_ptr[i] == to_find)
        {
            return i;
        }
    }

    return -1;
}

int array_delete_prime(int *array_ptr, int size)
{
    int counter = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (is_prime(array_ptr[i]))
        {
            counter++;
            array_ptr[i] = 0;
        }
    }
    return counter;
}

void array_print_primes(int *array_ptr, int size)
{
    printf("Prime numbers: \n");
    for (size_t i = 0; i < size; i++)
    {
        if (is_prime(array_ptr[i]))
        {
            printf("%2d, ", array_ptr[i]);
        }
        else
        {
            printf(" 0, ");
        }
    }
    printf("\n");
}

int array_scan(int *array_ptr, int size)
{
    int counter;
    printf("Enter numbers count, not more than %d: ", size);
    scanf("%d", &counter);
    if (counter > size)
    {
        return -1;
    }
    
    for (size_t i = 0; i < counter; i++)
    {
        printf("Element[%d]: ", i);
        scanf("%d", &array_ptr[i]);
    }

    return counter;
}