#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int rompecabezas[4][4];

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

///########################################################################################################


void llenar_romp(){
    int num = 1;
    while (num != 16){
        int i = rand()%4;
        int j = rand()%4;
        if(rompecabezas[i][j] == 0){
            rompecabezas[i][j] = num;
            num++;
        }
    }
}

void imprimir(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << rompecabezas[i][j] << " ";
        }
        cout << endl;
    }
}

void tecla(){
    char cTecla;

    cout << "Presione una tecla ..." << endl;

    while(cTecla != 27)
    {
       cTecla = getch();
       if(cTecla == 0)
           cTecla = getch();
       else
           switch(cTecla)
           {
            case 72:
                 cout << "Presiono Arriba" << endl;
            break;

            case 80:
                 cout << "Presiono Abajo" << endl;
            break;

            case 75:
                 cout << "Presiono izquierda" << endl;
            break;

            case 77:
                 cout << "Presiono derecha" << endl;
            break;
            }
    }
}

int main()
{
    srand(time(NULL));
    llenar_romp();
    imprimir();
    tecla();
}
