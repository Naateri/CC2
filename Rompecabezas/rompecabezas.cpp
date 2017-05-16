#include <iostream>
using namespace std;

bool ordenado(int (*mat)[4]){
	int *row = *mat;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (*row < *(row+1)){
				cout << *row << " ";
				row++;
			} else {
				cout << "NO " << *row << endl;
				return 0;
			}
		}
		cout << endl;
		mat++;
	}
	return 1;
}
