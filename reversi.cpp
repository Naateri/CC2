#include <iostream>
#include <iostream>
#include <conio.h>

using namespace std;

int tablero[8][8];

bool lleno(int (*mat)[8]){
	int *row = *mat;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (*row != 0){
				row++;
			} else {
				return 0;
			}
		}
		mat++;
	}
	cout << "Tablero lleno.\n";
	return 1;
}



int main(int argc, char *argv[]) {
	if (lleno(tablero)){
		cout << "Fill";
	} else cout << "vacio";
	return 0;
}
