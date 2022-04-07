#include "STACK.h"

void stack_create(Stack *st, int size)
{
    st->size = size;
    st->s = (int *)calloc(st->size, sizeof(int));
    st->top = -1;
}

void stack_display(Stack s)
{
    for (int i = s.top; i >= 0; i--)
    {
        printf("%d ", s.s[i]);
    }
    printf("\n");
}

int stack_is_empty(Stack s)
{
    if (s.top == -1)
    {
        return 1;
    }

    return 0;
}

int stack_is_full(Stack s)
{
    return s.top == (s.size - 1);
}

int stack_push(Stack *s, int key)
{
    if (stack_is_full(*s))
    {
        printf("Warning: Stack Overflow.\n");
        return 0;
    }

    s->top += 1;
    s->s[s->top] = key;

    return 1;
}

int stack_pop(Stack *s)
{
    if (stack_is_empty(*s))
    {
        printf("Warning: Stack Underflow.\n");
        return -1;
    }

    int x = s->s[s->top];

    s->s[s->top] = 0;
    s->top -= 1;

    return x;
}

int stack_peek(Stack s, int pos)
{
    int index = s.top - pos + 1;

    if (index < 0)
    {
        printf("Warning: Invalid Position.\n");
        return -1;
    }

    return s.s[index];
}

int stack_top(Stack s)
{
    if (stack_is_empty(s))
    {
        return -1;
    }

    return s.s[s.top];
}