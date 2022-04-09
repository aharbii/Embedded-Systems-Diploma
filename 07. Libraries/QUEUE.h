/******************************************************************************
 * FILE: QUEUE.h
 * DESCRIPTION:  C header file contains declration and documentation
 *               for Queue data structure with its operations.
 *
 *              Queries:
 *                  --> Is Empty
 *                  --> Is Full
 *
 *                  --> Display Queue
 * 
 *              Manipulations:
 *                  --> Create Queue
 *
 *                  --> Enqueue
 *                  --> Dequeue
 *
 * AUTHOR: Ahmed Harbi
 * DATE: Jan 2022
 *****************************************************************************/

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#include "ARRAY.h"
#include "BIT_MANIPULATION.h"
#include "CIRCULAR_LINKED_LIST.h"
#include "DOUBLY_LINKED_LIST.h"
#include "LINEAR_LINKED_LIST.h"
#include "MATH.h"
#include "SORTING.h"
#include "STACK.h"
#include "STRINGS.h"

typedef struct Queue
{
    int front;
    int rear;
    int size;
    int *elements;
} Queue;

int queue_is_empty(Queue q);
int queue_is_full(Queue q);

void queue_display(Queue q);

void queue_create(Queue *q, int size);
int enqueue(Queue *q, int key);
int dequeue(Queue *q);

#endif /* _QUEUE_H_ */