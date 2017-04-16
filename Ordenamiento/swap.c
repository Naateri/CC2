#include <stdio.h>
#include <stdlib.h>
//swap en C
void swap(int *p, int *q){
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

int main(){
	int a = 3, b = 5;
	printf("a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	printf("Este es mi programa!\n");
	return 0;
}

