#ifndef ADT_LLIST_2015114834
#define ADT_LLIST_2015114834
#include <stdio.h>
#include <stdlib.h>

typedef struct LList_node{
    void* data_in;
    struct LList_node* next;
}L_node;

typedef struct {
    int count;
    L_node* front;
    L_node* rear;
    L_node* cur;
    int (*cmp_func)(void* x, void*y);
    void (*func_print)(void* x);
}LLIST;

LLIST* Llist_create(int (*func)(void* x, void* y),void(*print_func)(void* x));

bool add_node_at(LLIST*, unsigned int, void*);

void* del_node_at(LLIST*,unsigned int);

void print_node(LLIST*,L_node*);

void reverse_node(LLIST* );

void* get_data_out(LLIST*, unsigned int);

int find_data(LLIST* , void* );

LLIST* copy_data(LLIST*);

int compare_int(void*, void* );

void print_int(void* );
#endif
