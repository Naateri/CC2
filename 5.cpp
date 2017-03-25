#include <iostream>
#include <string>
using namespace std;

/*
Completado, solo faltaría ver algunos casos particulares, y probablemente se pueda hacer
un programa más efectivo computacionalmente. kthxbye
*/
string units[] = {"uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez"};
string teens[] = {"once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve"};
string twenties[] = {"veinte", "veinti", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
string cientos[] = {"ciento", "doscientos", "trescientos", "cuatroscientos", "quinientos", "seiscientos", "setecientos",
	"ochocientos", "novecientos"};
string miles[] = {"mil", "millón", "millones"};

unsigned long long int askNumber(){
	unsigned long long int num;
	cout << "Ingrese un numero: ";
	cin >> num;
	if (num > 999999999999ULL){
		cout << "Numero muy grande.\n";
		return askNumber();
	}
	return num;
}

string menor10(int num){ //1 -> 9
	if (num == 0)
		return "";
	string lol;
	lol = units[num-1];
	return lol;
}

string menor100(int num){ //10 -> 99
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
		if (num == 0)
			return lol;
		lol = lol + " y " + menor10(num);
		return lol;
	}
}

string menor1000(int num){ //100 -> 999
	string lol, followup;
	if (num == 100)
		return "cien";
	else if (num % 100 == 0){
		lol = cientos[(num/100)-1];
		return lol;
	}
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

string menor10000(int num){ //1 000 -> 9 999
	string lol, before, after;
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
		if (num < 10)
			after = menor10(num);
		else if (num < 100)
			after = menor100(num);
		else
			after = menor1000(num);
		lol = lol + " " + after;
		return lol;
	}
}

string getAfter(int num){
	string after;
	if (num < 10)
		after = menor10(num);
	else if (num < 100)
		after = menor100(num);
	else
		after = menor1000(num);
	return after;
}

string menor100000(int num){ //10 000 -> 99 999
	int decmil;
	string before, lol, after;
	decmil = num/1000;
	before = menor100(decmil);
	if (decmil%10 == 1){
		for(int i = 0; i<before.length()-1; i++)
			lol += before[i];
		before = lol;
	}
	//lol = before + " mil";
	num %= 1000;
	after = getAfter(num);
	lol = before + " mil " + after;
	return lol;
}

string menor1000000(int num){ //100 000 ->  999 999
	int centmil;
	string before, lol, after;
	centmil = num/1000;
	before = menor1000(centmil);
	if (centmil == 1){
		for(int i = 0; i<before.length()-1; i++)
			lol += before[i];
		before = lol;
	}
	num %= 1000;
	after = getAfter(num);
	lol = before + " mil " + after;
	return lol;
}

string getAfter2(int num){ //up to 999 999
	string after;
	if (num < 1000)
		after = getAfter(num);
	else if (num < 10000)
		after = menor10000(num);
	else if (num < 100000)
		after = menor100000(num);
	else
		after = menor1000000(num);
	return after;
}

string menor10Millon(int num){ //1 000 000 -> 9 999 999
	int unitMil, backupNum;
	//backupNum = num/10000;
	string before1, before2, lol, after;
	unitMil = num/1000000;
	before1 = menor10(unitMil);
	if (unitMil == 1){
		before1 = "un";
		before2 = miles[1];
	} else
		before2 = miles[2];
	num %= 1000000;
	after = getAfter2(num);
	lol = before1 + " " + before2 + " " + after;
	return lol;
}

string menor100Millon(long num){ // 10 000 000 -> 99 999 999
	string before, lol, after;
	int decMill;
	decMill = num/1000000;
	before = menor100(decMill) + " " + miles[2];
	num %= 1000000;
	after = getAfter2(num);
	lol = before + " " + after;
	return lol;
}

string menor1000Millon(long num){ // 100 000 000 -> 999 999 999
	string before, lol, after;
	int centMill;
	centMill = num/1000000;
	before = menor1000(centMill) + " " + miles[2];
	num %= 1000000;
	after = getAfter2(num);
	lol = before + " " + after;
	return lol;
}

string menor10MilMillon(unsigned long long int num){ //1 000 000 000 -> 9 999 999 999
	string before, lol, after;
	/*long long *milMill = NULL;
	milMill = new long long;
	*milMill = num/1000000;*/
	long long milMill;
	milMill = num/1000000;
	before = menor10000(milMill);
	//delete [] milMill;
	num %= 1000000;
	after = getAfter2(num);
	lol = before + " " + miles[2] + " " + after;
	return lol;
}

string menor100MilMillon(unsigned long long int num){
	string before, lol, after;
	long long milMill;
	milMill = num/1000000;
	before = menor100000(milMill) + " " + miles[2];
	num %= 1000000;
	after = getAfter2(num);
	lol = before + " " + after;
	return lol;
}

string menor1Billon(unsigned long long int num){
	string before, lol, after;
	long long milMill;
	milMill = num/1000000;
	before = menor1000000(milMill) + " " + miles[2];
	num %= 1000000;
	after = getAfter2(num);
	lol = before + " " + after;
	return lol;
}

string numALetras(unsigned long long int num){
	if (num <= 10) //1 -> 10
		return menor10(num); 
	else if (num < 100) //11 -> 99
		return menor100(num); 
	else if (num < 1000) //100 -> 999
		return menor1000(num); 
	else if (num < 10000) //1 000 -> 9 999
		return menor10000(num);
	else if (num < 100000) //10 000 -> 99 999
		return menor100000(num);
	else if (num < 1000000) //100 000 -> 999 999
		return menor1000000(num);
	else if (num < 10000000) //1 000 000 -> 9 999 999
		return menor10Millon(num);
	else if (num < 100000000) // 10 000 000 -> 99 999 999
		return menor100Millon(num);
	else if (num < 1000000000) //100 000 000 -> 999 999 999
		return menor1000Millon(num);
	else if (num < 10000000000ULL) //1 000 000 000 -> 9 999 999 999
		return menor10MilMillon(num);
	else if (num < 100000000000ULL) //10 000 000 000 -> 99 999 999 999
		return menor100MilMillon(num);
	else //100 000 000 000 -> 999 999 999 999
		return menor1Billon(num);
}

int main(int argc, char *argv[]) {
	cout << numALetras(askNumber()) << endl;
	return 0;
}
