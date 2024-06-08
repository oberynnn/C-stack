#ifndef STACK_H
#define STACK_H

typedef struct {
    char** values;
    int count;
} stack;

stack* create_stack(void);
int get_count(stack* my_stack);
bool is_empty(stack* my_stack);
bool is_full(stack* my_stack);
void push(stack* my_stack, char* value);
char* top(stack* my_stack);
char* pop(stack* my_stack);
void display(stack* my_stack);

#endif