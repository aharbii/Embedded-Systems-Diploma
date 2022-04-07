#include "CIRCULAR_LINKED_LIST.h"

void circular_linked_list_display(CircularLinkedListNode *head)
{
    /* O(n) */

    CircularLinkedListNode *h = head;
    
    do
    {
        printf("%d ", h->data);
        h = h->next;
        if (h == head)
        {
            printf("\n");
        }

    } while (h != head);
}

int circular_linked_list_count_nodes(CircularLinkedListNode *head)
{
    /* O(n) */
    int count = 1;

    CircularLinkedListNode *p = head;
    if (head == NULL)
    {
        return 0;
    }

    while (p->next != head)
    {
        count++;
        p = p->next;
    }
    return count;
}

CircularLinkedListNode *circular_linked_list_insert_node(CircularLinkedListNode *head, int key, int index)
{
    /* O(n) */
    if (index < 0 || index > circular_linked_list_count_nodes(head))
    {
        return head;
    }

    CircularLinkedListNode *t = (CircularLinkedListNode *)malloc(sizeof(CircularLinkedListNode));
    t->data = key;
    t->next = NULL;

    if (index == 0)
    {
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            t->next = head;
            CircularLinkedListNode *p = head;

            while (p->next != head)
            {
                p = p->next;
            }

            p->next = t;
            head = t;
        }
    }
    else
    {
        CircularLinkedListNode *p = head;
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    return head;
}

CircularLinkedListNode *circular_linked_list_delete_node(CircularLinkedListNode *head, int index)
{
    /* O(n) */
    if ((index < 1) || (index > circular_linked_list_count_nodes(head)))
    {
        return head;
    }
    CircularLinkedListNode *p = head;
    CircularLinkedListNode *q = NULL;
    int x = 0;
    if (index == 1)
    {
        q = head;
        while (p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if (p == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = q->next;
            head = head->next;
            free(q);
        }
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
    return head;
}