#include <stdio.h>
#include <stdlib.h>

int main()
{

    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    
    int fact = 1;

    while (number > 1)
    {
        fact *= number--;
    }

    printf("Fact = %d\n", fact);
    

    return 0;
}