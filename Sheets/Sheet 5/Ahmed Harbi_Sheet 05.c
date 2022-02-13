/******************************************************************************
 * Sheet.05
 *
 * Problem.01:
 *      --> You have an array of 100 element contain all number from 0 t0 100
 *          except one number, write c function to find the missed number
 *          (try in O(n)).
 *
 * @author: Ahmed Harbi
 * @date:   Feb 12th, 2022
 ******************************************************************************/

int get_missing(const int *array_ptr)
{
    int hash_table[101] = {0};

    for (int i = 0; i < 100; i++)
    {
        hash_table[array_ptr[i]] = 1;
    }

    for (int i = 0; i < 101; i++)
    {
        if (hash_table[i] == 0)
        {
            return i;
        }
    }

    return -1;
}

/******************************************************************************
 * Sheet.05
 *
 * Problem.02:
 *      -->  You have an array of 101 element contain all number from 1 t0 100,
 *           so one number is repeated, write c function to find the repeated
 *           number (try in O(n)).
 *
 * @author: Ahmed Harbi
 * @date:   Feb 12th, 2022
 ******************************************************************************/

int get_repeated(const int *array_ptr)
{
    int hash_table[100] = {0};

    for (int i = 0; i < 101; i++)
    {
        hash_table[array_ptr[i]] += 1;
    }

    for (int i = 0; i < 100; i++)
    {
        if (hash_table[i] > 1)
        {
            return i + 1;
        }
    }

    return -1;
}

/******************************************************************************
 * Sheet.05
 *
 * Problem.03:
 *      -->  You have an array of integers all numbers in the array repeated 2
 *           times except one number repeated one time only find this
 *           number (try o(n)). array like {1,2,4,66,2,1,500,66,7,7,500}->4.
 *
 * @author: Ahmed Harbi
 * @date:   Feb 12th, 2022
 ******************************************************************************/

int get_max(const int *array_ptr, const int array_size)
{
    int max = array_ptr[0];

    for (int i = 1; i < array_size; i++)
    {
        if (array_ptr[i] > max)
        {
            max = array_ptr[i];
        }
    }

    return max;
}

int get_min(const int *array_ptr, const int array_size)
{
    int min = array_ptr[0];

    for (int i = 1; i < array_size; i++)
    {
        if (array_ptr[i] < min)
        {
            min = array_ptr[i];
        }
    }

    return min;
}

int get_solo(const int *array_ptr, const int array_size)
{
    int max = get_max(array_ptr, array_size);
    int min = get_min(array_ptr, array_size);

    int hash_size = max - min + 1;
    int *hash_table = (int *)calloc(hash_size, sizeof(int));

    for (int i = 0; i < array_size; i++)
    {
        hash_table[array_ptr[i] - min] += 1;
    }

    int solo_number = -1;
    int not_found = 1;

    for (int i = 0; (i < hash_size) && (not_found); i++)
    {
        if (hash_table[i] == 1)
        {
            solo_number = i + min;
            not_found = 0;
        }
    }

    free(hash_table);

    return solo_number;
}

/******************************************************************************
 * Sheet.05
 *
 * Problem.04:
 *      -->  repeat Q3 but array is sorted (try less than O(n)).
 *           array {1,1,2,2,4,4,70,70,73,80,80,81,81} ->73.
 *
 * @author: Ahmed Harbi
 * @date:   Feb 12th, 2022
 ******************************************************************************/

int get_solo_sorted(const int *array_ptr, int l, int h)
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
            return get_solo_sorted(array_ptr, mid + 1, h);
        }
        else
        {
            return get_solo_sorted(array_ptr, l, mid - 1);
        }
    }
    else
    {
        if (array_ptr[mid] == array_ptr[mid - 1])
        {
            return get_solo_sorted(array_ptr, mid + 1, h);
        }
        else
        {
            return get_solo_sorted(array_ptr, l, mid - 1);
        }
    }
}

/******************************************************************************
 * Sheet.05
 *
 * Problem.05:
 *      -->  You have an array of integers contain Mono numbers only
 *           (from 0 to 9)
 *           write c function to find the most repeated number (try in O(n)).
 *
 * @author: Ahmed Harbi
 * @date:   Feb 12th, 2022
 ******************************************************************************/

int get_max_index(const int *array_ptr, const int *size)
{
    /* O(n) */
    int max = array_ptr[0];
    int index = 0;

    for (int i = 1; i < *size; i++)
    {
        if (max < array_ptr[i])
        {
            max = array_ptr[i];
            index = i;
        }
    }

    return index;
}

int get_most_repeated_mono(const int *array_ptr, const int *size)
{
    int hash_table[10] = {0};

    for (int i = 0; i < *size; i++)
    {
        hash_table[array_ptr[i]] += 1;
    }

    int hash_size = 10;

    int max = get_max_index(hash_table, &hash_size);

    return max;
}

/******************************************************************************
 * Sheet.05
 *
 * Problem.06:
 *      --> Write c function to find the first repeated char in string
 *          (try in O(n)).
 *          "ahmed selem" ->e.
 *
 * @author: Ahmed Harbi
 * @date:   Feb 12th, 2022
 ******************************************************************************/

char most_repeated_character(const char *str)
{
    int hash_table[128] = {0};

    for (int i = 0; str[i]; i++)
    {
        hash_table[str[i]] += 1;
    }

    int hash_size = 128;

    char most_repeated = get_max_index(hash_table, &hash_size);

    return most_repeated;
}

/******************************************************************************
 * Sheet.05
 *
 * Problem.07:
 *      --> Write c function to copy string to string without copy repeated
 *          characters try (O(n)).
 *          "ahmed selem kamel"->"ahmed slk".
 *
 * @author: Ahmed Harbi
 * @date:   Feb 12th, 2022
 ******************************************************************************/

void copy_solo(const char *str, char *copy)
{
    int hash_table[128] = {0};
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (hash_table[str[i]] == 0)
        {
            copy[k++] = str[i];
            hash_table[str[i]] = 1;
        }
    }
    copy[k] = '\0';
}

/******************************************************************************
 * Sheet.05
 *
 * Problem.08:
 *      --> Write C function to take an array and if it finds a number "given"
 *          makes the previous elements in a new array and returns it
 *          (try to optimize).
 *
 * @author: Ahmed Harbi
 * @date:   Feb 12th, 2022
 ******************************************************************************/

int *get_pre(int *array_ptr, int size, int *return_size, int key)
{
    *return_size = size;
    int *ans = (int *)malloc(*return_size * sizeof(int));
    int k = 0;
    int i = 0;
    int not_found = 1;
    while ((i < size) && (not_found))
    {
        if (array_ptr[i] == key)
        {
            not_found = 0;
        }
        else
        {
            ans[k++] = array_ptr[i++];
        }
    }
    *return_size = k;
    return ans;
}

/******************************************************************************
 * Sheet.05
 *
 * Problem.09:
 *      -->Write a c function to swap the two bytes of a short int
 *         (n=0xFE20 ->0X20FE) use 2 methods.
 *
 * @author: Ahmed Harbi
 * @date:   Feb 12th, 2022
 ******************************************************************************/

void swap_bytes(unsigned short *x)
{
    unsigned char first_part = (0xFF) & (*x);
    unsigned char second_part = ((0xFF << 8) & (*x)) >> 8;

    *(char *)x = second_part;
    *((char *)x + 1) = first_part;
}
