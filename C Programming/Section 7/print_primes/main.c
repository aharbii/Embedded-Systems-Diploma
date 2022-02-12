#include <stdio.h>
#include <stdlib.h>

int is_prime(int number)
{
    if ((number == 0) || (number == 1))
    {
        return 0;
    }

    for (int i = 2; i < number; i++)
    {
        if ((number % i) == 0)
        {
            return 0;
        }
    }
    
    return 1;
}

int main()
{
    int first_number;
    printf("Enter first number: ");
    scanf("%d", &first_number);

    int second_number;
    printf("Enter second number: ");
    scanf("%d", &second_number);

    if (first_number > second_number)
    {
        int temp = first_number;
        first_number = second_number;
        second_number = temp;
    }
    
    for (int i = (first_number + 1); i < second_number; i++)
    {
        if (is_prime(i))
        {
            printf("%d\n", i);
        }
    }

    return 0;
}