
#ifndef ADT_QUEUE_2015114834
#define ADT_QUEUE_2015114834

#define ERROR_MALLOC NULL,0
#define ERROR_EMPTY NULL,0
#define ERROR_OVER NULL,0
#define ERROR_ALL ERROR_MALLOC,ERROR_EMPTY
#define ENQUEUE_SUCCESS 1
#define DESTORY_SUCCESS 1

#define DEQUEUE_FAIL -1
#define ENQUEUE_FAIL -1
#define DESTORY_FAIL 0

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

bool enqueue(QUEUE*, void*);

void* dequeue(QUEUE*);

void* queue_hook_front(QUEUE*);
void* queue_hook_rear(QUEUE*);
bool destroy_queue(QUEUE*);
void* dequeue_at(QUEUE*, int);
void print_queue(QUEUE* queue);
#endif // ADT_QUEUE_2015114834
