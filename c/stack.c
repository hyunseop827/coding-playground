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

typedef enum {
    INT_INPUT_OK,
    INT_INPUT_END,
    INT_INPUT_ERROR
} InputResult;

// define the stack by using struct
typedef struct int_stack {
    int pos;
    int* data;
} Stack;

// functions
StackResult stack_init(Stack *stack);
void print_stack(Stack *stack);

StackResult push(Stack *stack, int* value);
StackResult pop(Stack *stack, int *value);

// functions for scanf
InputResult input_int(int *out_value);

int main() {

    // integer stack
    Stack stack;
    if(stack_init(&stack) != STACK_OK){
        printf("stack initalise failed\n");
        printf("program shut down\n");
        return 0;
    }

    int value, option, result;
    option = 100;
    
    while(option != 0) {
        printf("\noption list\n");
        printf("1 - push\n");
        printf("2 - pop\n");
        printf("3 - print stack\n");
        printf("0 - exit\n----------------\n");

        switch (option) {

            case 1:
                printf("value? :");
                scanf("%d", &value);
                if(push(&stack, &value) != STACK_OK){
                    printf("stack is full\n");   
                    break;
                }
                break;

            case 2:
                if(pop(&stack, &value) != STACK_OK){
                    printf("stack is empty\n");
                    break;
                }

                printf("value poped out: %d\n", value);
                break;

            case 3:
                print_stack(&stack);
                break;
            case 0:
                free(stack.data);
                break;
                
            default:
                printf("wrong option\nplease try again...\n");
                break;
        }
    }
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
        return STACK_INIT_FAIL;
    }
    else{
        return STACK_OK;
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
        return;
    }

    for(int i = stack->pos; i >= 0; i--){
        printf("%2d\n", stack->data[i]);
        printf("----\n");
    }
    return;
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
        stack->data[++(stack->pos)] = *value;
        return STACK_OK;
    }
}

/**
 * @breif pop
 *
 * @param *stack stack
 * @param *value return pop
 *
 */
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

InputResult input_int(int *value){
    int result = scanf("%d", value);

    if(result == 1){
        return INT_INPUT_OK;
    }

    if (result == EOF){
        return INT_INPUT_END;
    }

    int ch;

    while((ch = getchar()) != '\n' && ch != EOF);
   
    return INT_INPUT_ERROR;
}

