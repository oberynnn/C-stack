#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

#define DEFAULT_CAPACITY 100    
#define MAX_LEN 4096

stack* create_stack(void) {
    stack* new;
    int i;

    new = malloc(sizeof(stack));
    new->values = malloc(sizeof(char*) *DEFAULT_CAPACITY);
    for (i = 0; i < DEFAULT_CAPACITY; i++) {
        new->values[i] = malloc(sizeof(char) * MAX_LEN);
    }
    new->count = 0;
    return new;
}

int get_count(stack* my_stack) {
    return my_stack->count;
}

bool is_empty(stack* my_stack) {
    return my_stack->count == 0;
}

bool is_full(stack* my_stack) {
    return my_stack->count == DEFAULT_CAPACITY;
}

void push(stack* my_stack, char* value) {
    int idx;

    if (is_full(my_stack)) {
        fprintf(stderr, "Stack is full.\n");
        exit(1);
    }
    idx = my_stack->count;
    strcpy(my_stack->values[idx], value);
    my_stack->count++;
}

char* top(stack* my_stack) {
    if (is_empty(my_stack)) {
        fprintf(stderr, "Stack is empty.\n");
        exit(1);
    }
    return my_stack->values[my_stack->count - 1];
}

char* pop(stack* my_stack) {
    char* top_value;

    top_value = top(my_stack);
    my_stack->count--;
    return top_value;
}

void display(stack* my_stack) {
    int i;

    for (i = 0; i < my_stack->count; i++) {
        printf("%s\n", my_stack->values[i]);
    }
}