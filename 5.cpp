#include <iostream>
#include <string>
using namespace std;

//FALTA, SOLO FUNCIONA HASTA EL 9999
string units[] = {"uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez"};
string teens[] = {"once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve"};
string twenties[] = {"veinte", "veinti", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
string cientos[] = {"ciento", "doscientos", "trescientos", "cuatroscientos", "quinientos", "seiscientos", "setecientos",
	"ochocientos", "novecientos"};
string miles[] = {"mil", "millón", "millones"};

int askNumber(){
	int num;
	cout << "Ingrese un numero: ";
	cin >> num;
	if (num > 999999999999){
		cout << "Numero muy grande.";
		return askNumber();
	}
	return num;
}

string menor10(int num){
	string lol;
	lol = units[num-1];
	return lol;
}

string menor100(int num){
	string lol;
	if (num < 20)
		return teens[num-11];
	else if (num < 30){
		if (num == 20)
			return twenties[0];
		else{
			lol = twenties[1];
			num -= 20; //20 para que sea unidad
			lol += menor10(num);
			return lol;
		}
	} else {
		int dec;
		dec = num / 10; //decenas
		lol = twenties[dec-1];
		num %= 10;
		lol = lol + " y " + menor10(num);
		return lol;
	}
}

string menor1000(int num){
	string lol, followup;
	if (num == 100)
		return "cien";
	else{
		int cent;
		cent = num/100;
		lol = cientos[cent-1];
		num = num % 100;
		followup = menor100(num);
		lol = lol + " " + menor100(num);
		return lol;
	}
}

string menor10000(int num){
	string lol, before;
	if (num == 1000)
		return miles[0];
	else{
		int milesima = num/1000;
		before = menor10(milesima);
		if (milesima == 1){
			lol = miles[0];
		} else {
			lol = before + " " + miles[0];
		}
		num %= 1000;
		lol = lol + " " + menor1000(num);
		return lol;
	}
}

string numALetras(int num){
	if (num < 10)
		return menor10(num);
	else if (num < 100)
		return menor100(num);
	else if (num < 1000)
		return menor1000(num);
	else if (num < 10000)
		return menor10000(num);
}

int main() {
	cout << numALetras(askNumber());
	return 0;
}

