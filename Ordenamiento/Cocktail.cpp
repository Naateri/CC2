#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void generar(int *a, int tam){
    srand(time(NULL));
    for(int i = 0; i < tam; i++){
        a[i] = rand()%20;
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

void cocktail_1(int *a, int tam){
    int *fin;
    fin  = &a[tam-1];
    int r = tam;
    bool compro = 1;
    int contador = 0;
    while (compro){
        compro = 0;
        for(int i = 0; i < r-1; i++){
            if(*a > *(a+1)){
                swap(*a,*(a+1));
                ++contador;
                compro = 1;
            }

            if(*fin < *(fin-1)){
                swap(*fin,*(fin-1));
                ++contador;
                compro = 1;
            }
            a++;
            fin--;
        }
        r--;
        swap(a,fin);
    }
    cout << contador << endl;
}

void cocktail_2(int *a, int tam){
    int *fin;
    fin  = &a[tam-1];
    int r = tam;
    int contador = 0;
    bool compro = 1;
    while (compro){
        compro = 0;
        for(int i = 0; i < r-1; i++){
            if(*a > *(a+1)){
                swap(*a, *(a+1));
                ++contador;
                compro = 1;
            }
            a++;
        }

        for(int j = 0; j < r-1; j++){
            if(*fin < *(fin-1)){
                swap(*fin, *(fin-1));
                ++contador;
                compro = 1;
            }
            --fin;
        }
        r--;
        swap(a,fin);
    }
    cout << contador << endl;
}

int main()
{
    int a[11];
    int b[11];
    int tam = sizeof(a)/sizeof(a[0]);
    generar(a,tam);
    imprimir(a,tam);
    for(int i = 0; i < 11; i++){
        b[i] = a[i];
    }
    cocktail_1(a,tam);
    imprimir(a,tam);
    cocktail_2(b,tam);
    imprimir(b,tam);

    return 0;
}
