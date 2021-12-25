#include <stdio.h>
#include <stdlib.h>

int main() {


    int score;
    printf("Enter your actual score: ");
    scanf("%d", &score);

    int reminder;

    reminder = score % 5;

    if (reminder < 3)
    {
        score -= reminder;
    }
    else 
    {
        score += (5 - reminder);
    }

    printf("Your final score is %d\n", score);
    

    return 0;
}