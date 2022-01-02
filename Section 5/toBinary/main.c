#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short number;
    printf("Enter number: ");
    scanf("%hd", &number);

    printf("%hd in binary is\n0b", number);
    for (int i = ((sizeof(number) * 8) - 1); i >= 0; i--)
    {
        char bit = 1 << i;
        bit = (bit&number) >> i;
        printf("%d", bit);
        
    }
    
    printf("\n");
    
    return 0;
    
}