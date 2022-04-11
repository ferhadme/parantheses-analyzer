#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "pstack.h"

#define RED_CLR "\x1B[31m"
#define RESET_CLR "\x1B[0m"


bool is_left_paranthese(char p)
{
    return p == '(' || p == '[' || p == '{';
}

bool is_right_paranthese(char p)
{
    return p == ')' || p == ']' || p == '}';
}

char flip(char p)
{
    assert(is_right_paranthese(p));
    if (p == ')')
	return '(';
    if (p == '}')
	return '{';
    return '[';
}

void unbalanced(char *p_exp, p_stack *ps, int margin)
{
    printf("Unbalanced parantheses\n");
    printf("%s\n", p_exp);
    if (is_right_paranthese(*(p_exp + margin)))
	margin++;
    printf("%s%*s%s\n", RED_CLR, margin, "^", RESET_CLR);
    free_p_stack(ps);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
	printf("Usage: %s [parantheses expression]", *argv);
	return 1;
    }
    char *p_exp = *(argv + 1);

    p_stack *ps = create_p_stack();
    int margin = 0;

    for (char *p = p_exp; *p != '\0'; p++) {
	if (is_left_paranthese(*p)) {
	    push(ps, *p);
	} else if (is_right_paranthese(*p)) {
	    if (pop(ps) != flip(*p))
		unbalanced(p_exp, ps, margin);
	}
	margin++;
    }

    if (!is_empty(ps))
	unbalanced(p_exp, ps, margin);

    printf("Balanced parantheses\n");
    free_p_stack(ps);
    return 0;
}
