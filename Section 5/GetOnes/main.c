#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter number: ");
    scanf("%d", &number);

    int sum = 0;
    while (number)
    {
        if(number&1)
        {
            sum += 1;
        }
        number = number >> 1;
    }

    printf("Ones = %d\n", sum);
    
    return 0;
    
}