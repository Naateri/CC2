#include <iostream>
#include <stdlib.h>
#include <time.h>

//Selection sort

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

void selectionSort(int *a, int *b){
	int *a0, *min;
	b++;
	//a0 = a; 
	for (a; a < b-1; a++){
		a0 = a;
		min = a;
		for (a0; a0 < b; a0++){
			if (*(a0) < *min)
				min = a0;
		}
		if (*min != *(a0))
			swap(a, min);
	}
}

int main(){
	int a[] = {4, 6, 2, 12, 10, 3, 9, 11, 16, 8};
	printArray(a, (a+9));
	selectionSort(a, (a+9));
	printArray(a, (a+9));
}
