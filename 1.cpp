#include <iostream>
using namespace std;

int askYear(){
	int year;
	cout << "Ingrese un año: ";
	cin >> year;
	return year;
}

bool esBisiesto(int year){
	/* 
	p = es divisble entre 4
	¬q = no es divisible entre 100
	r = es divisible entre 400
	*/
	if ((year%4 == 0) && (year%100 != 0 || year%400 == 0))
		return true;
	else
		return false;
}

int main(){
	if (esBisiesto(askYear())){
		cout << "El año ingresado es bisiesto.";
	} else {
		cout << "El año ingresado no es bisiesto.";
	}
	return 0;
}

