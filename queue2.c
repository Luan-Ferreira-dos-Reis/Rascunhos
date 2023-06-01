#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define typeof(var) _Generic( (var),\
char: "Char",\
int: "Integer",\
float: "Float",\
double: "double",\
char *: "String",\
void *: "Pointer",\
default: "Undefined")

typedef struct Queue{
    int sizeQueue;       /* size of queue */
    int sizeElements;    /* type of elements */
    int *data;          /* array of element only one type of data */
    float *value;          /* array of element only one type of data */
    char *mensg;          /* array of element only one type of data */
}Queue;

/* create a queue to share date */
Queue createQueue(Queue *q, int sizeQueue, int sizeElements){
	void *data;
	q->sizeQueue = sizeQueue;
	q->sizeElements = sizeElements;	
	/* alloc memory space and set values 0*/
	(q->data) = (int*)calloc(sizeQueue, sizeof(int)); 
	(q->value) = (float*)calloc(sizeQueue, sizeof(float));
	(q->mensg) = (char*)calloc(sizeQueue, sizeof(char));		
	return *q;
}


/* loss the last element of the queue data[sizeQueue-1] and write on the first data[0]. */
/* Obs: begin of queue [last element of array] or the first in  */
void writeQueue(Queue *q, void *value){
	for(int i = q->sizeQueue - 1; i > 0; i--){
		q->data[i] = q->data[i-1];
		q->value[i] = q->value[i-1];
		q->mensg[i] = q->mensg[i-1];
	}
	q->data[0] = *(int*)value; 
	q->value[0] = *(float*)value;
	q->mensg[0] = *(char *)value;
}

/* Add elements to the begin of the queue and increase the queue*/
void sendQueue(Queue *q, void *value){
	q->data = (int*)realloc(q->data, ((q->sizeQueue) + 1)*sizeof(int));
	q->value = (float*)realloc(q->value, ((q->sizeQueue) + 1)*sizeof(float));
	q->mensg = (char*)realloc(q->mensg, ((q->sizeQueue) + 1)*sizeof(char));
	q->sizeQueue++;
	writeQueue(q, value);	
}

/* FIFO first in first out return the last element to in */
int readQueue(Queue *q){
	return q->data[q->sizeQueue-1];	
}
float readQueueFloat(Queue *q){
	return q->value[q->sizeQueue-1];	
}
char readQueueChar(Queue *q){
	return q->mensg[q->sizeQueue-1];	
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
float receiveQueueFloat(Queue *q){
	/* save the first out*/
	float buffer = readQueue(q);
	/* free memory */
	int last = (q->sizeQueue)-1;
		q->value = (float*)realloc(q->value, ((q->sizeQueue) - 1)*sizeof(float));
	q->sizeQueue--;
	return (buffer);
}
char receiveQueueChar(Queue *q){
	/* save the first out*/
	char buffer = readQueue(q);
	/* free memory */
	char last = (q->sizeQueue)-1;
		q->mensg = (char*)realloc(q->mensg, ((q->sizeQueue) - 1)*sizeof(char));
	q->sizeQueue--;
	return (buffer);
}

/* auxiliar function to print date of a queue */
void printfQueue(Queue *q){
	printf("data\n");
	for(int i = 0; i < (q->sizeQueue); i++){
    	printf("%d \n", q->data[i]);
	}
//	printf("\nvalue\n");
//	for(int i = 0; i < (q->sizeQueue); i++){
//    	printf("%f \n", q->value[i]);
//	}
//	printf("\nmensg\n");
//	for(int i = 0; i < (q->sizeQueue); i++){
//    	printf("%c \n", q->mensg[i]);
//	}
}

int main(int argc, char *argv[]){
    Queue q;
    int i;
    float f;
    char c = 'f';
    double d = 23.5675;
    
  int value[10] = {2, 3, 4, 5, 7, 1, 0, 6, 9, 8};
//  float value[10] = {2.8, 3.9, 4.6, 5.0, 7.1, 1.7, 0.5, 6.4, 9.3, 8.2};
//    char value[10] = {'2', '3', '4', '5', '7', '1', '0', '6', '9', '8'};
	
//	printf("Queue Created!\n");
  	q = createQueue(&q , 5, sizeof(int));
//  q = createQueue(&q , 5, sizeof(float));
//  q = createQueue(&q , 5, sizeof(char));
    
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
//	printf("first in first reading: %f\n", readQueueFloat(&q));
//	printf("first in first reading: %c\n", readQueueChar(&q));
	printf("Queue date\n");  
    printfQueue(&q);
      
    for(i = 0; i < 3; i++){
    	printf("receive elements from queue(first in first out)\n");
    	printf("element: %d\n", receiveQueue(&q));
//		printf("element: %f\n", receiveQueueFloat(&q));
//		printf("element: %c\n", receiveQueueChar(&q));
	}
	
	printf("Queue date\n");  
    printfQueue(&q);
    
    printf("%s\n%s\n%s\n%s\n", typeof(i), typeof(f), typeof(c),typeof(d));
    free(&q);
    return 0;
	}