#include <stdio.h>
#include <stdlib.h>

int main() {

    int score;
    printf("Enter your score: ");
    scanf("%d", &score);

    if (score <= 100) {
        if (score > 90) {
            printf("Your grade is A\n");
        }    
        else if (score > 80) {
            printf("Your grade is B+\n");
        }
        else if (score > 70) {
            printf("Your grade is B\n");
        }
        else if (score > 60) {
            printf("Your grade is C\n");
        }
        else if (score >= 50) {
            printf("Your grade is D\n");
        }
        else {
            printf("Your grade is F\n");
        }
    }
    else {
        printf("Unvalid Input\n");
    }

    return EXIT_SUCCESS;
}