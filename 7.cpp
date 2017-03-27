#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <stdlib.h> //rand

using namespace std;

class Cesar{
private:
	string alfabeto;
	int key;
	int generarClaves(){
		return rand() % 10 + 1;
	}
public:
	Cesar(){
		this -> alfabeto = "abcdefghijklmnopqrstuvwxyz";
		this -> key = generarClaves();
	}
	string cifrar(string msj){
		int i = 0, found;
		string cifrado, letra;// = "";
		for (i; i<msj.length(); i++){
			letra = msj[i];
			if (letra == " "){
				cifrado += " ";
				continue;
			}
			found = alfabeto.find(letra);
			found = (found+key) % alfabeto.length();
			cifrado += alfabeto[found];
			
		}
		return cifrado;
	}
	string descifrar(string cifrado){ 
		int i = 0, found;
		string descifrado, letra;
		for (i; i<cifrado.length(); i++){
			letra = cifrado[i];
			if (letra == " "){
				descifrado += " ";
				continue;
			}
			found = alfabeto.find(letra);
			if (found > alfabeto.length()){
				cout << "Error. Letra no encontrada.\n";
				cifrado = "Error.\n";
				return cifrado;
			} 
			if (found-key < 0){
				found = (found-key) % alfabeto.length();
			}
			descifrado += alfabeto[found];
		}
		return descifrado;
	}
	int getKey() {return this->key;}
};

int main(){
	ifstream msjOriginal;
	ofstream msjCifrado;
	string msj, cifrado, descifrado;
	msjOriginal.open("cifrar.txt");
	msjCifrado.open("descifrar.txt");
	while(getline(msjOriginal, msj)){ //probando
		cout << msj << endl;
	}
	/*
	codigo por agregarse
	*/
	msjOriginal.close();
	msjCifrado.close();
	return 0;
}
