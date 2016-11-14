#include <stdio.h>
#include <stdlib.h>
#include "ADT_queue.h"


typedef struct student {
	int id;
	int score;
} STD;//students data in queue node data

#define STD_N 20

int main()
{
    int i;
    STD* std_ptr; //struct point dequeue data

	QUEUE* queue;
	queue = create_queue();

	//struct array point memory allocation
    STD* c[STD_N];
    for(i=0 ; i<STD_N ; i++){
    	c[i] = (STD*)malloc(sizeof(STD));
    }

    //data insertion randomly
    for(i=0 ; i<STD_N ; i++){
    	c[i] -> id = i;
    	c[i] -> score = 10*i;
    }

    //enqueue data(id) in queue node
    for(i=0;i<STD_N ; i++){
    	if(enqueue(queue,c[i])){
    		printf("Enqueue: %d\n",c[i]->id);
            }
    	else {
    		printf("Enqueue failed\n");
    		return ENQUEUE_FAIL;
    	}
    }
    //dequeue all queue nodes
    while(queue->count != 0){
    	std_ptr = (STD*)dequeue(queue);//dequeue data point structure
        if(std_ptr==ERROR_EMPTY || std_ptr==ERROR_MALLOC){
            printf("Dequeue failed\n");
            return DEQUEUE_FAIL;
            }
    	printf("Dequeue: %d\n",std_ptr->id);
    }
    //enqeue data in queue node again
    for(i=0 ; i<STD_N ; i++){
    	if(enqueue(queue,c[i])){
    		printf("Enqueue: %d\n",c[i]->id);
    	}
    	else{
    		printf("Enqueue failed\n");
    		return ENQUEUE_FAIL;
    	}
    }
    
   //destory all of queue node and queue
    if(destroy_queue(queue) != DESTORY_SUCCESS){
        printf("Destory Fail\n");
        return DESTORY_FAIL;
}
    free(queue);//queue memory delocation
    
    return 0;
}
