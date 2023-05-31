//bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<time.h>
#include<Windows.h>
#include<stdbool.h>
#include<pthread.h>

void *acaoTarefa1(void *arg);
void *acaoTarefa2(void *arg);
void *acaoTarefa3(void *arg);
void *acaoTarefa4(void *arg);

pthread_t threads[4];

int main(void){
	
	pthread_create(&(threads[0]), NULL, acaoTarefa1, NULL);
	pthread_create(&(threads[1]), NULL, acaoTarefa2, NULL);
	pthread_create(&(threads[2]), NULL, acaoTarefa3, NULL);
	pthread_create(&(threads[3]), NULL, acaoTarefa4, NULL);
	
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);
	pthread_join(threads[3], NULL);
	
	return 0;	
}

// código das tarefas
void *acaoTarefa1(void *arg){
	while(1){
		printf("acao 1 \n");	
		Sleep(500);
	}
}

void *acaoTarefa2(void *arg){
	while(1){
		printf("acao 2 \n");
		Sleep(500);
	}
}

void *acaoTarefa3(void *arg){
	while(1){
		printf("acao 3 \n");
		Sleep(500);
	}
}

void *acaoTarefa4(void *arg){
	while(1){
		printf("acao 4 \n");
		Sleep(500);
	}
}








	

