#include "./stack.h"

struct Stack *create_stack(unsigned capacity)
{
    struct Stack *s = malloc(sizeof(struct Stack));
    s->capacity = capacity;
    s->top = -1;
    s->array = (int *)malloc(sizeof(int) * capacity);

    return s;
}

void push(struct Stack *stack, int value)
{
    if (is_full(stack))
        return;
    stack->array[++stack->top] = value;
}

int pop(struct Stack *stack)
{
    if (is_empty(stack))
        return INT_MIN;

    return stack->array[stack->top--];
}

int peek(struct Stack *stack)
{
    if (is_empty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

bool is_empty(struct Stack *stack)
{
    if (stack->top == -1)
        return true;

    return false;
}

bool is_full(struct Stack *stack)
{
    if (stack->top == stack->capacity)
        return true;

    return false;
}