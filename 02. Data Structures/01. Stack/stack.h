#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef enum StackStatus
{
    STACK_FULL,
    STACK_EMPTY,
    DONE
} StackStatus;

StackStatus push(int key);
StackStatus pop(int *data);

#endif /* _STACK_H_ */