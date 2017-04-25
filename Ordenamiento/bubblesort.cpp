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

void printArray(int *a, int *b){
	for (a; a < b; a++)
		cout << *a << ", ";
	cout << *a << '\n';
}

void bubbleSort(int *a, int *b){
	int *a0, *a1, *a_b; //a_b = a beginning
	a_b = a;
	bool status = true;
	while (status){
		status = false;
		a0 = a; a1 = (a0 + 1);
		for(a; a < b; a++){
			if (*a0 > *a1){
				swap(a0, a1);
				status = true;
			}
			a0 = a1;
			a1 = (a1+1);
		}
		a = a_b;
		b--;
	}
}

int main(){
	int a[] = {4, 6, 2, 12, 10, 3, 9, 11, 16, 8};
	printArray(a, (a+9));
	bubbleSort(a, (a+9));
	printArray(a, (a+9));
}
