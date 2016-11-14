#ifndef ADT_QUEUE_2015114834
#define ADT_QUEUE_2015114834

typedef struct queue {//Queue node struct -> data, link
    void* data_in;
    struct queue* next;
}QUEUE_NODE;

typedef struct {
    int count;
    QUEUE_NODE* front;
    QUEUE_NODE* rear;
}QUEUE;

QUEUE* create_queue();

int enqueue(QUEUE*, void*);

void* dequeue(QUEUE*);

void* queue_hook_front(QUEUE*);
void* queue_hook_rear(QUEUE*);
void destroy_queue(QUEUE*);


#endif // ADT_QUEUE_2015114834
