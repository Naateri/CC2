#include <iostream>
using namespace std;

int comparar(char* CadenaA, char* CadenaB){
	while (*CadenaA != '\0' && *CadenaB != '\0'){
		/*if (*CadenaA < *CadenaB)
			return 1;
		else if (*CadenaA > *CadenaB)
			return -1;*/
		if (*CadenaA != *CadenaB)
			return 0;
		CadenaA++;
		CadenaB++;
	}
	if (*CadenaA == '\0' && *CadenaB == '\0')
		return 1;
	/*else if (*CadenaA != '\0')
		return -1;*/
	else
		return 0;
}

void strcpy(char *a, char *b){
	while(*b != '\0'){
		*a = *b;
		a++; b++;
	}
	*a = '\0';
}

void fillAsterisks(char* word, char *a){
	while (*word != '\0'){
		*a = '*';
		a++; word++;
	}
	*a = '\0';
}

void reemplazar(char letter, char *word, char *replaced){
	while (*word != '\0'){
		if (letter == *word){
			*replaced = letter; 
		}
		word++; replaced++;
	}
}

bool findLetter(char l, char *w){
	while (*w != '\0'){
		if (l == *w)
			return 1;
		w++;
	}
	return 0;
}

void printC(char* m, int n, char &letter){
	for (int i = 0; i<n; i++){
		if (*m == '-')
			cout << '\\';
		else cout << *m;
		m++;
	}
	letter = *m;
}

void ahorcado(char *palabra, char *m){
	char asterisks[20];
	fillAsterisks(palabra, asterisks);
	char *usedLetters = new char[27];
	char *used = usedLetters;
	//strcpy(usedLetters, "\0");
	char letter;
	bool check;
	int i = 1;
	cout << comparar(palabra, asterisks) << endl;
	while (true){ //(letter != '\0' || !(comparar(palabra, asterisks))){
		do{
			cout << "Ingrese una letra: ";
			cin >> letter;
			check = findLetter(letter, used);
			if (check) cout << "Letra ya ingresada.\n";
		} while(check);
		*usedLetters = letter;
		usedLetters++;
		*usedLetters = '\0';
		cout << "letras usadas: " << used << endl;
		if (findLetter(letter, palabra)){
			reemplazar(letter, palabra, asterisks);
		} else {
			i++;
		}
		printC(m, i, letter);
		if (letter == ' ' || letter == '\n')++i; //omitiendo los espacios y saltos de linea
		cout << endl;
		cout << "Palabra: " << asterisks << endl;
		if (letter == '\0'){
			cout << "PERDISTE!\n";
			cout << "La palabra era: " << palabra << endl;
			break;
		}
		if ((comparar(palabra, asterisks))){
			cout << "GANASTE AMIGUITO!\n";
			break;
		}
	}
	delete[] usedLetters;
}

int main(int argc, char *argv[]) {
	//char* letras = "\0";
	char munheco[] = {' ', 'o', '\n', '/', '|', '-', '\n', '/', '-', '\0'};
	//char *m = munheco;
	//char* munheco = " o\n/|\\\n/\\";
	char *word = "profesor";
	char lel[] = "****";
	//char letter = 'a';
	//reemplazar('a', word, lel);
	//cout << lel << endl;
	ahorcado(word, munheco);
	//cout << *m << endl;
	return 0;
}
