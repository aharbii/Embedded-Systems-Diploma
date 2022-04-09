#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main()
{
    StackStatus status = push(10);
    if (status == STACK_FULL)
    {
        printf("Stack Overflow!\n");
    }

    int data = 0;
    status = pop(&data);

    if (status == STACK_EMPTY)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("%d has been popped out of the stack\n", data);
    }
    
    return 0;
}