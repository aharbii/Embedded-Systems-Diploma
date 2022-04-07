/******************************************************************************
 * FILE: LINEAR_LINKED_LIST.h
 * DESCRIPTION:  C header file contains declration and documentation
 *               for linear linked list data structure with its operations.
 *
 *              Queries:
 *                  --> Display
 *                  --> Count Nodes
 *                  --> Sum Nodes
 *                  --> Get Maximum Value
 *                  --> Get Minimum Value
 *
 *                  --> Searching for Element (Linear Search)
 *                  --> Improved Searching for Element (Linear Search)
 *
 *                  --> Checking if it is sorted
 *                  --> Checking if it has a cycle
 *
 *              Manipulations:
 *                  --> Insertion at Position
 *                  --> Insertion at Head
 *                  --> Insertion at Tail
 *                  --> Sorted Insertion
 *                  --> Sort Linked List (Insertion Sort)
 *
 *                  --> Deletion
 *                  --> Remove Duplicates
 *
 *                  --> Reverse Elements
 *                  --> Reverse Nodes
 *                  --> Rotate Nodes
 * 
 *                  --> Concatenate
 *                  --> Merging
 *
 * AUTHOR: Ahmed Harbi
 * DATE: Jan 2022
 *****************************************************************************/

#ifndef _LINEAR_LINKED_LIST_H_
#define _LINEAR_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

#include "ARRAY.h"
#include "BIT_MANIPULATION.h"
#include "MATH.h"
#include "SORTING.h"
#include "STRINGS.h"

typedef struct LinearLinkedListNode
{
    int data;
    struct LinearLinkedListNode *next;
} LinearLinkedListNode;

void linear_linked_list_display(LinearLinkedListNode *head);
int linear_linked_list_count_nodes(LinearLinkedListNode *head);
int linear_linked_list_sum_nodes(LinearLinkedListNode *head);
int linear_linked_list_get_max(LinearLinkedListNode *head);
int linear_linked_list_get_min(LinearLinkedListNode *head);

LinearLinkedListNode *linear_linked_list_linear_search(LinearLinkedListNode *head, int key);
LinearLinkedListNode *linear_linked_list_improved_linear_search(LinearLinkedListNode *head, int key);

int linear_linked_list_is_sorted(LinearLinkedListNode *head);
int linear_linked_list_is_circular(LinearLinkedListNode *head);

LinearLinkedListNode *linear_linked_list_insert_at_position(LinearLinkedListNode *head, int key, int index);
LinearLinkedListNode *linear_linked_list_insert_at_head(LinearLinkedListNode *head, int key);
LinearLinkedListNode *linear_linked_list_insert_at_tail(LinearLinkedListNode *head, int key);
LinearLinkedListNode *linear_linked_list_insert_sorted(LinearLinkedListNode *head, int key);
LinearLinkedListNode *linear_linked_list_insertion_sort(LinearLinkedListNode *head);

int linear_linked_list_delete_node(LinearLinkedListNode *head, int index);
LinearLinkedListNode *linear_linked_list_remove_duplicates(LinearLinkedListNode *head);

void linear_linked_list_reverse_elements(LinearLinkedListNode *head);
LinearLinkedListNode *linear_linked_list_reverse_nodes(LinearLinkedListNode *head);
LinearLinkedListNode *linear_linked_list_rotate(LinearLinkedListNode *head, int rotations);


LinearLinkedListNode *linear_linked_list_concatenate(LinearLinkedListNode *p, LinearLinkedListNode *q, LinearLinkedListNode *res);
LinearLinkedListNode *linear_linked_list_merge(LinearLinkedListNode *p, LinearLinkedListNode *q, LinearLinkedListNode *ans);

#endif /* _LINEAR_LINKED_LIST_H_ */