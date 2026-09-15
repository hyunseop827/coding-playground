#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

StackResult stack_init(Stack *stack) {

    stack->pos = -1;
    stack->data = (int*)malloc(sizeof(int) * STACK_MAX_SIZE);

    if(stack->data == NULL){
        return STACK_FAIL;
    }
    else{
        return STACK_OK;
    }
}

void print_stack(Stack *stack) {
    
    if(stack->pos <= -1){
        return;
    }

    for(int i = stack->pos; i >= 0; i--){
        printf("%2d\n", stack->data[i]);
        printf("----\n");
    }
    return;
}

StackResult push(Stack *stack, int value){

    if(stack->pos >= STACK_MAX_SIZE - 1) {
        return STACK_FULL;
    }
    else{
        stack->data[++(stack->pos)] = value;
        return STACK_OK;
    }
}

StackResult pop(Stack *stack, int *value){

    if(stack->pos <= -1) {
        return STACK_EMPTY;
    }
    else{

        *value = stack->data[stack->pos];
        stack->pos--;

        return STACK_OK;
    }
}

StackResult max(Stack *stack, int *value) {
    
    if(stack->pos <= -1) {
        return STACK_EMPTY;
    }

    else{
        
        int max = stack->data[stack->pos];
        for(int i = 0; i < stack->pos; i++){
            if(max <= stack->data[i]){
                max = stack->data[i];
            }
        }

        *value = max;

        return STACK_OK;
    }
}

StackResult min(Stack *stack, int *value) {


    if(stack->pos <= -1) return STACK_EMPTY;

    else {

        int min = stack->data[stack->pos];
        for(int i = 0; i < stack->pos; i++) {
            if (min >= stack->data[i]) {
                min = stack->data[i];
            }
        }

        *value = min;

        return STACK_OK;
    }
}

StackResult peek(Stack *stack, int *value) {

    if(stack->pos <= -1) return STACK_EMPTY;

    else {
        *value = stack->data[stack->pos];
        
        return STACK_OK;
    }
}

