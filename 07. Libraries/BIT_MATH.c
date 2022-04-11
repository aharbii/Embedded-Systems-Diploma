#include "BIT_MATH.h"

void decimal_to_binary(int n)
{
    printf("%d --> 0b", n);
    int start_print = 0;
    for (int i = ((sizeof(n) * 8) - 1); i >= 0; i--)
    {
        if (BIT_GET(n, i) == 1)
        {
            start_print = 1;
        }
        if (start_print == 1)
        {
            printf("%d", BIT_GET(n, i));
        }
    }
    printf("\n");
}
