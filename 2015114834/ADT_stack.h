#ifndef ADT_STACK_2015114834
#define ADT_STACK_2015114834

#include <stdio.h>

//Stack Node
typedef struct node{
    void* data_ptr;
    struct node* link;
} STACK_NODE;

//Stack ADT
typedef struct {
    int count;
    STACK_NODE* top;
} STACK;

//Interface
STACK* create_stack();

bool push(STACK* stack, void* in);

void* pop(STACK* stack);

void fill_space(int size);

#endif // ADT_STACK_2015114834
