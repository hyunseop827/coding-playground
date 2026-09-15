#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef enum {
    INT_INPUT_OK,
    INT_INPUT_END,
    INT_INPUT_ERROR
} InputResult;

InputResult input_int(int *out_value);

int main() {

    int value, option;
    Stack stack;

    option = 100;

    if(stack_init(&stack) != STACK_OK){
        printf("stack initalise failed\n");
        printf("program shut down\n");
        return EXIT_FAILURE;
    }
   
    // while loop for selection
    while(option != 0) {

        printf("\noption list\n");
        printf("1 - push\n");
        printf("2 - pop\n");
        printf("3 - print stack\n");
        printf("4 - find max\n");
        printf("5 - find min\n");
        printf("6 - find peek\n");
        printf("0 - exit\n----------------\n");

        InputResult menu_result = input_int(&option);
        
        // if EOF, shut down
        if (menu_result == INT_INPUT_END) {
            stack_destroy(&stack);
            return 0;
        }

        // if error occurs, go to while starts.
        if (menu_result == INT_INPUT_ERROR) {
            printf("enter integer only.\n");
            continue;
        }

        switch (option) {

            case 1:
                printf("value? :");
                InputResult int_result = input_int(&value);

                if(int_result == INT_INPUT_END){
                    stack_destroy(&stack);
                    return 0;
                }

                if(int_result == INT_INPUT_ERROR){
                    printf("wrong input type... enter integer please.\n");
                    break;
                }                

                if(stack_push(&stack, value) != STACK_OK) {
                    printf("stack is full\n");
                }

                break;
            case 2:
                if(stack_pop(&stack, &value) != STACK_OK){
                    printf("stack is empty\n");
                    break;
                }

                printf("value poped out: %d\n", value);
                break;

            case 3:
                print_stack(&stack);
                break;

            case 4:
                if(stack_max(&stack, &value) != STACK_OK){
                    printf("stack is empty\n");
                    break;
                }

                printf("max in stack: %d\n", value);
                break;

            case 5:
                if(stack_min(&stack, &value) != STACK_OK){
                    printf("stack is empty\n");
                    break;
                }

                printf("min in stack: %d\n", value);
                break;
                
            case 6:
                if(stack_peek(&stack, &value) != STACK_OK){
                    printf("stack is empty\n");
                    break;
                }
                printf("peek: %d\n", value);
                break;

            case 0:
                stack_destroy(&stack);
                break;
                
                default:
                    printf("wrong option\nplease try again...\n");
                    break;
             }
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
