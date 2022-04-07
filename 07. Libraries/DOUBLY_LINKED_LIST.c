#include "DOUBLY_LINKED_LIST.h"

void doubly_linked_list_display(DoublyLinkedListNode *head)
{
    /* O(n) */
    DoublyLinkedListNode * p = head;
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

int doubly_linked_list_count_nodes(DoublyLinkedListNode *head)
{
    /* O(n) */
    int count = 0;
    DoublyLinkedListNode *t = head;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}

DoublyLinkedListNode *doubly_linked_list_insert(DoublyLinkedListNode *head, int key, int index)
{
    /* O(n) */
    if (index < 0 || index > doubly_linked_list_count_nodes(head))
    {
        return head;
    }

    DoublyLinkedListNode *t = (DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
    t->data = key;
    t->previous = NULL;
    t->next = NULL;

    if (index == 0)
    {
        if (head == NULL)
        {
            head = t;
        }
        else
        {
            t->next = head;
            head->previous = t;
            head = t;
        }
    }
    else
    {
        DoublyLinkedListNode *p = head;
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        t->previous = p;
        if (p->next != NULL)
        {
            p->next->previous = t;
        }
        p->next = t;
    }
    return head;
}

int doubly_linked_list_delete_node(DoublyLinkedListNode *head, int index)
{
    /* O(n) */
    if (index < 1 || index > doubly_linked_list_count_nodes(head))
    {
        return -1;
    }

    DoublyLinkedListNode *p = head;
    int x = 0;
    if (index == 1)
    {
        head = head->next;
        if (head != NULL)
        {
            head->previous = NULL;
        }
        x = p->data;
        free(p);
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        p->previous->next = p->next;
        if (p->next != NULL)
        {
            p->next->previous = p->previous;
        }
        x = p->data;
        free(p);
    }
    return x;
}

DoublyLinkedListNode *doubly_linked_list_reverse(DoublyLinkedListNode *head)
{
    DoublyLinkedListNode *p = head;
    DoublyLinkedListNode *temp = NULL;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->previous;
        p->previous = temp;
        p = p->previous;
        if ((p != NULL) && (p->next == NULL))
        {
            head = p;
        }
    }
    return head;
}
