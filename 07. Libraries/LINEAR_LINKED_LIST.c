/******************************************************************************
 * FILE: LINEAR_LINKED_LIST.h
 * DESCRIPTION:  C program that performs some operations on linked lists.
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
 *
 *                  --> Deletion
 *                  --> Remove Duplicates
 *
 *                  --> Reverse Elements
 *                  --> Reverse Nodes
 *
 *                  --> Concatenate
 *                  --> Merging
 *
 * AUTHOR: Ahmed Harbi
 * DATE: Jan 2022
 *****************************************************************************/

#include "LINEAR_LINKED_LIST.h"

void linear_linked_list_display(LinearLinkedListNode *head)
{
    /* time --> space */
    /* O(n) --> O(1) */

    LinearLinkedListNode *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
        if (!p)
        {
            printf("\n");
        }
    }
}

int linear_linked_list_count_nodes(LinearLinkedListNode *head)
{
    /* O(n) */
    int count = 0;
    LinearLinkedListNode *p = head;
    while (p != NULL)
    {
        count += 1;
        p = p->next;
    }
    return count;
}

int linear_linked_list_sum_nodes(LinearLinkedListNode *head)
{
    /* O(n) */
    int sum = 0;
    LinearLinkedListNode *p = head;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int linear_linked_list_get_max(LinearLinkedListNode *head)
{
    /* O(n) */
    LinearLinkedListNode *p = head;
    int max = INT32_MIN;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int linear_linked_list_get_min(LinearLinkedListNode *head)
{
    /* O(n) */
    LinearLinkedListNode *p = head;
    int min = INT32_MAX;
    while (p != NULL)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

LinearLinkedListNode *linear_linked_list_linear_search(LinearLinkedListNode *head, int key)
{
    /* O(n) */
    LinearLinkedListNode *p = head;
    while (p != NULL)
    {
        if (p->data == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

LinearLinkedListNode *linear_linked_list_improved_linear_search(LinearLinkedListNode *head, int key)
{
    /* O(n) */
    LinearLinkedListNode *p = head;
    LinearLinkedListNode *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return head;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

LinearLinkedListNode *linear_linked_list_insert_at_position(LinearLinkedListNode *head, int key, int index)
{
    /* O(n) */
    if ((index < 0) || (index > linear_linked_list_count_nodes(head)))
    {
        return head;
    }

    LinearLinkedListNode *t = (LinearLinkedListNode *)malloc(sizeof(LinearLinkedListNode));
    t->data = key;
    t->next = NULL;

    LinearLinkedListNode *p = head;

    if (index == 0)
    {
        t->next = head;
        head = t;
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    return head;
}

LinearLinkedListNode *linear_linked_list_insert_at_head(LinearLinkedListNode *head, int key)
{
    LinearLinkedListNode *t = (LinearLinkedListNode *)malloc(sizeof(LinearLinkedListNode));
    t->data = key;

    t->next = head;
    head = t;
    return head;
}

LinearLinkedListNode *linear_linked_list_insert_at_tail(LinearLinkedListNode *head, int key)
{
    /* O(n) */
    LinearLinkedListNode *t = (LinearLinkedListNode *)malloc(sizeof(LinearLinkedListNode));
    t->data = key;
    t->next = NULL;

    LinearLinkedListNode *p = head;

    if (head == NULL)
    {
        head = t;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }

    return head;
}

LinearLinkedListNode *linear_linked_list_insert_sorted(LinearLinkedListNode *head, int key)
{
    /* O(n) */
    LinearLinkedListNode *t = (LinearLinkedListNode *)malloc(sizeof(LinearLinkedListNode));
    t->data = key;
    t->next = NULL;

    LinearLinkedListNode *p = head;

    if (head == NULL)
    {
        head = t;
    }
    else
    {
        LinearLinkedListNode *q = NULL;
        while ((p != NULL) && (p->data < key))
        {
            q = p;
            p = p->next;
        }
        if (q == NULL)
        {
            t->next = p;
            head = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
    return head;
}

LinearLinkedListNode *linear_linked_list_insertion_sort(LinearLinkedListNode *head)
{
    LinearLinkedListNode *ans = NULL;
    LinearLinkedListNode *p = head;
    while (p)
    {
        ans = linear_linked_list_insert_sorted(ans, p->data);
        p = p->next;
    }
    return ans;
}

int linear_linked_list_delete_node(LinearLinkedListNode *head, int index)
{
    /* O(n) */
    if ((index < 1) || (index > linear_linked_list_count_nodes(head)))
    {
        return -1;
    }

    LinearLinkedListNode *q = NULL;

    LinearLinkedListNode *p = head;

    int x = 0;
    if (index == 1)
    {
        q = head;
        head = head->next;
        x = q->data;
        free(q);
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
    }
    return x;
}

int linear_linked_list_is_sorted(LinearLinkedListNode *head)
{
    /* O(n) */
    int x = INT32_MIN;
    int sorted = 1;

    LinearLinkedListNode *p = head;

    while ((p != NULL) && sorted)
    {
        if (p->data >= x)
        {
            x = p->data;
            p = p->next;
        }
        else
        {
            sorted = 0;
        }
    }
    return sorted;
}


LinearLinkedListNode *linear_linked_list_remove_duplicates(LinearLinkedListNode *head)
{
    LinearLinkedListNode *p = head;

    if (p == NULL)
    {
        return head;
    }

    LinearLinkedListNode *q = p->next;
    while (q != NULL)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    return head;
}

void linear_linked_list_reverse_elements(LinearLinkedListNode *head)
{
    /* O(n) */
    int *A = (int *)calloc(linear_linked_list_count_nodes(head), sizeof(int));
    int i = 0;

    LinearLinkedListNode *p = head;

    while (p != NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    p = head;
    i--;
    while (p != NULL)
    {
        p->data = A[i];
        p = p->next;
        i--;
    }
    free(A);
}

LinearLinkedListNode *linear_linked_list_reverse_nodes(LinearLinkedListNode *head)
{
    /* O(n) */
    /* Sliding Pointers */
    LinearLinkedListNode *p = head;
    LinearLinkedListNode *q = NULL;
    LinearLinkedListNode *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
    return head;
}

LinearLinkedListNode *linear_linked_list_rotate(LinearLinkedListNode *head, int rotations)
{
    int len = linear_linked_list_count_nodes(head);
    for (int i = 0; i < (rotations % len); i++)
    {
        int x = linear_linked_list_delete_node(head, len);
        head = linear_linked_list_insert_at_head(head, x);
    }
    return head;
}

LinearLinkedListNode *linear_linked_list_concatenate(LinearLinkedListNode *p, LinearLinkedListNode *q, LinearLinkedListNode *res)
{
    res = p;
    if (!p)
    {
        res = q;
    }
    
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    return res;
}

LinearLinkedListNode *linear_linked_list_merge(LinearLinkedListNode *p, LinearLinkedListNode *q, LinearLinkedListNode *ans)
{
    if (ans != NULL)
    {
        ans = NULL;
    }

    LinearLinkedListNode *last = NULL;
    if (p->data < q->data)
    {
        ans = p;
        last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        ans = q;
        last = q;
        q = q->next;
        last->next = NULL;
    }

    while ((p != NULL) && (q != NULL))
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p != NULL)
    {
        last->next = p;
    }
    if (q != NULL)
    {
        last->next = q;
    }
    return ans;
}

int linear_linked_list_is_circular(LinearLinkedListNode *head)
{
    LinearLinkedListNode *p = head;
    LinearLinkedListNode *q = head;
    int found_loop = 0;
    while ((p != NULL) && (q != NULL) && !found_loop)
    {
        p = p->next;
        q = q->next;
        (q == NULL) ? (q = q) : (q = q->next);
        if (p == q)
        {
            found_loop = 1;
        }
    }
    if (found_loop)
    {
        return 1;
    }
    return 0;
}
