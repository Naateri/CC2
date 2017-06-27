#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


void print5x5(int (*mat)[5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if ((*(*mat+i)+j) == 0) cout << "-";
            else cout << (*(*mat+i)+j) << " ";
        }
        cout << endl;
    }
}

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
		int num, gap = n/5; /// gap = cuantos numeros tiene cada letra
		pair<int, char> bola;
		vector<int>::iterator it;
		do{
			num = 1 + rand()%n;
			if (bolillas.size() == 1){
                it = find(bolillas.begin(), bolillas.begin()+1, num);
			}
			else it = find(bolillas.begin(), bolillas.end(), num);
		}while(it == bolillas.end());
		if (bolillas.size() > 1)
			bolillas.erase(it);
        bola.first = num;
        if (num % gap == 0){
            bola.second = *(bingo + (num / gap) - 1);
        }
        else bola.second = *(bingo + (num / gap));
		return bola;
	}
};

class Cartilla{
private:
    int numOfBalls;
public:
    Cartilla(int n){
        this->numOfBalls = n;
    }
    void operator()(int n){ ///n = numero de cartillas
        srand(rdtsc());
        for (int carts = 0; carts < n; carts++){
            int num, gap;
            int (*cart)[5];
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){

                    do{
                        num = rand() % gap;
                    }while(num);
                    //(*(*cart+j)+i) = num;
                    cart[j][i] = num;
                }
            }
            (*(*cart+2)+2) = 0;
            print5x5(cart);
        }
    }
};

vector<int> Bolillero::bolillas = MakeVector(n);
int main(int argc, char *argv[]) {
	Dado A;
	Bolillero B;
//	Cartilla C(n);
	pair<int, char> hola;
	for (int i = 0; i < 30; i++){
        hola = B(n);
		cout << hola.second << "-" << hola.first << endl;
	}
	cout << "Dado: " << A(20) << endl;
	return 0;
}

