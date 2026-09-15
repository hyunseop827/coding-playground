#ifndef STACK_H
#define STACK_H

#define STACK_MAX_SIZE 100

typedef enum {
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_FAIL
} StackResult;

typedef struct int_stack {
    int pos;
    int *data;
} Stack;

StackResult stack_init(Stack *stack);
void print_stack(Stack *stack);
StackResult stack_push(Stack *stack, int value);
StackResult stack_pop(Stack *stack, int *value);
StackResult stack_max(Stack *stack, int *value);
StackResult stack_min(Stack *stack, int *value);
StackResult stack_peek(Stack *stack, int *value);
void stack_destroy(Stack *stack);

#endif
