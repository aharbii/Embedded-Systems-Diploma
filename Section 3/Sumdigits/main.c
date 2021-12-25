#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    int reminder ;
    int sum = 0;
    for (int i = 0; number > 0; i++)
    {
        reminder = number % 10;
        sum += reminder;
        number /= 10;
    }

    printf("sum = %d\n", sum);

    
    

    return 0;
}