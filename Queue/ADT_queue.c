#include <stdio.h>
#include <stdlib.h>
#include "ADT_queue.h"



QUEUE* create_queue(){//create new queue with dynamic memory allocation
    QUEUE* queue;
    queue = (QUEUE*)malloc(sizeof(QUEUE));
    if(queue == NULL){
        printf("Queue memory allocation Error!\n");
        return ERROR_MALLOC;
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
    return queue;
}

bool enqueue(QUEUE* queue, void* in){//queue node memory allocation and enter in queue
    QUEUE_NODE* new_node;
    new_node = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
    if(new_node == NULL){
        printf("Queue node memory allocation Error!\n");
        return ERROR_MALLOC;
    }

    new_node->data_in = in;
    new_node->next = NULL;

    if(queue->count == 0){//there is no node
        queue->front = new_node;
    }
    else{
        queue->rear->next = new_node;
    }

    (queue->count)++;
    queue->rear = new_node;
    return ENQUEUE_SUCCESS;//true
}

void* dequeue(QUEUE* queue){//deleting front queue node and return its data
    if(queue->count == 0){
        printf("Queue is empty!\n");
        return ERROR_EMPTY;
    }

    QUEUE_NODE* del_node;
    del_node=queue->front; //node backup
    if(del_node == NULL){
        printf("Queue front node Error!(We can not backup delete node)\n");
        return ERROR_MALLOC;
    }
    void* del_data=queue->front->data_in;//node data backup

    if(queue->count ==1){//there is 1 node
        queue->front = NULL;
        queue->rear = NULL;
    }
    else{//there are over 2 nodes
        queue->front=queue->front->next; //update front node
    }

    (queue->count)--;
    free(del_node);
    return del_data;//ok
}

void* queue_hook_front(QUEUE* queue){//queue hook front node and return this address
    if(queue->count == 0){
        printf("Queue is empty\n");
        return ERROR_EMPTY;
    }
    return queue->front;
}

void* queue_hook_rear(QUEUE* queue){//queue hook rear node and return this address
    if(queue->count == 0){
        printf("Queue is empty\n");
        return ERROR_EMPTY;
    }
    return queue->rear;
}

bool destroy_queue(QUEUE* queue){//dequeue all node
    int count_before_destory = queue->count;//count of queue before destory
    if(queue != NULL){
        while(queue->count != 0){
            free(queue->front->data_in);
            printf("%d-th node is deleted\n",count_before_destory-(queue->count));
            if(dequeue(queue)==ERROR_ALL){
                return DESTORY_FAIL;
                }
        }
    }
    return DESTORY_SUCCESS;
}

void* dequeue_at(QUEUE* queue,int idx){//deleting front what you want to using idx (most front node is 1 and most rear node is count)
    int pos=1;
    if(queue->count == 0){
        printf("Queue is empty!\n");
        return ERROR_EMPTY;
    }
    if(idx > (queue->count)){
        printf("your idx is bigger than count\n");
        return ERROR_OVER;
        }

    QUEUE_NODE* del_node;
    QUEUE_NODE* del_before_node;
    del_before_node=queue->front; //node backup
    while(pos != (idx-1)){
        del_before_node = del_before_node->next;
        pos++;
    }
    del_node = del_before_node->next;

    if(del_node == NULL){
        printf("Del Queue node Error!(We can not backup delete node)\n");
        return ERROR_MALLOC;
    }

    void* del_data=del_node->data_in;//node data backup

    if(queue->count ==1){//there is 1 node
        queue->front = NULL;
        queue->rear = NULL;
    }
    else if(idx ==1){
        queue->front=queue->front->next;}
    else if(idx == (queue->count)){
         queue->rear = del_before_node;
    }
    else{
        del_before_node->next = del_node->next;
    }

    (queue->count)--;
    free(del_node);
    return del_data;//ok
}

void print_queue(QUEUE* queue){
    if(queue->count == 0){
        printf("Queue is empty!\n");
        exit(0);
    }
    QUEUE_NODE* pos_node = queue->front;
    while(pos_node != NULL){
        printf("Queue Data : %d\n",*((int*)(pos_node->data_in)));
        pos_node = pos_node->next;
        }
}
