#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int sizeQueue;       /* size of queue */
    int syzeElements;    /* size of each element */
    int *data;          /* array of element only one type of data */
}Queue;

Queue createQueue(Queue *q,int sizeQueue, int sizeElements){
	void *data;
	q->sizeQueue = sizeQueue;
	q->syzeElements = sizeElements;
	
	data = (int*)calloc(sizeQueue, sizeof(int)); //sizeElements
	q->data = data;
	
	return *q;
}

void enQueue(Queue *q, void *value){
	for(int i = q->sizeQueue - 1; i > 0; i--){
		q->data[i] = q->data[i-1];
	}
	q->data[0] = *(int*)value; 
}

int deQueue(Queue *q){
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
    int value0 = 4;
    q = createQueue(&q , 5, sizeof(int));
    enQueue(&q, &value[0]);
    enQueue(&q, &value[1]);
    enQueue(&q, &value[2]);
    enQueue(&q, &value[3]);
    enQueue(&q, &value[4]);


   
    printf("Queue date\n");  
    for(int i = 0; i < (q.sizeQueue); i++){
    	printf("%d \n", q.data[i]);
	}

    return 0;
	}