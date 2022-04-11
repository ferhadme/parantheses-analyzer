#include <stdio.h>
#include <stdbool.h>
#include "pstack.h"

bool is_left_paranthese(char p)
{
    return p == '(' || p == '[' || p == '{';
}

bool is_right_paranthese(char p)
{
    return p == ')' || p == ']' || p == '}';
}

/* Assuming arg is only right paranthese */
char flip(char p)
{
    if (p == ')')
	return '(';
    if (p == '}')
	return '{';
    return '[';
}

int main(int argc, char **argv) {
    if (argc != 2) {
	printf("Usage: %s [parantheses expression]", *argv);
	return 1;
    }
    char *p_exp = *(argv + 1);

    p_stack *ps = create_p_stack();

    for (char *p = p_exp; *p != '\0'; p++) {
	if (is_left_paranthese(*p)) {
	    push(ps, *p);
	} else if (is_right_paranthese(*p)) {
	    if (pop(ps) != flip(*p)) {
		printf("Unbalanced parantheses\n");
		free_p_stack(ps);
		return 1;
	    }
	}
    }

    if (!is_empty(ps)) {
	printf("Unbalanced parantheses\n");
	free_p_stack(ps);
	return 2;
    }

    printf("Balanced parantheses\n");
    free_p_stack(ps);
    return 0;
}

/*
TODO: count paranthes pairs
TODO: count paranthes individually
TODO: Show where balance broke
*/
