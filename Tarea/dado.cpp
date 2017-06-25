#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int rdtsc(){
	__asm__ __volatile__("rdtsc");
}

vector<int> MakeVector(){
	vector<int> v;
	for (int i = 1; i <= 75; i++)
		v.push_back(i);
	return v;
}

class BolillasArray{
private:
	int _size;
	int *array;
	void resize(int x){
		int *a;
		int i;
		a = new int[x];
		this->_size = x;
		for(i = 0; i< x; i++){
			*(a+i) = *(array+i);
		}
		delete [] array;
		array = a;
	}
public:
	BolillasArray(){ //FIX
		this->_size = 0;
		int *a;
		a = new int[0];
		this->array = a;
		//this->point = NULL;
	}
	BolillasArray(int bolillas[], int size){
		int i;
		this->_size = size;
		this->array = new int[size];
		for (i = 0; i< size; i++){
			*(array+i) = *(bolillas+i);
		}
	}
};

class Dado{
public:
	int operator()(int n){
		srand(time(NULL));
		return 1 + rand()%n;
	}
};

class Bolillero{
private:
	static vector<int> bolillas;
public:
	int operator()(){ ///n = numero de bolas
		srand(rdtsc());
		int num;
		vector<int>::iterator it;
		do{
			num = 1 + rand()%75;
			if (bolillas.size() == 1){
				break;
			}
			it = find(bolillas.begin(), bolillas.end(), num);
		}while(it == bolillas.end());
		if (bolillas.size() > 1)
			bolillas.erase(it);
		return num;
	}
};

vector<int> Bolillero::bolillas = MakeVector();
int main(int argc, char *argv[]) {
	Dado A;
	Bolillero B;
	for (int i = 0; i < 75; i++){
		cout << "i: " << i << " - "<< B() << endl;
	}
	cout << A(6) << endl;
	return 0;
}

