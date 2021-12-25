#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter 0x0 to quit the application.\n");
    unsigned char run = 1;
    while(run)
    {
        printf("Enter Operation: ");
        int first_number;
        scanf("%d", &first_number);

        char operation;
        operation = getchar();
        
        int second_number;
        scanf("%d", &second_number);

        double result = 0;

        switch (operation)
        {
            case '+':
                result = first_number + second_number;
                break;
            case '*':
                result = first_number * second_number;
                break;
            case '-':
                result = first_number - second_number;
                break;
            case '/':
                if (second_number == 0)
                {
                    printf("Unvalid Operation, Division by 0\n");
                }
                else 
                {
                    result = (double) first_number / second_number;
                }
                break;
            case 'x':
                run = 0;
                break;
            default:
                printf("Unvalid Operation\n");
                break;
        }

        printf("%d %c %d = %.2lf\n", first_number, operation, second_number, result);
    }
    return 0;
}