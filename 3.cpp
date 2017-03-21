#include <iostream>
using namespace std;
int regular[]={0,3,3,6,1,4,6,2,5,0,3,5};
int bisiesto[]={0,3,4,0,2,5,0,3,6,1,4,6};
char abvDOF[7] = {'D', 'L', 'M', 'X', 'J', 'V', 'S'};
int monthsLess30[4] = {4, 6, 9, 10}; //meses con menos de 30 dias
	
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

int getDay(int a, int m, int d){
	int result1,result2,result3,result4,result5;
	if(esBisiesto(a))
		m=bisiesto[m-1];
	else
		m=regular[m-1];

	result1=(a-1)%7;
	result2=(a-1)/4;
	result3=(3*(((a-1)/100)+1))/4;
	result4=(result2-result3)%7;
	result5=d%7;
	d=(result1+result4+m+result5)%7;
	return d;
}

char returnDay(int d){
	return abvDOF[d];
}


int askYear(){ //pregunta año
	int year;
	cout << "Ingrese un año: ";
	cin >> year;
	return year;
}

int askMonth(){
	int month;
	cout << "Ingrese un mes (del 1 al 12: 1 siendo Enero, 12 Diciembre): ";
	cin >> month;
	if (month > 12 || month < 0){
		cout << "Ingrese un mes válido\n";
		return askMonth();
	}
	return month;
}

int getDays(int month, int year){
	for (int i = 0; i < 4; i++){
		if (month == monthsLess30[i]){
			return 30;
		}
	}		
	if (month == 2){ //si es febrero
		if (esBisiesto(year)) // si es bisiesto		
			return 29;
		else //si no es bisiesto
			return 28;
	}
	else
		return 31; 
	
}

/*int shiftMonth(int month){ ALGORITMO ANTIGUO
	if (month > 2)
		return month-2;
	else
		return month+10;
	//Marzo = 1, Abril = 2...Febrero = 12
}

int operation(int day, int month, int year){ 
	int res, c;
	c = (year/100); //primeros 2 digitos
	if (month <= 2) //si es ene o feb
		year--;
	year = year % 100; //ultimos 2 digitos
	month = shiftMonth(month);
	res = day + (2.6 * month - 0.2) + year + year/4  + c/4 - (2*c); //formula
	return res % 7;
}*/
//algoritmo de Gauss, sacado de: https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Disparate_variation

char getDay(int num){
	return abvDOF[num];
}

void imprimirCalendario(int month, int days, int year){
	int i = 0, j = 0, op;
	op = getDay(year, month, 1); //dia del primero del mes
	//char firstDay = getDay(op);
	for(i; i<7; i++)
		cout << abvDOF[i] << " ";
	//cout << "resultado operacion " << op;
	cout << endl;
	//while(firstDay != abvDOF[j]){
	while(j < op){
		cout << "  "; //2 espacios
		j++; 
	}
	for(i = 1, op; i<=days; i++, op++){
		if (op > 6){
			op = 0;
			cout << endl;	
		}
		cout << i << " ";
	}
}

int main(){
	int year, month, days;
	year = askYear();
	month = askMonth();	
	days = getDays(month, year);
	imprimirCalendario(month, days, year);
	return 0;
}


