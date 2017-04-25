#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

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

void cocktail(int *a, int *fin){
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

int main()
{
    int tama;
    cout << "Ingrese el largo: ";
    cin >> tama;
    int a[tama];
    generar(a,tama);
    imprimir(a,tama);

    cocktail(a,a+tama);
    imprimir(a,tama);

    return 0;
}
