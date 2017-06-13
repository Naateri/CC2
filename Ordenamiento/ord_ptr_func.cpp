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

void generar(int *a, int tam){
	srand(time(NULL));
	for(int i = 0; i < tam; i++){
		a[i] = rand()%50;
	}
}

void imprimir(int *a, int tam){
	cout << "[";
	for(int i = 0; i < tam; i++){
		if(i != tam-1){
			cout << a[i] << ",";
		}
		else{
			cout << a[i];
		}
	}
	cout << "]" << endl;
}

bool mayor(int a, int b){
	return a > b;
}

bool menor(int a, int b){
	return a < b;
}

bool absolutoMayor(int a, int b){
	if (a < 0){
		a = (a * -1);
	}
	if (b < 0){
		b = (b * -1);
	}
	return a > b;
}
bool absolutoMenor(int a, int b){
	if (a < 0){
		a = (a * -1);
	}
	if (b < 0){
		b = (b * -1);
	}
	return a < b;
}


void cocktail(int *a, int *fin, bool (*p) (int, int)){
	int *aux;
	aux = a;
	bool compro = 1;
	while (compro){
		compro = 0;
		for(; a < fin; a++){
			if(*a > *(a+1)){
				swap(*a, *(a+1));
				compro = 1;
			}
		}
		for(; fin != aux; fin--){
			if(*fin < *(fin-1)){
				swap(*fin, *(fin-1));
				compro = 1;
			}
		}
		swap(a,fin);
		a++;
		fin--;
	}
}

void quicksort(int *izq, int *der, bool (*p) (int, int))
{
	int *x , *a, *b, aux;
	a = izq;
	b = der;
	x = a;
	x += (der - izq) /2;
	do{
		while(( p(*a, *x)) && (b <= der) )
		{
			a++;
		}
		
		while( p(*x, *b) && (b > izq) )
		{
			b--;
		}
		
		if( a <= b )
		{
			swap(a,b);
			a++;  b--;
		}
		
	}while( a <= b );
	
	if( p(*izq,*b) )
		quicksort( izq, b, p );
	if( p(*a, *der) )
		quicksort( a, der, p );
}

void bubbleSort(int *a, int *b, bool (*p) (int, int)){
	int *a0, *a1, *a_b; //a_b = a beginning
	a_b = a;
	bool status = true;
	while (status){
		status = false;
		a0 = a; a1 = (a0 + 1);
		for(a; a < b; a++){
			if (p(*a0, *a1)){
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

void insertionSort(int *a, int *b, bool (*p) (int, int)){
	int *a0, *aux;
	int x;
	b++;
	a0 = a+1;
	for(a0; a0 < b; a0++){
		x = *a0;
		aux = a0;
		while (( (aux) > a) && ( p(*(aux - 1), x))){
			*aux = *(aux - 1);
			aux--;
		}
		*aux = x;
	}
}

void selectionSort(int *a, int *b, bool (*p) (int, int)){
	int *a0, *min;
	//a0 = a; 
	for (a; a < b-1; a++){
		a0 = a;
		min = a;
		for (a0; a0 < b; a0++){
			if (p(*(a0), *min))
				min = a0;
		}
		if (*min != *(a0))
			swap(a, min);
	}
}



int main(int argc, char *argv[]) {
	bool (*p) (int, int);
	p = absolutoMenor;
	int a[20];
	generar(a, 20);
	imprimir(a, 20);
	selectionSort(a, (a+20), p);
	imprimir(a, 20);
	return 0;
}

