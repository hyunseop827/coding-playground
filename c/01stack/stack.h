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
StackResult push(Stack *stack, int value);
StackResult pop(Stack *stack, int *value);
StackResult max(Stack *stack, int *value);
StackResult min(Stack *stack, int *value);
StackResult peek(Stack *stack, int *value);

#endif
