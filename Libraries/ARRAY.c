#include <stdio.h>
#include <stdlib.h>
#include "MATH.h"

void array_print(const int *array_ptr, const int *size)
{
    /* O(n) */
    printf("Array: ");
    for (int i = 0; i < *size; i++)
    {
        printf("%2d, ", array_ptr[i]);
    }
    printf("\n");
}

void matrix_print_2d(const int *array_ptr, const int *rows, const int *cols)
{
    /* O(n) */
    printf("Array: \n\t");
    for (int i = 0; i < *rows; i++)
    {
        for (int j = 0; j < *cols; j++)
        {
            printf("%2d, ", *((array_ptr + i * (*cols))+j));
        }
        printf("\n\t");
    }
    printf("\n");
}

int array_scan(int *array_ptr, int *size)
{
    /* O(n) */
    int counter;
    printf("Enter numbers count, not more than %d: ", *size);
    scanf("%d", &counter);
    if (counter > *size)
    {
        return -1;
    }
    
    for (int i = 0; i < counter; i++)
    {
        printf("Element[%d]: ", i);
        scanf("%d", &array_ptr[i]);
    }

    return counter;
}

int array_get_index_first(const int *array_ptr, const int *size, int key)
{
    /* O(n) */
    for (int i = 0; i < *size; i++)
    {
        if (array_ptr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

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

int array_get_between(int a, int b, int *array_ptr)
{
    /* O(n) */
    if (a > b)
    {
        swap(&a, &b);
    }
    else if(a == b)
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

void array_print_primes(const int *array_ptr, const int *size)
{
    /* O(n) */
    printf("Prime numbers: \n");
    for (int i = 0; i < *size; i++)
    {
        if (is_prime(array_ptr[i]))
        {
            printf("%2d, ", array_ptr[i]);
        }
    }
    printf("\n");
}

int array_get_most_repeated(const int *array_ptr, const int *size)
{
    /* O(n^2) */
    int key = 0;
    int occurrence = 0;
    int max = 0;

    for (int i = 0; i < *size; i++)
    {
        occurrence = 0;
        for (int j = 0; j < *size; j++)
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

void array_append(int *array_ptr, int *size, const int key)
{
    /* O(1) */
    array_ptr[*size] = key;
    *size += 1;
}

void array_pop(int *array_ptr, int *size)
{
    /* O(1) */
    array_ptr[*size - 1] = 0;
    *size -= 1;
}

int array_delete(int *array_ptr, int *size, int index)
{
    /* O(n) */
    int x = 0;
    if ((index >= 0) && (index <= *size - 1))
    {
        x = array_ptr[index];
        array_ptr[index] = 0;
        for (int i = index; i < (*size - 1); i++)
        {
            array_ptr[i] = array_ptr[i + 1];
        }
        *size -= 1;
        return x;
    }
    return 0;
}

int array_delete_primes(int *array_ptr, int *size)
{
    /* O(n) */
    int counter = 0;
    for (int i = 0; i < *size; i++)
    {
        if (is_prime(array_ptr[i]))
        {
            array_delete(array_ptr, size, i);
            counter++;
        }
    }
    return counter;
}

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

int array_longest_consecutive(int *array_ptr, int *size, int number)
{
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

void array_most_repeated_consecutive(int *array_ptr, int *size, int *value, int *repeats)
{
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
    *value = key;
    *repeats = max;
}

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

void array_insert(int *array_ptr, int *size,int index, int key)
{
    /* O(n) */
    if ((index >= 0) && (index <= *size))
    {
        for (int i = *size; i > index; i--)
        {
            array_ptr[i] = array_ptr[i - 1];
        }
        array_ptr[index] = key;
        *size += 1;
    }
}

int array_linear_search(const int *array_ptr, const int *size, int key)
{
    /* O(n) */
    for (int i = 0; i < *size; i++)
    {
        if (key == array_ptr[i])
        {
            return i;
        }
    }
    return -1;
}

int array_improved_linear_search(int *array_ptr, int *size, int key)
{
    /* O(n) */
    for (int i = 0; i < *size; i++)
    {
        if (key == array_ptr[i])
        {
            swap(&array_ptr[i], &array_ptr[0]);
            return i;
        }
    }
    return -1;
}

int array_binary_search(const int *array_ptr, const int *size, int key)
{
    /* O(log(n)) */
    int l = 0;
    int h = *size - 1;
    while ((l <= h))
    {
        int mid = (h + l) / 2;
        if (array_ptr[mid] == key)
        {
            return mid;
        }
        else if (array_ptr[mid] > key)
        {
            h = mid - 1;
        }
        else if (array_ptr[mid] < key)
        {
            l = mid + 1;
        }
    }
    return -1;
}

int array_binary_search_recursive(const int *array_ptr, const int *size, int l, int h, int key)
{
    /* O(log(n)) */
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (array_ptr[mid] == key)
        {
            return mid;
        }
        else if (array_ptr[mid] > key)
        {
            return array_binary_search_recursive(array_ptr, size, l, mid - 1, key);
        }
        else if (array_ptr[mid] < key)
        {
            return array_binary_search_recursive(array_ptr, size, mid + 1, h, key);
        }
    }
    return -1;
}

int array_at(const int *array_ptr, const int *size, int index)
{
    /* O(1) */
    if ((index >= 0) && (index <= *size))
    {
        return array_ptr[index];
    }

    return -1;
}

void array_set(int *array_ptr, int *size, int index, int key)
{
    /* O(1) */
    if ((index >= 0) && (index <= *size))
    {
        array_ptr[index] = key;
    }
}

int array_get_max(const int *array_ptr, const int *size)
{
    /* O(n) */
    int max = array_ptr[0];
    for (int i = 1; i < *size; i++)
    {
        if (max < array_ptr[i])
        {
            max = array_ptr[i];
        }
    }
    return max;
}

int array_get_min(const int *array_ptr, const int *size)
{
    /* O(n) */
    int min = array_ptr[0];
    for (int i = 0; i < *size; i++)
    {
        if (min > array_ptr[i])
        {
            min = array_ptr[i];
        }
    }
    return min;
}

int array_get_sum(const int *array_ptr, const int *size)
{
    /* O(n) */
    int sum = 0;
    for (int i = 0; i < *size; i++)
    {
        sum += array_ptr[i];
    }
    return sum;
}

int array_get_sum_recursive(const int *array_ptr, const int *size, int n)
{
    /* O(n) */
    if (n < 0)
    {
        return 0;
    }

    return array_ptr[n] + array_get_sum_recursive(array_ptr, size, n - 1);
}

double array_get_average(const int *array_ptr, const int *size)
{
    /* O(n) */
    int total = 0;
    for (int i = 0; i < *size; i++)
    {
        total += array_ptr[i];
    }

    double average = (double)total / (*size);
    return average;
}

void array_insert_sorted(int *array_ptr, int *size, int value)
{
    /* O(n) */
    int i = *size - 1;
    while ((array_ptr[i] > value) && (i >= 0))
    {
        array_ptr[i + 1] = array_ptr[i];
        i--;
    }
    array_ptr[i + 1] = value;
    *size += 1;
}

int array_is_sorted(int *array_ptr, int *size)
{
    /* O(n) */
    for (int i = 0; i < (*size - 1); i++)
    {
        if (array_ptr[i] > array_ptr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void array_rearrange(int *array_ptr, int *size)
{
    int i = 0;
    int j = *size - 1;
    while (i < j)
    {
        while (array_ptr[i] < 0)
        {
            i++;
        }
        while (array_ptr[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(&array_ptr[i], &array_ptr[j]);
        }
    }
}

void array_union(const int *first_array, const int *first_size, const int *second_array, const int *second_size, int *array_ptr, int *size)
{
    /* O(n^2) */
    int i = 0;
    int j = 0;
    int k = 0;
    *size = 0;
    for (int i = 0; i < *first_size; i++)
    {
        array_ptr[k++] = first_array[i];
        *size += 1;
    }

    for (int i = 0; i < *second_size; i++)
    {
        int is_found = 0;
        for (int j = 0; (j < *size) && (!is_found); j++)
        {
            if (second_array[i] == array_ptr[j])
            {
                is_found = 1;
            }
        }

        if (!is_found)
        {
            array_ptr[k++] = second_array[i];
            *size += 1;
        }
    }
}

void array_union_sorted(const int *first_array, const int *first_size, const int *second_array, const int *second_size, int *array_ptr, int *size)
{
    /* O(n^2) */
    int i = 0;
    int j = 0;
    int k = 0;
    *size = 0;
    while ((i < *first_size) && (j < *second_size))
    {
        if (first_array[i] < second_array[j])
        {
            array_ptr[k++] = first_array[i++];
            *size += 1;
        }
        else if (first_array[i] == second_array[j])
        {
            array_ptr[k++] = second_array[i++];
            j++;
            *size += 1;
        }
        else if (first_array[i] > second_array[j])
        {
            array_ptr[k++] = second_array[j++];
            *size += 1;
        }
    }

    while (i < *first_size)
    {
        array_ptr[k++] = first_array[i++];
        *size += 1;
    }
    while (j < *second_size)
    {
        array_ptr[k++] = second_array[j++];
        *size += 1;
    }
}

void array_intersection(const int *first_array, const int *first_size, const int *second_array, const int *second_size, int *array_ptr, int *size)
{
    /* O(n^2) */
    *size = 0;
    int k = 0;
    for (int i = 0; i < *first_size; i++)
    {
        for (int j = 0; j < *second_size; j++)
        {
            if (first_array[i] == second_array[j])
            {
                array_ptr[k++] = first_array[i];
                *size += 1;
            }
        }
    }
}

void array_intersection_sorted(const int *first_array, const int *first_size, const int *second_array, const int *second_size, int *array_ptr, int *size)
{
    /* O(n) */
    int i = 0;
    int j = 0;
    int k = 0;
    *size = 0;
    while ((i < *first_size) && (j < *second_size))
    {
        if (first_array[i] == second_array[j])
        {
            array_ptr[k++] = first_array[i++];
            j++;
            *size += 1;
        }
        else if (first_array[i] < second_array[j])
        {
            i++;
        }
        else if (first_array[i] > second_array[j])
        {
            j++;
        }
    }
}

void array_difference(const int *first_array, const int *first_size, const int *second_array, const int *second_size, int *array_ptr, int *size)
{
    /* O(n^2) */
    *size = 0;
    int k = 0;
    for (int i = 0; i < *first_size; i++)
    {
        int is_found = 0;
        for (int j = 0; (j < *second_size) && (!is_found); j++)
        {
            if (first_array[i] == second_array[j])
            {
                is_found = 1;
            }
        }
        if (!is_found)
        {
            array_ptr[k++] = first_array[i];
            *size += 1;
        }
    }
}

void array_difference_sorted(const int *first_array, const int *first_size, const int *second_array, const int *second_size, int *array_ptr, int *size)
{
    /* O(n) */
    int i = 0;
    int j = 0;
    int k = 0;
    *size = 0;
    while (i < *first_size)
    {
        if (first_array[i] == second_array[j])
        {
            i++;
            j++;
        }
        else if (first_array[i] < second_array[j])
        {
            array_ptr[k++] = first_array[i++];
            *size += 1;
        }
        else if (first_array[i] > second_array[j])
        {
            j++;
        }
    }
    while (i < *first_size)
    {
        array_ptr[k++] = first_array[i++];
        *size += 1;
    }
}

int array_get_sum_sequence(const int *array_ptr, const int *size)
{
    /* O(1) */
    int max = array_ptr[*size - 1];
    int min = array_ptr[0];
    return sum_formula(max) - sum_formula(min - 1);
}

int array_get_missing_sorted(const int *array_ptr, const int *size)
{
    /* O(n) */
    int actual_sum = array_get_sum(array_ptr, size);
    int expected_sum = array_get_sum_sequence(array_ptr, size);
    int missing = expected_sum - actual_sum;
    return missing;
}

int array_get_missing_diff(const int *array_ptr, const int *size)
{
    /* O(n) */
    int diff = array_ptr[0] - 0;
    for (int i = 0; i < *size; i++)
    {
        int current_diff = array_ptr[i] - i;
        if (current_diff != diff)
        {
            while (diff < array_ptr[i] - i)
            {
                printf("%d\n", i + diff);
                diff += 1;
            }
        }
    }
    return -1;
}

void array_get_missing_unsorted(const int *array_ptr, const int *size)
{
    /* O(n) */
    int max = array_get_max(array_ptr, size);
    int *hash_table = (int *)calloc(max, sizeof(int));
    for (int i = 0; i < max; i++)
    {
        hash_table[i] = 0;
    }

    for (int i = 0; i < *size; i++)
    {
        hash_table[array_ptr[i]] += 1;
    }

    for (int i = 1; i < max; i++)
    {
        if (hash_table[i] == 0)
        {
            printf("%d\n", i);
        }
    }

    free(hash_table);
}

void array_get_duplicate_sorted(const int *array_ptr, const int *size)
{
    /* O(n) */
    int duplicated = 0;
    for (int i = 1; i < *size; i++)
    {

        if (array_ptr[i] == array_ptr[i - 1])
        {
            if (array_ptr[i] != duplicated)
            {
                duplicated = array_ptr[i];
                printf("%d\n", array_ptr[i]);
            }
        }
    }
}

void array_get_duplicate_hash(const int *array_ptr, const int *size)
{
    /* O(n) */
    int max = array_get_max(array_ptr, size) + 1;
    int *hash_table = (int *)calloc(max, sizeof(int));
    for (int i = 0; i < max; i++)
    {
        hash_table[i] = 0;
    }

    for (int i = 0; i < *size; i++)
    {
        hash_table[array_ptr[i]] += 1;
    }

    for (int i = 0; i < max; i++)
    {
        if (hash_table[i] > 1)
        {
            printf("%d --> %d\n", i, hash_table[i]);
        }
    }

    free(hash_table);
}

void array_pair_with_sum(const int *array_ptr, const int *size, int sum)
{
    /* O(n^2) */
    for (int i = 0; i < *size; i++)
    {
        for (int j = i + 1; j < *size; j++)
        {
            if ((array_ptr[i] + array_ptr[j]) == sum)
            {
                printf("%d --> %d\n", array_ptr[i], array_ptr[j]);
            }
        }
    }
}

void array_pair_with_sum_hashing(const int *array_ptr, const int *size, int sum)
{
    /* O(n) */
    int max = array_get_max(array_ptr, size) + 1;
    int *hash_table = (int *)calloc(max, sizeof(int));
    for (int i = 0; i < max; i++)
    {
        hash_table[i] = 0;
    }

    for (int i = 0; i < *size; i++)
    {
        int need = sum - array_ptr[i];
        if (hash_table[need] == 1)
        {
            printf("%d + %d = %d\n", array_ptr[i], need, sum);
        }
        hash_table[array_ptr[i]] += 1;
    }

    free(hash_table);
}

void array_pair_with_sum_sorted(const int *array_ptr, const int *size, int sum)
{
    /* O(n) */
    int i = 0;
    int j = *size - 1;
    while (i < j)
    {
        if ((array_ptr[i] + array_ptr[j]) == sum)
        {
            printf("%d + %d = %d\n", array_ptr[i], array_ptr[j], sum);
            i++;
            j--;
        }
        else if ((array_ptr[i] + array_ptr[j]) > sum)
        {
            j--;
        }
        else if ((array_ptr[i] + array_ptr[j]) < sum)
        {
            i++;
        }
    }
}

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
