#include <stdio.h>
#include <stdlib.h>

int main()
{
    float float_number;
    printf("Enter flout number: ");
    scanf("%f", &float_number);

    int rounded = float_number;
    
    if ((float_number - rounded) >= 0.5)
    {
        rounded++;
    }
    
    printf("rounded of %.2f = %d\n", float_number, rounded);

    return 0;
}