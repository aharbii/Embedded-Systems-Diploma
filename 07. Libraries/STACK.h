/******************************************************************************
 * FILE: STACK.h
 * DESCRIPTION:  C header file contains declration and documentation
 *               for stack data structure with its operations.
 *
 *              Queries:
 *                  --> Is Empty
 *                  --> Is Full
 *
 *                  --> Display Stack
 *
 *                  --> Get Stack Top
 *                  --> Get Stack peek
 *
 *              Manipulations:
 *                  --> Create Stack
 *
 *                  --> Push into Stack
 *                  --> Pop out of Stack
 *
 * AUTHOR: Ahmed Harbi
 * DATE: Jan 2022
 *****************************************************************************/

#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>

#include "ARRAY.h"
#include "BIT_MANIPULATION.h"
#include "CIRCULAR_LINKED_LIST.h"
#include "DOUBLY_LINKED_LIST.h"
#include "LINEAR_LINKED_LIST.h"
#include "MATH.h"
#include "SORTING.h"
#include "STRINGS.h"

typedef struct Stack
{
    int size;
    int top;
    int *s;
} Stack;

int stack_is_empty(Stack s);
int stack_is_full(Stack s);

void stack_display(Stack s);

int stack_top(Stack s);
int stack_peek(Stack s, int pos);

void stack_create(Stack *st, int size);

int stack_push(Stack *s, int key);
int stack_pop(Stack *s);

#endif /* _STACK_H_ */