#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef enum {
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NO_MEMORY,
    STACK_INIT_FAIL,
    STACK_TYPE_ERR
} StackResult;

// define the stack by using struct
typedef struct int_stack {
    int pos;
    int* data;
} Stack;

// functions
void stack_init(Stack *stack);
void print_stack(Stack *stack);

bool push(Stack *stack);
bool pop(Stack *stack, int *value);

int main() {

    // integer stack
    Stack stack;
    stack_init(&stack);

    print_stack(&stack);

    push(&stack);

    print_stack(&stack);

    int value;

    if(pop(&stack, &value)){

    print_stack(&stack);
    printf("%d\n", value);

} 

/**
 * @brief initailising stack
 *
 * @param stack stack you are going to initialise
 * 
 * @return STACK_OK or STACK_INIT_FAIL
 */
StackResult stack_init(Stack *stack) {

    stack->pos = -1;
    stack->data = (int*)malloc(sizeof(int) * MAX_SIZE);

    if(stack->data == NULL){
        printf("Intialisation failed\n");
        return STACK_OK;
    }
    else{
        printf("Intialisation successed\n");
        return STACK_INIT_FAIL;
    }
}

/**
 * @breif print stack form index 0
 *
 * @param stack you going to print out
 * 
 * @return STACK_OK or STACK_EMPTY
 */
void print_stack(Stack *stack) {
    
    if(stack->pos <= -1){
        return STACK_EMPTY;
    }

    for(int i = stack->pos; i >= 0; i--){
        printf("%2d\n", stack->data[i]);
        printf("----\n");
    }
    return STACK_OK;
}

/** 
 * @breif push
 * 
 * @param stack you want to push
 * @param *value value you want to add
 *
 * @return STACK_OK, STACK_FULL
 */
StackResult push(Stack *stack, int* value){

    if(stack->pos >= MAX_SIZE - 1) {
        return STACK_FULL;
    }
    else{

        stack->pos++;
        stack->data[stack->pos] = value;
        return STACK_OK;
    }
}

bool pop(Stack *stack, int *value){
    if(stack->pos <= -1) {
        return STACK_FULL;
    }
    else{

        *value = stack->data[stack->pos];
        stack->pos--;

        return STACK_OK;
    }
}

