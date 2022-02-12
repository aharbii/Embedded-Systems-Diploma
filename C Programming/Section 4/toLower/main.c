#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter # to quit.\n");
    int run = 1;
    while(run)
    {
        char c;
        printf("Enter charcater: ");
        scanf(" %c", &c);

        if (c == '#')
        {
            run = 0;
            continue;
        }
        
        if ((c >= 'a') && (c <= 'z')) 
        {
            printf("%c is lowercase\n", c);
        }
        else if((c >= 'A') && (c <= 'Z'))
        {
            int diff = 'a' - 'A';
            c += diff;
            printf("%c\n", c);
        }
        else
        {
            printf("%c is not an alphabet\n", c);
        }
    }


    return 0;
}