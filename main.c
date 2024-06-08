#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"


int main(void) {
    stack* my_stack;

    my_stack = create_stack();
    push(my_stack, "Aegon");
    push(my_stack, "Oberyn");
    display(my_stack);

    return 0;
}