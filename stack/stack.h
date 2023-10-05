#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
  unsigned capacity;
  int top;
  int *array;
};

struct Stack *create_stack(unsigned capacity);

void push(struct Stack *stack, int value);
int pop(struct Stack *stack);
int peek(struct Stack *stack);

bool is_full(struct Stack *stack);
bool is_empty(struct Stack *stack);