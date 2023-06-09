#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int sizeQueue;       /* size of queue */
    int syzeElements;    /* size of each element */
    int *data;          /* array of element only one type of data */
}Queue;

/* create a queue to share date */
Queue createQueue(Queue *q, int sizeQueue, int sizeElements){
	void *data;
	q->sizeQueue = sizeQueue;
	q->syzeElements = sizeElements;	
	/* alloc memory space and set values 0*/
	(q->data) = (int*)calloc(sizeQueue, sizeof(int)); 
		
	return *q;
}

/* loss the last element of the queue data[sizeQueue-1] and write on the first data[0]. */
/* Obs: begin of queue [last element of array] or the first in  */
void writeQueue(Queue *q, void *value){
	for(int i = q->sizeQueue - 1; i > 0; i--){
		q->data[i] = q->data[i-1];
	}
	q->data[0] = *(int*)value; 
}

/* Add elements to the begin of the queue and increase the queue*/
void sendQueue(Queue *q, void *value){
	q->data = (int*)realloc(q->data, ((q->sizeQueue) + 1)*sizeof(int));
	q->sizeQueue++;
	writeQueue(q, value);	
}

/* FIFO first in first out return the last element to in */
int readQueue(Queue *q){
	return q->data[q->sizeQueue-1];	
}

/* receive a element of queue and remove the element */
int receiveQueue(Queue *q){
	/* save the first out*/
	int buffer = readQueue(q);
	/* free memory */
	int last = (q->sizeQueue)-1;
		q->data = (int*)realloc(q->data, ((q->sizeQueue) - 1)*sizeof(int));
	q->sizeQueue--;
	return (buffer);
}

void printfQueue(Queue *q){
	for(int i = 0; i < (q->sizeQueue); i++){
    	printf("%d \n", q->data[i]);
	}
}

int main(int argc, char *argv[]){
    Queue q;
    int x;
    int value[10] = {2, 3, 4, 5, 7, 1, 0, 6, 9, 8};

	printf("Queue Created!\n");
    q = createQueue(&q , 5, sizeof(int));
    
    printf("writing 5 elements\n");
    writeQueue(&q, &value[0]);
    writeQueue(&q, &value[1]);
    writeQueue(&q, &value[2]);
    writeQueue(&q, &value[3]);
    writeQueue(&q, &value[4]);
    printfQueue(&q);
	
	printf("send 5 new elements\n"); 	
	sendQueue(&q, &value[5]);
	sendQueue(&q, &value[6]);
    sendQueue(&q, &value[7]);
    sendQueue(&q, &value[8]);
    sendQueue(&q, &value[9]); 
    printf("Queue date\n");  
    printfQueue(&q);
    
	printf("reading from queue\n");
	printf("first in first reading: %d\n", readQueue(&q));
	printf("Queue date\n");  
    printfQueue(&q);
      
    for(x = 0; x < 3; x++){
    	printf("receive elements from queue(first in first out)\n");
		printf("element: %d\n", receiveQueue(&q));
	}
	
	printf("Queue date\n");  
    printfQueue(&q);
    return 0;
	}