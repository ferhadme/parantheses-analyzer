#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "pstack.h"

static char *expand(p_stack *ps);
static char *shrink(p_stack *ps);

p_stack *create_p_stack()
{
    p_stack *ps = malloc(sizeof(p_stack));
    if (!ps)
	return NULL;
    ps->parans = malloc(sizeof(char) * INITIAL_CAPACITY);
    if (!ps->parans)
	return NULL;
    *(ps->parans) = '\0';
    ps->top = -1;
    ps->capacity = INITIAL_CAPACITY;
    return ps;
}

void free_p_stack(p_stack *ps)
{
    free(ps->parans);
    free(ps);
}

int size(p_stack *ps)
{
    return ps->top + 1;
}

bool is_empty(p_stack *ps)
{
    return size(ps) == 0;
}

void push(p_stack *ps, char elem)
{
    if (size(ps) == ps->capacity)
	expand(ps);
    *(ps->parans + (++ps->top)) = elem;
}

char pop(p_stack *ps)
{
    if (is_empty(ps))
	return '\0';
    char removed = peek(ps);
    *(ps->parans + (ps->top--)) = '\0';
    if (size(ps) == ps->capacity / 2
	&& ps->capacity > INITIAL_CAPACITY)
	shrink(ps);
    return removed;
}

char peek(p_stack *ps)
{
    return *(ps->parans + ps->top);
}

void clear_p_stack(p_stack *ps)
{
    for (int i = 0; i < size(ps); i++)
	pop(ps);
}

static char *expand(p_stack *ps)
{
    ps->capacity *= 2;
    return realloc(ps->parans, ps->capacity);
}

static char *shrink(p_stack *ps)
{
    ps->capacity /= 2;
    return realloc(ps->parans, ps->capacity);
}

void print_stack_contents(p_stack *ps)
{
    printf("%s\n", ps->parans);
}
