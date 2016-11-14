#include "ADT_llist.h"
#include <stdio.h>
#include <stdlib.h>

LLIST* Llist_create(int (*func)(void* x, void* y),void(*print_func)(void* x)){ //Llist create by memory allocation and initialize
    LLIST* list;
    list = (LLIST*)malloc(sizeof(LLIST));
    if(list == NULL){
        printf("LLIST malloc error!\n");
        return NULL;
    }

    list->front = NULL;
    list->rear = NULL;
    list->cur = NULL;
    list->cmp_func = func; //fucntion pointer
    list->func_print = print_func; // function pointer
    list->count = 0;

    return list;
}

bool add_node_at(LLIST* list, unsigned int index, void* data){ //add node what you want to position
    if(index > list->count){
        return 0;
    }
    L_node* new_node;
    new_node = (L_node*)malloc(sizeof(L_node));
    if(new_node == NULL){
        printf("There is memory allocation error\n");
        return 0;
    }

    new_node->data_in = data;
    new_node->next = NULL;

    if(list->count ==0){
        list->front = new_node;
        list->rear = new_node;
        (list->count)++;
        return true;
    }

    int itr_i = 0;
    if(index == 0){
        new_node->next = list->front;
        list->front = new_node;
        (list->count)++;
        return true;
   }
   itr_i++;
   list->cur = list->front;
   while(itr_i != index){
        list->cur = list->cur->next;
        itr_i++;
   }

   if(itr_i == list->count){
        list->cur->next = new_node;
        list->rear = new_node;
        (list->count)++;
        return true;
   }
   else{
        new_node->next = list->cur->next;
        list->cur->next = new_node;
        (list->count)++;
        return true;
    }

    return false;
}

void* del_node_at(LLIST* list, unsigned int index){ //delete node whay you want position
    L_node* del_node = NULL;
    if(list->count ==0){ //There is no node;
        printf("There is no node\n");
        return NULL;
    }
    else if(index > (list->count)){ // More than count
        printf("Your index is more than node\n");
        return NULL;
    }
    else{ // OK
        if(list->count == 1){ //There is only one node
            del_node = list->front;
            del_node->data_in = list->front->data_in;
            free(del_node);
            list->count = 0;
            return del_node->data_in;
        }
        int itr_i = 0;
        list->cur = list->front;//Other cases
        L_node* pre = NULL;
        while(itr_i != index){
            pre = list->cur;
            list->cur = list->cur->next;
            itr_i++;
        }
        
        if(index==0){//Index 0 -> first node
            del_node = list->front;
            list->front = list->front->next;
            free(del_node);
            list->cur = NULL;
            (list->count)--;
            return del_node->data_in;
        }
        else if(index == ((list->count) - 1)){ // Last node
            del_node = list->cur;
            list->rear = pre;
            pre->next = NULL;
            free(del_node);
            list->cur=NULL;
            (list->count)--;
            return del_node->data_in;
        }
        else{ // others
            del_node  = list->cur;
            pre->next = list->cur->next;
            free(del_node);
            list->cur = NULL;
            (list->count)--;
            return del_node->data_in;
       }

    exit(0);
    }    
}

void print_node(LLIST* list,L_node* front){
       L_node* pos = front;
       while(pos != NULL){
        (*(list->func_print))(pos->data_in);
        pos = pos->next;
        }
}

void reverse_node(LLIST* list){ //Reverse all node;
    if(list->count == 0 || list->count ==1){
        printf("Error\n");
        exit(0);
    }
    int itr_i=0;
    list->cur = list->front;
    printf("reverse\n");
    for(int max=((list->count)-2);max>=0;max--){
        while(itr_i != max){
            list->cur = list->cur->next;
            itr_i++;
        }
        list->cur->next->next = list->cur;
        list->cur = list->front;
        itr_i=0;
    }
    list->front->next = NULL; 
    L_node* temp;
    temp = list->front;
    list->front = list->rear;
    list->rear = temp;
}

void* get_data_out(LLIST* list, unsigned int index){//get from llist what you want
    if(index>=list->count){
        printf("There is more than node\n");
        return NULL;
    }

    list->cur = list->front;
    int iter_i = 0;
    while(list->cur != NULL){
        if(iter_i == index){
            return list->cur->data_in;
        }
        list->cur = list->cur->next;
        iter_i++;
    }
    printf("There is error!\n");
    return NULL;
}

int find_data(LLIST* list, void* search_data){//Find data
    list->cur = list->front;
    int cmp_result,left,right;
    int iter_i=0;
    while(list->cur != NULL){
        cmp_result = (*(list->cmp_func))(list->cur->data_in,search_data);
        if(cmp_result == 0){
            return iter_i;
        }

        list->cur=list->cur->next;
        iter_i++;
    }
    return -1;
}

int compare_int(void* x, void* y){
    int *x_p = (int*)x;
    int *y_p = (int*)y;
    return *x_p-*y_p;
}

void print_int(void* x){
    int* p_var = (int*)x;
    printf(" - int data %d\n",*p_var);
}

LLIST* copy_data(LLIST* list){//copy list to copyed list
    LLIST* copyed_list;
    copyed_list = Llist_create(compare_int,print_int);
    
    int iter_i;
    for(iter_i=0;iter_i<list->count;iter_i++){
        add_node_at(copyed_list,iter_i,get_data_out(list,iter_i));
        }
    
    return copyed_list;
}
