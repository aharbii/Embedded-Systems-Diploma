#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

typedef enum QueueStatus
{
    QUEUE_FULL,
    QUEUE_EMPTY,
    DONE
} QueueStatus;

QueueStatus push(int key);
QueueStatus pop(int *data);

#endif /* _QUEUE_H_ */