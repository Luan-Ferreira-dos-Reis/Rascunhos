#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int sizeQueue;       /* size of queue */
    int syzeElements;    /* size of each element */
    int *data;          /* array of element only one type of data */
}Queue;

Queue createQueue(Queue *q, int sizeQueue, int sizeElements){
	void *data;
	q->sizeQueue = sizeQueue;
	q->syzeElements = sizeElements;
	
	/* alloc memory space and set values 0*/
	data = (int*)calloc(sizeQueue, sizeof(int)); 
	q->data = data;
		
	return *q;
}

/* loss the last element of the queue data[sizeQueue-1] and write on the first data[0]. */
/* Obs: begin of queue [last element of array] or the first in  */
void overWriteQueue(Queue *q, void *value){
	for(int i = q->sizeQueue - 1; i > 0; i--){
		q->data[i] = q->data[i-1];
	}
	q->data[0] = *(int*)value; 
}

/*FIFO first in first out return the last element to in*/
int readQueue(Queue *q){
	return q->data[q->sizeQueue-1];	
}






void task1(void *p){
    float r = *(float*)p;
    printf("hello task2\n");
    printf(" %.4f\n", r);
}

void task2(void *p){
    char r = *(char*)p;
    printf("hello task3\n");
    printf(" %c\n", r);
}

void* taskVoidVoid(void *p){
    int *argumento = (int*)p;
    int conteudo = *argumento;
   
    int retorno = conteudo * 5;
   
    int *ptrRetorno= NULL;
   
    ptrRetorno = &retorno;
    return ptrRetorno;
}

int main(int argc, char *argv[]){
    Queue q;
    int value[5] = {2, 3, 4, 5, 7};

    q = createQueue(&q , 1, sizeof(int));
    overWriteQueue(&q, &value[0]);
    overWriteQueue(&q, &value[1]);
    overWriteQueue(&q, &value[2]);
    overWriteQueue(&q, &value[3]);
    overWriteQueue(&q, &value[4]);
   
    printf("Queue date\n");  
    for(int i = 0; i < (q.sizeQueue); i++){
    	printf("%d \n", q.data[i]);
	}
	
	overWriteQueue(&q, &value[0]);
	
	printf("Queue date\n");  
    for(int i = 0; i < (q.sizeQueue); i++){
    	printf("%d \n", q.data[i]);
	}

    return 0;
	}