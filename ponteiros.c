#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int prazoTarefas[6] = {20, -300, 10 , -10, -20, -100};
int  quantTarefas = 6;

int proxima_tarefa(){
  int menor = prazoTarefas[0];
  int i_menor = 0;
  for (int i = 0; i < quantTarefas; i++){
    if(prazoTarefas[i] < menor){
      i_menor = i;
      menor = prazoTarefas[i];
    }
  }
  return i_menor;
}


int main(void){
	int *ptrY = NULL;
	int *ptrX = NULL;
	int *temp;
	int y = 5;
	ptrY = &y;
	int x = 6;
	ptrX = &x;
	printf("antes\n");
	printf("endereco de x %d: valor de x %d\n", ptrX, x);
	printf("endereco de y %d: valor de y %d\n", ptrY, y);

	printf("depois\n");
	printf("endereco de x %d: valor de x %d\n", ptrX, *ptrX);
	printf("endereco de y %d: valor de y %d\n", ptrY, *ptrY);
	
	//printf("y = %d  *ptrY = %d ptrY = %x &y = %d\n", y, *ptrY, ptrY, &y);
	//printf("%d\n", proxima_tarefa());
	
	
	return 0;
}