#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void swap(int *p, int *q){
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

int sizeOfArray(int *a, int *b){ //funciona mientras no se repitan elementos
	int i = 1;
	while(*a != *b){
		a = a+1;
		i++;
	}
	return i;
}

void printArray(int *a, int n){
	for (int i = 0; i < n; i++){
		cout << *a << ", ";
		a++;
	}
	cout << '\n';
}

void bubbleSort(int *a, int *b){
	int *a0, *a1, *a_b; //a_b = a beginning
	a_b = a;
	bool status = true;
	while (status){
		status = false;
		a0 = a; a1 = (a0 + 1);
		for(int i = 0; a < b; i++, a++){
			if (*a0 > *a1){
				swap(a0, a1);
				status = true;
			}
			a0 = a1;
			a1 = (a1+1);
		}
		a = a_b - 1;
	}
}

int main(){
	int a[] = {4, 6, 2, 12, 10, 3, 9, 11, 8, 16};
	bubbleSort(a, (a+9));
	printArray(a, 10);
}


