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

int array_get_index_first(const int *array_ptr, const int *size, int key)
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
        if (is_prime(array_ptr[i]))
        {
            counter++;
            array_ptr[i] = 0;
            for (i; i < (*size - 1); i++)
            {
                array_ptr[i] = array_ptr[i + 1];
            }
            *size -= 1;
        }
    }
    return counter;
}

void array_print_primes(const int *array_ptr, const int *size)
{
    printf("Prime numbers: \n");
    for (size_t i = 0; i < size; i++)
    {
        if (is_prime(array_ptr[i]))
        {
            printf("%2d, ", array_ptr[i]);
        }
    }
    printf("\n");
}

int array_scan(int *array_ptr, int *size)
{
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

int array_get_index_last(const int *array_ptr, const int *size, int key)
{
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

void array_print_2d(const int *array_ptr, const int *rows, const int *cols)
{
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

int array_get_between(int a, int b, int *array_ptr)
{
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

int array_get_most_repeated(const int *array_ptr, const int *size)
{
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

int array_longest_consecutive(int *array_ptr, int size, int number)
{
    int key = 0;
    int occurrence = 0;
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (array_ptr[i] == number)
        {
            occurrence = 0;
            for (int j = i; j < size; j++)
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

void array_most_repeated_consecutive(int *array_ptr, int size, int *value, int *repeats)
{
    int key = 0;
    int occurrence = 0;
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        occurrence = 0;
        for (int j = i; j < size; j++)
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

void merge_array(int *first_array, int first_size, int *second_array, int second_size, int *merged, int *merged_size)
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

void insert(Array *arr, int index, int value)
{
    /* O(n) */
    if ((index >= 0) && (index <= arr->length))
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = value;
        arr->length++;
    }
}

int delete_element(Array *arr, int index)
{
    /* O(n) */
    int x = 0;
    if ((index >= 0) && (index <= arr->length))
    {
        x = arr->A[index];
        arr->A[index] = 0;
        for (int i = index; i < (arr->length - 1); i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int linear_search(Array *arr, int key)
{
    /* O(n) */
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            return i;
        }
    }
    return -1;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int improved_linear_search(Array *arr, int key)
{
    /* O(n) */
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int binary_search(Array *arr, int key)
{
    /* O(log(n)) */
    int l = 0;
    int h = arr->length - 1;
    while ((l <= h))
    {
        int mid = (h + l) / 2;
        if (arr->A[mid] == key)
        {
            return mid;
        }
        else if (arr->A[mid] > key)
        {
            h = mid - 1;
        }
        else if (arr->A[mid] < key)
        {
            l = mid + 1;
        }
    }
    return -1;
}

int binary_search_recursive(Array *arr, int l, int h, int key)
{
    /* O(log(n)) */
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr->A[mid] == key)
        {
            return mid;
        }
        else if (arr->A[mid] > key)
        {
            return binary_search_recursive(arr, l, mid - 1, key);
        }
        else if (arr->A[mid] < key)
        {
            return binary_search_recursive(arr, mid + 1, h, key);
        }
    }
    return -1;
}

int get(const Array *arr, int index)
{
    /* O(1) */
    if ((index >= 0) && (index <= arr->length))
    {
        return arr->A[index];
    }
    return -1;
}

void set(Array *arr, int index, int key)
{
    /* O(1) */
    if ((index >= 0) && (index <= arr->length))
    {
        arr->A[index] = key;
    }
}

int get_max(const Array *arr)
{
    /* O(n) */
    int max = arr->A[0];
    for (int i = 1; i < arr->length; i++)
    {
        if (max < arr->A[i])
        {
            max = arr->A[i];
        }
    }
    return max;
}

int get_min(const Array *arr)
{
    /* O(n) */
    int min = arr->A[0];
    for (int i = 0; i < arr->length; i++)
    {
        if (min > arr->A[i])
        {
            min = arr->A[i];
        }
    }
    return min;
}

int get_sum(const Array *arr)
{
    /* O(n) */
    int sum = 0;
    for (int i = 0; i < arr->length; i++)
    {
        sum += arr->A[i];
    }
    return sum;
}

int get_sum_recursive(const Array *arr, int n)
{
    /* O(n) */
    if (n < 0)
    {
        return 0;
    }

    return arr->A[n] + get_sum_recursive(arr, n - 1);
}

double get_average(const Array *arr)
{
    /* O(n) */
    int total = 0;
    for (int i = 0; i < arr->length; i++)
    {
        total += arr->A[i];
    }

    double average = (double)total / arr->length;
    return average;
}

void reverse(Array *arr)
{
    /* O(n) */
    Array B = {
        .A = {0},
        .length = arr->length,
        .size = arr->size};
    for (int i = (arr->length - 1), j = 0; i >= 0; i--, j++)
    {
        B.A[j] = arr->A[i];
    }

    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B.A[i];
    }
}

void reverse_swap(Array *arr)
{
    /* O(n) */
    for (int i = 0, j = (arr->length - 1); i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void insert_sorted(Array *arr, int value)
{
    /* O(n) */
    int i = arr->length - 1;
    while ((arr->A[i] > value) && (i >= 0))
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = value;
    arr->length++;
}

int is_sorted(Array *arr)
{
    /* O(n) */
    for (int i = 0; i < (arr->length - 1); i++)
    {
        if (arr->A[i] > arr->A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void rearrange(Array *arr)
{
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

void merge_array(const Array *A, const Array *B, Array *C)
{
    /* O(m + n) */
    int i = 0;
    int j = 0;
    int k = 0;
    while ((i < A->length) && (j < B->length))
    {
        if (A->A[i] < B->A[j])
        {
            C->A[k++] = A->A[i++];
        }
        else
        {
            C->A[k++] = B->A[j++];
        }
    }

    while (i < A->length)
    {
        C->A[k++] = A->A[i++];
    }
    while (j < B->length)
    {
        C->A[k++] = B->A[j++];
    }
    C->length = k;
    C->size = k * sizeof(int);
}

void union_array(const Array *A, const Array *B, Array *C)
{
    /* O(n^2) */
    int i = 0;
    int j = 0;
    int k = 0;
    C->length = 0;
    for (int i = 0; i < A->length; i++)
    {
        C->A[k++] = A->A[i];
        C->length++;
    }

    for (int i = 0; i < B->length; i++)
    {
        int is_found = 0;
        for (int j = 0; (j < C->length) && (!is_found); j++)
        {
            if (B->A[i] == C->A[j])
            {
                is_found = 1;
            }
        }

        if (!is_found)
        {
            C->A[k++] = B->A[i];
            C->length++;
        }
    }
}

void union_array_sorted(const Array *A, const Array *B, Array *C)
{
    /* O(n^2) */
    int i = 0;
    int j = 0;
    int k = 0;
    C->length = 0;
    while ((i < A->length) && (j < B->length))
    {
        if (A->A[i] < B->A[j])
        {
            C->A[k++] = A->A[i++];
            C->length++;
        }
        else if (A->A[i] == B->A[j])
        {
            C->A[k++] = B->A[i++];
            j++;
            C->length++;
        }
        else if (A->A[i] > B->A[j])
        {
            C->A[k++] = B->A[j++];
            C->length++;
        }
    }

    while (i < A->length)
    {
        C->A[k++] = A->A[i++];
        C->length++;
    }
    while (j < B->length)
    {
        C->A[k++] = B->A[j++];
        C->length++;
    }
}

void intersection_array(const Array *A, const Array *B, Array *C)
{
    /* O(n^2) */
    C->length = 0;
    int k = 0;
    for (int i = 0; i < A->length; i++)
    {
        for (int j = 0; j < B->length; j++)
        {
            if (A->A[i] == B->A[j])
            {
                C->A[k++] = A->A[i];
                C->length++;
            }
        }
    }
}

void intersection_array_sorted(const Array *A, const Array *B, Array *C)
{
    /* O(n) */
    int i = 0;
    int j = 0;
    int k = 0;
    C->length = 0;
    while ((i < A->length) && (j < B->length))
    {
        if (A->A[i] == B->A[j])
        {
            C->A[k++] = A->A[i++];
            j++;
            C->length++;
        }
        else if (A->A[i] < B->A[j])
        {
            i++;
        }
        else if (A->A[i] > B->A[j])
        {
            j++;
        }
    }
}

void difference_array(const Array *A, const Array *B, Array *C)
{
    /* O(n^2) */
    C->length = 0;
    int k = 0;
    for (int i = 0; i < A->length; i++)
    {
        int is_found = 0;
        for (int j = 0; (j < B->length) && (!is_found); j++)
        {
            if (A->A[i] == B->A[j])
            {
                is_found = 1;
            }
        }
        if (!is_found)
        {
            C->A[k++] = A->A[i];
            C->length++;
        }
    }
}

void difference_array_sorted(const Array *A, const Array *B, Array *C)
{
    /* O(n) */
    int i = 0;
    int j = 0;
    int k = 0;
    C->length = 0;
    while (i < A->length)
    {
        if (A->A[i] == B->A[j])
        {
            i++;
            j++;
        }
        else if (A->A[i] < B->A[j])
        {
            C->A[k++] = A->A[i++];
            C->length++;
        }
        else if (A->A[i] > B->A[j])
        {
            j++;
        }
    }
    while (i < A->length)
    {
        C->A[k++] = A->A[i++];
        C->length++;
    }
}

int get_sum(const Array *arr)
{
    /* O(n) */
    int actual_sum = 0;
    for (int i = 0; i < arr->length; i++)
    {
        actual_sum += arr->A[i];
    }
    return actual_sum;
}

int sum_formula(int n)
{
    /* O(1) */
    int sum = (n * (n + 1)) / 2;
    return sum;
}

int get_sum_sequence(const Array *arr)
{
    /* O(1) */
    int max = arr->A[arr->length - 1];
    int min = arr->A[0];
    return sum_formula(max) - sum_formula(min - 1);
}

int get_missing_sorted(const Array *arr)
{
    /* O(n) */
    int actual_sum = get_sum(arr);
    int expected_sum = get_sum_sequence(arr);
    int missing = expected_sum - actual_sum;
    return missing;
}

int get_missing_diff(const Array *arr)
{
    /* O(n) */
    int diff = arr->A[0] - 0;
    for (int i = 0; i < arr->length; i++)
    {
        int current_diff = arr->A[i] - i;
        if (current_diff != diff)
        {
            while (diff < arr->A[i] - i)
            {
                printf("%d\n", i + diff);
                diff += 1;
            }
        }
    }
    return -1;
}

int get_max(const Array *arr)
{
    /* O(n) */
    int max = arr->A[0];
    for (int i = 1; i < arr->length; i++)
    {
        if (max < arr->A[i])
        {
            max = arr->A[i];
        }
    }
    return max;
}

void get_missing_unsorted(const Array *arr)
{
    /* O(n) */
    int max = get_max(arr);
    int *hash_table = (int *)calloc(max, sizeof(int));
    for (int i = 0; i < max; i++)
    {
        hash_table[i] = 0;
    }

    for (int i = 0; i < arr->length; i++)
    {
        hash_table[arr->A[i]] += 1;
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

void get_duplicate_sorted(const Array *arr)
{
    /* O(n) */
    int duplicated = 0;
    for (int i = 1; i < arr->length; i++)
    {

        if (arr->A[i] == arr->A[i - 1])
        {
            if (arr->A[i] != duplicated)
            {
                duplicated = arr->A[i];
                printf("%d\n", arr->A[i]);
            }
        }
    }
}

void get_duplicate_hash(const Array *arr)
{
    /* O(n) */
    int max = get_max(arr) + 1;
    int *hash_table = (int *)calloc(max, sizeof(int));
    for (int i = 0; i < max; i++)
    {
        hash_table[i] = 0;
    }

    for (int i = 0; i < arr->length; i++)
    {
        hash_table[arr->A[i]] += 1;
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

void pair_with_sum(const Array *arr, int sum)
{
    /* O(n^2) */
    for (int i = 0; i < arr->length; i++)
    {
        for (int j = i + 1; j < arr->length; j++)
        {
            if ((arr->A[i] + arr->A[j]) == sum)
            {
                printf("%d --> %d\n", arr->A[i], arr->A[j]);
            }
        }
    }
}

void pair_with_sum_hashing(const Array *arr, int sum)
{
    /* O(n) */
    int max = get_max(arr) + 1;
    int *hash_table = (int *)calloc(max, sizeof(int));
    for (int i = 0; i < max; i++)
    {
        hash_table[i] = 0;
    }

    for (int i = 0; i < arr->length; i++)
    {
        int need = sum - arr->A[i];
        if (hash_table[need] == 1)
        {
            printf("%d + %d = %d\n", arr->A[i], need, sum);
        }
        hash_table[arr->A[i]] += 1;
    }

    free(hash_table);
}

void pair_with_sum_sorted(const Array *arr, int sum)
{
    /* O(n) */
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        if ((arr->A[i] + arr->A[j]) == sum)
        {
            printf("%d + %d = %d\n", arr->A[i], arr->A[j], sum);
            i++;
            j--;
        }
        else if ((arr->A[i] + arr->A[j]) > sum)
        {
            j--;
        }
        else if ((arr->A[i] + arr->A[j]) < sum)
        {
            i++;
        }
    }
}
