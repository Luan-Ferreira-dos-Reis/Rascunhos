#include<stdio.h>

int main(){
	int a, b, c;
	a = 0;
	b = 12;
	c = 0;
	while(a < b){
		c += a; 
		a++;
	}
	printf("c = %d", c);
	return 0;
}