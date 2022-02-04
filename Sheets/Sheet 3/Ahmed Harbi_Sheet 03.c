/******************************************************************************
 * Sheet.03
 *
 * Problem.01:
 *      --> Write a C function to return the index of LAST occurrence of a 
 *          number in a given array. Array index start from 0. If the item is 
 *          not in the list return -1.
 *
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

int array_get_index_last(const int *array_ptr, const int *size, int key)
{
    /* O(n) */
    for (int i = (*size - 1); i >= 0; i++)
    {
        if (array_ptr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.02:
 *      -->  Write a C function to return the maximum and minimum number in 
 *           an array and their indexes.
 *
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

void array_get_max_min(const int *array_ptr, const int *size, int max_min[2][2])
{
    /* O(n) */
    max_min[0][0] = array_ptr[0];
    max_min[0][1] = 0;
    max_min[1][0] = array_ptr[0];
    max_min[1][1] = 0;
    for (int i = 1; i < *size; i++)
    {
        if (array_ptr[i] > max_min[0][0])
        {
            max_min[0][0] = array_ptr[i];
            max_min[0][1] = i;
        }
        else if (array_ptr[i] < max_min[1][0])
        {
            max_min[1][0] = array_ptr[i];
            max_min[1][1] = i;
        }
    }
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.03:
 *      -->  Write a C function that return 0 if a given number is a power of 
 *           3, otherwise return 1.
 *
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

int is_powerof_three(int number)
{
    int reminder = 0;
    while (number > 1)
    {
        reminder = number % 3;
        number /= 3;
    }

    if ((reminder == 0) && (number != 0))
    {
        return 0;
    }

    return 1;
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.04:
 *      -->  Write a C function that take two numbers and return array contain 
 *           all numbers between the two given numbers. (numbers 2,6->return 
 *           array contain [3,4,5]).
 *
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

int array_get_between(int a, int b, int *array_ptr)
{
    /* O(n) */
    if (a > b)
    {
        swap(&a, &b);
    }
    else if (a == b)
    {
        return 0;
    }

    int size = b - a - 1;
    for (int i = 0; i < size; i++)
    {
        array_ptr[i] = ++a;
    }

    return size;
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.05:
 *      -->  Write c function to find the most repeated number in an array of 
 *           integers.
 *
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

int array_get_most_repeated(const int *array_ptr, const int *size)
{
    /* O(n^2) */
    int key = 0;
    int occurrence = 1;
    int max = 0;

    for (int i = 0; i < *size; i++)
    {
        occurrence = 1;
        for (int j = i; j < *size; j++)
        {
            if (array_ptr[i] == array_ptr[j])
            {
                occurrence++;
            }
        }
        if (occurrence > max)
        {
            max = occurrence;
            key = array_ptr[i];
        }
    }

    return key;
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.06:
 *      -->  Write a C function to take an array and reverse its elements.
 *
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

void array_reverse(int *array_ptr, const int *size)
{
    /* O(n) */
    int reversed[100] = {0};
    for (int i = (*size - 1), j = 0; i >= 0; i--, j++)
    {
        reversed[j] = array_ptr[i];
    }
    for (int i = 0; i < *size; i++)
    {
        array_ptr[i] = reversed[i];
    }
}

void array_reverse_swap(int *array_ptr, const int *size)
{
    /* O(n) */
    for (int i = 0, j = (*size - 1); i < j; i++, j--)
    {
        swap(&array_ptr[i], &array_ptr[j]);
    }
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.07:
 *      -->  Write a C function to take 2 arrays and swap them (try with 2 
 *           different sizes)
 *
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

void array_swap(int *first_array, int *first_size, int *second_array, int *second_size)
{
    /* O(n) */
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
        int i = 0;
        for (; i < *second_size; i++)
        {
            second_array[i] = temp[i];
        }

        for (int j = 0; j < diff; j++)
        {
            array_append(second_array, second_size, temp[j + i]);
        }
    }
    else if (*first_size < *second_size)
    {
        int diff = *second_size - *first_size;
        temp_size = *second_size;
        for (int i = 0; i < *second_size; i++)
        {
            temp[i] = second_array[i];
        }
        for (int i = 0; i < diff; i++)
        {
            array_pop(second_array, second_size);
        }

        for (int j = 0; j < *first_size; j++)
        {
            second_array[j] = first_array[j];
        }
        int i = 0;
        for (; i < *first_size; i++)
        {
            first_array[i] = temp[i];
        }

        for (int j = 0; j < diff; j++)
        {
            array_append(first_array, first_size, temp[j + i]);
        }
    }
    else
    {
        temp_size = *second_size;
        for (int i = 0; i < *second_size; i++)
        {
            temp[i] = second_array[i];
        }
        for (int j = 0; j < *first_size; j++)
        {
            second_array[j] = first_array[j];
        }
        for (int i = 0; i < *first_size; i++)
        {
            first_array[i] = temp[i];
        }
    }
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.08:
 *      -->  Write a C function that return the count of the longest 
 *           consecutive occurrence of a given number in an array.
 *           Array= {1,2,2,3,3,3,3,4,4,4,4,3,3,3} and searching for 
 *           3 -> result = 4.
 *
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

int array_longest_consecutive(int *array_ptr, int *size, int number)
{
    /* O(n^2) */
    int key = 0;
    int occurrence = 0;
    int max = 0;
    for (int i = 0; i < *size; i++)
    {
        if (array_ptr[i] == number)
        {
            occurrence = 0;
            for (int j = i; j < *size; j++)
            {
                if (array_ptr[i] == array_ptr[j])
                {
                    occurrence++;
                }
                else
                {
                    break;
                }
            }
            if (occurrence > max)
            {
                max = occurrence;
                key = array_ptr[i];
            }
        }
    }

    return max;
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.09:
 *      -->  Write a C function that return the count of the longest 
 *           consecutive occurrence of any number ,and return the number
 *           Array={1,2,2,3,3,3,3,4,4,4,4,4,3,3,3} result -> 5 ,number -> 4.
 *
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

int array_most_repeated_consecutive(int *array_ptr, int *size)
{
    /* O(n^2) */
    int key = 0;
    int occurrence = 0;
    int max = 0;
    for (int i = 0; i < *size; i++)
    {
        occurrence = 0;
        for (int j = i; j < *size; j++)
        {
            if (array_ptr[i] == array_ptr[j])
            {
                occurrence++;
            }
            else
            {
                break;
            }
        }
        if (occurrence > max)
        {
            max = occurrence;
            key = array_ptr[i];
        }
    }
    return key;
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.10:
 *      -->  Write c function to take 2 arrays and return an array by merging 
 *           them like this ( arr1={1,2,3,4,5},arr2={11,12,13,14,15} return 
 *           arr3={1,11,2,12,3,13,4,14,5,15} ).
 *
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

void array_merge(int *first_array, int first_size, int *second_array, int second_size, int *merged, int *merged_size)
{
    /* O(m + n) */
    int i = 0;
    int j = 0;
    int k = 0;
    while ((i < first_size) && (j < second_size))
    {
        merged[k++] = first_array[i++];
        merged[k++] = second_array[j++];
    }

    while (i < first_size)
    {
        merged[k++] = first_array[i++];
    }

    while (j < second_size)
    {
        merged[k++] = second_array[j++];
    }
    *merged_size = k;
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.11:
 *      -->  Write a c function that removes the repeated number of an input
 *           sorted array and return a new array without the repeated numbers
 *
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

void array_remove_duplicate_sorted(int *array_ptr, int *size)
{
    /* O(n) */
    int duplicated = 0;
    for (int i = 1; i < *size; i++)
    {
        if (array_ptr[i] == array_ptr[i - 1])
        {
            array_delete(array_ptr, size, i);
            i--;
        }
    }
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.12:
 *      -->  Write c function to take an array (with unknown size) contain 2 
 *           zeros swap the 3 element after the first zero with the 3 element 
 *           after the second zero ( x,x,x,0,1,2,3,xxxx,0,5,6,7,xxxx 
 *           ->swap 1,2,3with 5,6,7).
 * 
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

void array_swap_after_zero(int *array_ptr)
{
    int i = 0;
    while (array_ptr[i] != 0)
    {
        i++;
    }
    int j = i + 1;

    while (array_ptr[j] != 0)
    {
        j++;
    }

    for (int k = 0; k < 3; k++)
    {
        swap(&array_ptr[++i], &array_ptr[++j]);
    }
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.13:
 *      -->  Write c function to take an array and return the biggest difference
 *           between 2 numbers in the array (the smaller number must come first 
 *           in the array) {10,1,5,3,6,8,7,2}->return 7 difference between 1,8.
 *
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

int array_get_greatest_difference(const int *array_ptr, const int *size)
{
    int min = array_get_min(array_ptr, size);
    int index = 0;

    while (array_ptr[index] != min)
    {
        index++;
    }

    int new_size = *size - 1;

    if (index == (*size - 1))
    {
        return array_get_greatest_difference(array_ptr, &new_size);
    }

    new_size = *size - index;
    int max = array_get_max(&array_ptr[index], &new_size);
    int greatest_diff = max - min;

    return greatest_diff;
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.14:
 *      -->  Write c function to find the most repeated number in an array of 
 *           char (size of the array is very large) try to optimize your code.
 * 
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

char array_get_most_repeated_character(const char *array_ptr, const int *size)
{
    int hash_table[128] = {0};
    for (int i = 0; i < *size; i++)
    {
        hash_table[(int)array_ptr[i]] += 1;
    }

    int hash_size = 128;
    char most_repeated = array_get_max_index(hash_table, &hash_size);

    return most_repeated;
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.15:
 *      -->  Write a C Function that swaps two pointers.
 * 
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

void swap_ptr(int **first_ptr, int **second_ptr)
{
    int *temp = *first_ptr;
    *first_ptr = *second_ptr;
    *second_ptr = temp;
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.16:
 *      -->  Write a C function to get the nth term of Fibonacci series, 
 *           and use it to print the first 20 element.
 *
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

int fibonacci_iter(int n)
{
    /* O(n) */
    int t0 = 0;
    int t1 = 1;
    if (n <= 1)
    {
        return n;
    }
    int s;
    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

/******************************************************************************
 * Sheet.03
 *
 * Problem.17:
 *      -->  Write a C function to take 10 mono numbers (from 0to 9) from user 
 *           and return the most repeated one, if user enter number bigger than 
 *           9 return -1(don’t use arrays).
 *
 * @author: Ahmed Harbi
 * @date:   Jan 19th, 2022
 ******************************************************************************/

int array_get_most_repeated_mono(const int *array_ptr, const int *size)
{
    int hash_table[10] = {0};
    for (int i = 0; i < *size; i++)
    {
        hash_table[array_ptr[i]] += 1;
    }

    int hash_size = 10;
    int max = array_get_max_index(hash_table, &hash_size);

    return max;
}
