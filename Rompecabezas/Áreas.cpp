#include <iostream>
#define pi 3.1416
using namespace std;

double cuadrado(double *lado){
    return *lado * *lado;
}

double rectangulo(double *lado){
    return *lado * *(lado+1);
}

double triangulo(double *base){
    return (*base * *(base+1))/2;
}

double circulo(double *radio){
	return pi* (*radio * *radio);
}

double area(double *valor, double(*p)(double* lista)){
	return p(valor);
}

int main(){

	double (*p)(double*);
	double arey[2] = {5,8};
	cout << area(arey,cuadrado) << endl;
	cout << area(arey,rectangulo) << endl;
	cout << area(arey,triangulo) << endl;
	cout << area(arey,circulo) << endl;
    return 0;
}
