#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Mayor{
public:
	bool operator()(int a, int b){return a>b;};
};

class Menor{
public:
	bool operator()(int a, int b){return a<b;};
};

class AbsolutoMayor{
public:
	bool operator()(int a, int b){
		if (a < 0){
			a = (a * -1);
		}
		if (b < 0){
			b = (b * -1);
		}
		return a > b;
	}
};

class AbsolutoMenor{
public:
	bool operator()(int a, int b){
		if (a < 0){
			a = (a * -1);
		}
		if (b < 0){
			b = (b * -1);
		}
		return a < b;
	}
};

template <class O>
class Ordenamiento{
public:
	void selectionSort(int *a, int *b);
private:
	O A;
};
template <class O>
void Ordenamiento<O>::selectionSort(int *a, int *b){
	int *a0, *min;
	//a0 = a; 
	for (a; a < b-1; a++){
		a0 = a;
		min = a;
		for (a0; a0 < b; a0++){
			//if (*A(*(a0), *min))
			if ((A)(*a0, *min))
				min = a0;
		}
		if (*min != *(a0))
			swap(a, min);
	}
}

void swap(int *p, int *q){
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void generar(int *a, int tam){
	srand(time(NULL));
	for(int i = 0; i < tam; i++){
		a[i] = rand()%100;
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



int main(int argc, char *argv[]) {
	bool (*p) (int, int);
	p = absolutoMenor;
	Ordenamiento<Mayor> Ord;
	int a[20];
	generar(a, 20);
	imprimir(a, 20);
	Ord.selectionSort(a, (a+20));
	imprimir(a, 20);
	return 0;
}

