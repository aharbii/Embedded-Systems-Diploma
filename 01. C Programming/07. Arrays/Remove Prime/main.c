#include <stdlib.h>
#include <stdio.h>
#include "ARRAY.h"
#include "MATH.h"

int main()
{
    int array[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    array_print_primes(array, ARRAY_SIZE(array));

    int primes_counter = array_delete_prime(array, ARRAY_SIZE(array));
    array_print(array, ARRAY_SIZE(array));

    printf("%d prime numbers have been deleted\n", primes_counter);
    return 0;
}
