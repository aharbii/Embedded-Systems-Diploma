#include "stack.h"

static int stack[STACK_SIZE];
static int stack_ptr = 0;

StackStatus push(int key)
{
    if (stack_ptr == STACK_SIZE)
    {
        return STACK_FULL;
    }

    stack[stack_ptr] = key;
    stack_ptr += 1;
    return DONE;
}

StackStatus pop(int *data)
{
    if (stack_ptr == 0)
    {
        return STACK_EMPTY;
    }

    stack_ptr -= 1;
    *data = stack[stack_ptr];
    return DONE;
}
