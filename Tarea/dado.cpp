#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int rdtsc(){
	__asm__ __volatile__("rdtsc");
}

vector<int> MakeVector(int n){
	vector<int> v;
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	return v;
}

const int n = 75;

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
    char bingo[5] = {'B','I','N','G','O'};
public:
	pair<int, char> operator()(int n){ ///n = numero de bolas
		srand(rdtsc());
		int num, gap = n/5;
		pair<int, char> bola;
		vector<int>::iterator it;
		do{
			num = 1 + rand()%n;
			if (bolillas.size() == 1){
				break;
			}
			it = find(bolillas.begin(), bolillas.end(), num);
		}while(it == bolillas.end());
		if (bolillas.size() > 1)
			bolillas.erase(it);
        bola.first = num;
        if(num == n) {
            bola.second = *(bingo+4);
        } else if (num % gap == 0){
            bola.second = *(bingo + (num / gap) - 1);
        }
        else bola.second = *(bingo + (num / gap));
		return bola;
	}
};

vector<int> Bolillero::bolillas = MakeVector(n);
int main(int argc, char *argv[]) {
	Dado A;
	Bolillero B;
	pair<int, char> hola;
	for (int i = 0; i < n; i++){
        hola = B(n);
		cout << /*"i: " << i << " - "<<*/ hola.second << "-" << hola.first << endl;
	}
	cout << "Dado: " << A(20) << endl;
	return 0;
}

