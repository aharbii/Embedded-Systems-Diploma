#include <stdio.h>
#include <stdlib.h>

int power_of_number(int base, int exponent)
{
    int power = 1;
    for (int i = 0; i < exponent; i++)
    {
        power *= base;
    }
    return power;
}

int main()
{
    int base;
    printf("Enter base: ");
    scanf("%d", &base);
    
    int exponent;
    printf("Enter exponent: ");
    scanf("%d", &exponent);

    int power = power_of_number(base, exponent);
    printf("%d ^ %d = %d\n", base, exponent, power);
}