/******************************************************************************
 * FILE: DOUBLY_LINKED_LIST.h
 * DESCRIPTION:  C header file contains declration and documentation
 *               for doubly linked list data structure with its operations.
 *
 *              Queries:
 *                  --> Display
 *                  --> Count Nodes
 *
 *              Manipulations:
 *                  --> Insertion at Position
 *                  --> Deletion
 *                  --> Reverse Nodes
 *
 * AUTHOR: Ahmed Harbi
 * DATE: Jan 2022
 *****************************************************************************/

#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

#include "ARRAY.h"
#include "BIT_MATH.h"
#include "LINEAR_LINKED_LIST.h"
#include "MATH.h"
#include "SORTING.h"
#include "STRINGS.h"

typedef struct DoublyLinkedListNode
{
    struct DoublyLinkedListNode *previous;
    int data;
    struct DoublyLinkedListNode *next;
} DoublyLinkedListNode;

void doubly_linked_list_display(DoublyLinkedListNode *head);
int doubly_linked_list_count_nodes(DoublyLinkedListNode *head);

DoublyLinkedListNode *doubly_linked_list_insert(DoublyLinkedListNode *head, int key, int index);
int doubly_linked_list_delete_node(DoublyLinkedListNode *head, int index);

DoublyLinkedListNode *doubly_linked_list_reverse(DoublyLinkedListNode *head);

#endif /* _DOUBLY_LINKED_LIST_H_ */