/******************************************************************************
 * FILE: CIRCULAR_LINKED_LIST.h
 * DESCRIPTION:  C header file contains declration and documentation
 *               for circular linked list data structure with its operations.
 *
 *              Queries:
 *                  --> Display
 *                  --> Count Nodes
 * 
 *              Manipulations:
 *                  --> Insertion at Position
 *                  --> Deletion
 *
 * AUTHOR: Ahmed Harbi
 * DATE: Jan 2022
 *****************************************************************************/

#ifndef _CIRCULAR_LINKED_LIST_H_
#define _CIRCULAR_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

#include "ARRAY.h"
#include "BIT_MANIPULATION.h"
#include "DOUBLY_LINKED_LIST.h"
#include "LINEAR_LINKED_LIST.h"
#include "MATH.h"
#include "SORTING.h"
#include "STRINGS.h"

typedef struct CircularLinkedListNode
{
    int data;
    struct CircularLinkedListNode *next;
} CircularLinkedListNode;

void circular_linked_list_display(CircularLinkedListNode *head);
int circular_linked_list_count_nodes(CircularLinkedListNode *head);

CircularLinkedListNode *circular_linked_list_insert_node(CircularLinkedListNode *head, int key, int index);
CircularLinkedListNode *circular_linked_list_delete_node(CircularLinkedListNode *head, int index);

#endif /* _CIRCULAR_LINKED_LIST_H_ */