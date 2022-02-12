#include <stdio.h>
#include <stdlib.h>
#include "ARRAY.h"
#include "STRINGS.h"
#include "MATH.h"

int get_solo(const int *array_ptr, int l, int h)
{

    int mid = (l + h) / 2;
    if ((array_ptr[mid] != array_ptr[mid + 1]) && (array_ptr[mid] != array_ptr[mid - 1]))
    {
        return array_ptr[mid];
    }
    if ((mid % 2) == 0)
    {
        if (array_ptr[mid] == array_ptr[mid + 1])
        {
            return get_solo(array_ptr, mid + 1, h);
        }
        else
        {
            return get_solo(array_ptr, l, mid - 1);
        }
    }
    else
    {
        if (array_ptr[mid] == array_ptr[mid - 1])
        {
            return get_solo(array_ptr, mid + 1, h);
        }
        else
        {
            return get_solo(array_ptr, l, mid - 1);
        }
    }
}

int main()
{
    int arr[] = {1, 1, 2, 2, 4, 4, 70, 70, 73, 73, 80, 80, 81};
    int size = ARRAY_SIZE(arr);
    printf("%d\n", get_solo(arr, 0, size - 1));
    return 0;
}
