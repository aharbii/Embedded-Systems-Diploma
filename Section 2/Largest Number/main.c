#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int first_number;
    int second_number;
    int third_number;

    printf("Enter first number: ");
    scanf("%d", &first_number);

    printf("Enter second number: ");
    scanf("%d", &second_number);

    printf("Enter third number: ");
    scanf("%d", &third_number);

    int maximum;

    if(first_number > second_number) {
        if (first_number > third_number) {
            maximum = first_number;
        }
        else {
            maximum = third_number;
        }
    }
    else {
        if (second_number > third_number) {
            maximum = second_number;
        }
        else {
            maximum = third_number;
        }
    }

    // if ((first_number > second_number) && (first_number > second_number))
    //     maximum = first_number;
    // else if ((second_number > first_number) && (second_number > third_number))
    //     maximum = second_number;
    // else
    //     maximum = third_number;

    printf("Largest number is %d\n", maximum);

    return EXIT_SUCCESS;
}