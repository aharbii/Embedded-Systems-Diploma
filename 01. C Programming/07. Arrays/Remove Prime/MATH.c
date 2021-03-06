int get_power(int base, int exponent)
{
    int power = 1;
    for (int i = 0; i < exponent; i++)
    {
        power *= base;
    }
    return power;
}

int is_prime(int number)
{
    int is_prime = 1;
    for (int i = 2; (i < number) && (is_prime); i++)
    {
        if ((number % i) == 0)
        {
            is_prime = 0;
        }
    }

    if ((number == 0) || (number == 1))
    {
        is_prime = 0;
    }

    return is_prime;
}

void swap(int *a, int *b)
{
    *b += *a;
    *a = *b - *a;
    *b = *b - *a;
}

