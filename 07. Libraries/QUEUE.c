#include "QUEUE.h"

void queue_create(Queue *q, int size)
{
    q->size = size;
    q->front = 0;
    q->rear = 0;
    q->elements = (int *)calloc(size, sizeof(int));
}

void queue_display(Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.elements[i]);
        i = (i + 1) % q.size;
    } while (i != ((q.rear + 1) % q.size));
    printf("\n");
}

int queue_is_empty(Queue q)
{
    if (q.front == q.rear)
    {
        return 1;
    }
    return 0;
}

int queue_is_full(Queue q)
{
    if (((q.rear + 1) % q.size) == q.front)
    {
        return 1;
    }
    return 0;
}

int enqueue(Queue *q, int key)
{
    if (queue_is_full(*q))
    {
        printf("Queue Overflow.\n");
        return 0;
    }

    q->rear = (q->rear + 1) % q->size;
    q->elements[q->rear] = key;
    return 1;
}

int dequeue(Queue *q)
{
    if (queue_is_empty(*q))
    {
        printf("Queue Underflow.\n");
        return -1;
    }

    q->front = (q->front + 1) % q->size;
    int x = q->elements[q->front];
    q->elements[q->front] = 0;
    return x;
}
