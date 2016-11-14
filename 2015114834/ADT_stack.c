#include <stdio.h>
#include <stdlib.h>

#include "ADT_stack.h"

STACK* create_stack(){//create stack function with dynamic memory allocation
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    if(stack == NULL){
        printf("Stack Dynamic Allocation Error!\n");
        return NULL;
    }
    stack->count = 0; //stack is empty
    stack->top = NULL; //stack initialize
    return stack;
}

bool push(STACK* stack, void* in){//stack node and parameter data in
    STACK_NODE* new_node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
    if(new_node == NULL){
        printf("Stack's Node Dynamic Allocation Error!\n");
        return false;
    }

    new_node->data_ptr = in;
    new_node->link = stack->top;
    stack->top = new_node;
    (stack->count)++;
    return true;
}

void* pop(STACK* stack){//stack node delete and return node data
    if(stack->count ==0){
        printf("Stack is empty!\n");
        return NULL;
    }
    else{
        STACK_NODE* temp = stack->top;
        void* data_out = stack->top->data_ptr;
        stack->top = stack->top->link;
        free(temp);
        (stack->count)--;
        return data_out;
    }

}

void fill_space(int size){// just fill space visually
    int i;
    for(i=0; i<size ; i++){
        printf(" ");
    }
}
