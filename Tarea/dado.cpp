#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Carta;

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

bool verificar(vector<int> numeros, int numero){
    for(int i = 0; i < numeros.size(); i++){
        if(numeros[i] == numero){
            return true;
        }
    }
    return false;
}

vector<Carta> unir(vector<Carta> A, vector<Carta> B){
    vector<Carta>C;
    for(int i = 0; i < A.size(); i++){
        C.push_back(A[i]);
    }
    for(int j = 0; j < B.size(); j++){
        C.push_back(B[j]);
    }
    return C;
}

vector<Carta> partir(vector<Carta> numero,int posicion, int numeros){
    vector <Carta> resultado;
    for(int i = 0; i < numeros; i++){
        resultado.push_back(numero[posicion]);
        posicion++;
    }
    return resultado;
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
            (cart[2][2]) = 0;
            print5x5(cart);
        }
    }
};

class Cartillas{
private:
    int bolillas;
public:
    Cartillas(int a){
        this -> bolillas = a;
    }
    operator()(int num){ ///numero de cartillas
        int resultado;
        for(int i = 0; i < num; i++){
            vector<int> comprobacion;
            cout << " B  I  N  G  O" << endl;
            for(int j = 0; j < 5; j++){
                for(int k=0;k<5;k++){
                    resultado = rand()%bolillas+(k*bolillas)+1;
                    while(verificar(comprobacion,resultado)){
                        resultado = rand()%bolillas+(k*bolillas)+1;
                    }
                    if(resultado<10)
                        cout<<" ";
                    comprobacion.push_back(resultado);
                    cout<<resultado<<" ";
                }
                cout<<endl;
            }
            cout<<endl<<endl;
        }
    }
};

class Carta{
public:
    string palo;
    int numero;
    Carta(string letra, int num){
        this -> palo = letra;
        this -> numero = num;
    }
};

class Baraja{
private:
    vector<Carta> picas;
    vector<Carta> corazones;
    vector<Carta> diamantes;
    vector<Carta> treboles;
    vector<Carta> baraja;

public:
    Baraja(){
        for(int j = 1; j <= 13; j++){
            picas.push_back(Carta("P",j));
            corazones.push_back(Carta("C",j));
            diamantes.push_back(Carta("D",j));
            treboles.push_back(Carta("T",j));
        }
        this -> baraja = unir(unir(picas,corazones),unir(diamantes,treboles));
    }
    operator()(int mesclas){
        for(int i = 0; i < mesclas; i++){
            vector<Carta> resultado = baraja;
            vector<Carta> nuevo;
            vector<Carta> izquierda = partir(resultado,0,26);
            vector<Carta> derecha = partir(resultado,26,26);
            for(int j = 0; j < baraja.size()/2; j++){
                nuevo.push_back(derecha[j]);
                nuevo.push_back(izquierda[j]);
            }
            this -> baraja = nuevo;
        }
    }
    void imprimir(){
        for(int i = 0; i < baraja.size(); i++){
            cout << baraja[i].palo << baraja[i].numero << " ";
        }
    }
};


vector<int> Bolillero::bolillas = MakeVector(n);
int main(int argc, char *argv[]) {
	Dado A;
	Bolillero B;
	pair<int, char> hola;
	for (int i = 0; i < 30; i++){
        hola = B(n);
		cout << hola.second << "-" << hola.first << endl;
	}
	cout << "Dado: " << A(20) << endl;
	cout << "########################################################################" << endl;
	Cartillas Bingo(15);
	Bingo(10);
	cout << "########################################################################" << endl;
    Baraja lol;
    lol.imprimir();
    cout << "#########################################################################"<<endl;
    lol(13);
    lol.imprimir();
	return 0;
}
