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

typedef struct eos_queue{
    int size_queue;       /* size of queue */
    int size_elements;    /* type of elements */
    int *data;          /* array of element only one type of data */
    float *value;          /* array of element only one type of data */
    char *mensg;          /* array of element only one type of data */
}eos_queue;

/* create a queue to share date */
eos_queue eos_create_queue(eos_queue *q, int size_queue, int size_elements){
	void *data;
	q->size_queue = size_queue;
	q->size_elements = size_elements;	
	/* alloc memory space and set values 0*/
	(q->data) = (int*)calloc(size_queue, sizeof(int)); 
	(q->value) = (float*)calloc(size_queue, sizeof(float));
	(q->mensg) = (char*)calloc(size_queue, sizeof(char));		
	return *q;
}


/* loss the last element of the queue data[sizeQueue-1] and write on the first data[0]. */
/* Obs: begin of queue [last element of array] or the first in  */
void eos_queue_write(eos_queue *q, void *value){
	for(int i = q->size_queue - 1; i > 0; i--){
		q->data[i] = q->data[i-1];
		q->value[i] = q->value[i-1];
		q->mensg[i] = q->mensg[i-1];
	}
	q->data[0] = *(int*)value; 
	q->value[0] = *(float*)value;
	q->mensg[0] = *(char *)value;
}

/* Add elements to the begin of the queue and increase the queue*/
void eos_queue_send(eos_queue *q, void *value){
	q->data = (int*)realloc(q->data, ((q->size_queue) + 1)*sizeof(int));
	q->value = (float*)realloc(q->value, ((q->size_queue) + 1)*sizeof(float));
	q->mensg = (char*)realloc(q->mensg, ((q->size_queue) + 1)*sizeof(char));
	q->size_queue++;
	eos_queue_write(q, value);	
}

/* FIFO first in first out return the last element to in */
int eos_queue_read(eos_queue *q){
	return q->data[q->size_queue-1];	
}
float eos_queue_read_float(eos_queue *q){
	return q->value[q->size_queue-1];	
}
char eos_queue_read_char(eos_queue *q){
	return q->mensg[q->size_queue-1];	
}

/* receive a element of queue and remove the element */
int eos_queue_receive(eos_queue *q){
	/* save the first out*/
	int buffer = eos_queue_read(q);
	/* free memory */
	int last = (q->size_queue)-1;
		q->data = (int*)realloc(q->data, ((q->size_queue) - 1)*sizeof(int));
	q->size_queue--;
	return (buffer);
}
float eos_queue_receive_float(eos_queue *q){
	/* save the first out*/
	float buffer = eos_queue_read_float(q);
	/* free memory */
	int last = (q->size_queue)-1;
		q->value = (float*)realloc(q->value, ((q->size_queue) - 1)*sizeof(float));
	q->size_queue--;
	return (buffer);
}
char eos_queue_receive_char(eos_queue *q){
	/* save the first out*/
	char buffer = eos_queue_read_char(q);
	/* free memory */
	char last = (q->size_queue)-1;
		q->mensg = (char*)realloc(q->mensg, ((q->size_queue) - 1)*sizeof(char));
	q->size_queue--;
	return (buffer);
}

/* auxiliar function to print date of a queue */
void printfQueue(eos_queue *q){
//	printf("data\n");
//	for(int i = 0; i < (q->size_queue); i++){
//    	printf("%d \n", q->data[i]);
//	}
	printf("\nvalue\n");
	for(int i = 0; i < (q->size_queue); i++){
    	printf("%f \n", q->value[i]);
	}
//	printf("\nmensg\n");
//	for(int i = 0; i < (q->size_queue); i++){
//    	printf("%c \n", q->mensg[i]);
//	}
}

int main(int argc, char *argv[]){
    eos_queue q;
    int i;
    float f;
    char c = 'f';
    double d = 23.5675;
    
//  int value[10] = {2, 3, 4, 5, 7, 1, 0, 6, 9, 8};
  float value[10] = {2.8, 3.9, 4.6, 5.0, 7.1, 1.7, 0.5, 6.4, 9.3, 8.2};
//    char value[10] = {'2', '3', '4', '5', '7', '1', '0', '6', '9', '8'};
	
//	printf("Queue Created!\n");
//  	q = eos_create_queue(&q , 5, sizeof(int));
  q = eos_create_queue(&q , 5, sizeof(float));
//  q = eos_create_queue(&q , 5, sizeof(char));
    
    printf("writing 5 elements\n");
    eos_queue_write(&q, &value[0]);
    eos_queue_write(&q, &value[1]);
    eos_queue_write(&q, &value[2]);
    eos_queue_write(&q, &value[3]);
    eos_queue_write(&q, &value[4]);
    printfQueue(&q);
	
	printf("send 5 new elements\n"); 	
	eos_queue_send(&q, &value[5]);
	eos_queue_send(&q, &value[6]);
    eos_queue_send(&q, &value[7]);
    eos_queue_send(&q, &value[8]);
    eos_queue_send(&q, &value[9]); 
    printf("Queue date\n");  
    printfQueue(&q);
    
	printf("reading from queue\n");
//	printf("first in first reading: %d\n", eos_queue_read(&q));
	printf("first in first reading: %f\n", eos_queue_read_float(&q));
//	printf("first in first reading: %c\n", eos_queue_read_char(&q));
	printf("Queue date\n");  
    printfQueue(&q);
      
    for(i = 0; i < 3; i++){
    	printf("receive elements from queue(first in first out)\n");
//    	printf("element: %d\n", eos_queue_receive(&q));
		printf("element: %f\n", eos_queue_receive_float(&q));
//		printf("element: %c\n", eos_queue_receive_char(&q));
	}
	
	printf("Queue date\n");  
    printfQueue(&q);
    
    printf("%s\n%s\n%s\n%s\n", typeof(i), typeof(f), typeof(c),typeof(d));
    return 0;
	}