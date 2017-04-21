#include <iostream>
#include <stdlib.h>
#include <time.h>

//Insertion sort

using namespace std;

void swap(int *p, int *q){
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void printArray(int *a, int *b){
	for (a; a < b; a++)
		cout << *a << ", ";
	cout << *a << '\n';
}

void insertionSort(int *a, int *b){
	int *a0, *aux;
	int x;
	b++;
	a0 = a+1;
	for(a0; a0 < b; a0++){
		x = *a0;
		aux = a0;
		while (( (aux) > a) && ( *(aux - 1) > x)){
			*aux = *(aux - 1);
			aux--;
		}
		*aux = x;
	}
}

int main(){
	int a[] = {4, 6, 2, 12, 10, 3, 9, 11, 16,8};
	printArray(a, (a+9));
	insertionSort(a, (a+9));
	printArray(a, (a+9));
}
