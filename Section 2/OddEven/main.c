#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int number;

    printf("Enter number: ");
    scanf("%d", &number);

    if ((number % 2) == 0) {
        printf("%d is even.\n", number);
    }
    else {
        printf("%d is odd.\n", number);
    }

    return EXIT_SUCCESS;
}
