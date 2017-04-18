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

int sizeOfArray(int *a, int *b){ 
	return (b-a) + 1;
}

void printArray(int *a, int n){
	for (int i = 0; i < n; i++){
		cout << *a << ", ";
		a++;
	}
	cout << '\n';
}

void selectionSort(int *a, int *b){ //hacerlo sin (x + i)
	int *a0, *min; 
	//int n = sizeOfArray(a, b);
	for (a; a < b-1; i++){
		a0 = a+i;
		min = a+i;
		for (a + aDeArriba; a+aDeArriba < b; j++){ //obviamente no compila
			a0++;
			if (*a0 < *min)
				min = a0;
		}
		if (*min != *(a+i))
			swap(a, min);
	}
}

int main(){
	int a[] = {4, 6, 2, 12, 10, 3, 9, 11, 8, 16};
	selectionSort(a, (a+9));
	printArray(a, 10);
}
