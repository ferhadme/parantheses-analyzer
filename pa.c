#include <stdio.h>
#include "pstack.h"

int main(int argc, char **argv) {
    (void) argc;
    (void) argv;
    p_stack *ps = create_p_stack();

    push(ps, 'a');
    push(ps, 'b');
    push(ps, 'c');
    push(ps, 'd');
    push(ps, 'e');
    print_stack_contents(ps);

    free_p_stack(ps);
    return 0;
}
