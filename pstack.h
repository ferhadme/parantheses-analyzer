#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define INITIAL_CAPACITY 50

typedef struct
{
    char *parans;
    int top;
    int capacity;
} p_stack;

p_stack *create_p_stack();

void free_p_stack(p_stack *ps);

int size(p_stack *ps);

bool is_empty(p_stack *ps);

void push(p_stack *ps, char elem);

char pop(p_stack *ps);

char peek(p_stack *ps);

void clear_p_stack(p_stack *ps);

void print_stack_contents(p_stack *ps);

#endif // STACK_H
