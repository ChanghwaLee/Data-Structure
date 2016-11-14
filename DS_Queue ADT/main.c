#include <stdio.h>
#include <stdlib.h>
#include "ADT_queue.h"

typedef struct student {
	int id;
	int score;
} STD;

#define STD_N 20

int main()
{
    int i;
    STD* std_ptr; //struct point

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

    for(i=0;i<STD_N ; i++){
    	if(enqueue(queue,c[i])){
    		printf("Enqueue: %d\n",c[i]->id);
    	}
    	else {
    		printf("Enqueue failed\n");
    		return -1;
    	}
    }

    while(queue->count != 0){
    	dequeue(queue);
    	printf("Dequeue: %d\n",std_ptr->id);
    }

    for(i=0 ; i<STD_N ; i++){
    	if(enqueue(queue,c[i])){
    		printf("Enqueue : %d\n",c[i]->id);
    	}
    	else{
    		printf("Enqueue failed\n");
    		return -1;
    	}
    }

    destroy_queue(queue);
    
    return 0;
}
