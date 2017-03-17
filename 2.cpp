#include <iostream>
#include <string>
using namespace std;

int monthsLess30[4] = {4, 6, 9, 10}; //meses con menos de 30 dias
string daysOfWeek[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"}; //0 es sabado, 1 domingo...

int askYear(){ //pregunta año
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

int askMonth(){
	int month;
	cout << "Ingrese un mes (del 1 al 12: 1 siendo Enero, 12 Diciembre): ";
	cin >> month;
	if (month > 12 || month < 0){
		cout << "Ingrese un mes válido\n";
		askMonth();
	}
	return month;
}
	
int askDay(int month, int year){
	int day, i = 0;
	cout << "Ingrese el día del mes (del 1 al 31): ";
	cin >> day;
	if (day > 28 && month == 2 && !esBisiesto(year)){ //si es febrero, no es bisiesto,
		cout << "Ingrese un numero válido, el año no es bisiesto.\n"; // y se ingresa un numero
		askDay(month, year); //mayor a 28
	} else if (day > 30) { //si el dia es mayor a 30
		int mnth;
		for(i; i<4; i++){
			mnth = monthsLess30[i]; //y es parte de un mes 
			if (mnth == month){ //con 30 dias
				cout << "Ingrese un número válido.\n";
				askDay(month, year);
			}
		}
	} else if (day > 31 || day < 0){
		cout << "Ingrese un numero menor a 31 y mayor a 0\n";
		askDay(month, year);
	}
	return day;
}

int shiftMonth(int month){
	if (month > 2)
		return month-2;
	else
		return month+10;
	//Marzo = 1, Abril = 2...Febrero = 12
}

int operation(int day, int month, int year){
	int res, c;
	if (month <= 2) //si es ene o feb
		year--;
	c = (year/100); //primeros 2 digitos, siglo
	year = year % 100; //ultimos 2 digitos
	month = shiftMonth(month);
	res = day + (2.6 * month - 0.2) + year + year/4  + c/4 - (2*c); //formula
	return res % 7;
}
//algoritmo de Gauss, sacado de: https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Disparate_variation

string getDay(int num){
	return daysOfWeek[num];
}

int main() {
	int year, month, day;
	year = askYear();
	month = askMonth();
	day = askDay(month, year);
	cout << "El día ingresado es (DD/MM/YY) " << day << "/" << month << "/" << year%100 << endl;
	cout << "El día de la semana es: " << getDay(operation(day, month, year));
	//cout << operation(day, month, year);
	return 0;
}

