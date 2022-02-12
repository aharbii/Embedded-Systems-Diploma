#include <stdio.h>
#include <stdlib.h>

int main()
{
    int first_number;
    int second_number;

    printf("Enter first number: ");
    scanf("%d", &first_number);
    printf("Enter second number: ");
    scanf("%d", &second_number);

    if ((first_number - second_number) > 1)
    {
        for (int i = (first_number - 1); i > second_number; i--)
        {
            if ((i % 3) == 0)
            {
                printf("%d\n", i);
            }
        }
    }
    else if ((second_number - first_number) > 1)
    {
        for (int i = (second_number - 1); i > first_number; i--)
        {
            if ((i % 3) == 0)
            {
                printf("%d\n", i);
            }
        }
    }
    else
    {
        printf("No numbers in between.\n");
    }
    return 0;
}