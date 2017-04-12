#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int modulo(int a, int n){
	int q, r;
	q = a/n;
	r = a - (q*n);
	if (r<0){
		r += n;
	}
	return r;
}

int inversus(vector<int> &cocientes, int mod){
	int p_0 = 0, p_1 = 1, p, q;
	for(int i = 0; i < cocientes.size()-1; i++){
		q = cocientes.at(i);
		p = p_0 - (p_1*q);
		if (p<0)//p = modulo(p, mod);
			p = modulo(p,mod);
		p_0 = p_1;
		p_1 = p;
	}
	return p_1;
}

class Cesar{
private:
	int publicKey;
	int privateKey;
	int alfabetoSize;
	void privSetPrivKey(){ //private key setter, private function
		int a = this->publicKey, b, resul, modul = this->alfabetoSize, modOriginal, prevMod = 1;
		vector<int> results;
		modOriginal = modul;
		while(1){
			prevMod = modul % a; //prevmod = r
			b = (modul - prevMod) / a;
			results.push_back(b);
			if (prevMod == 0)
				break;
			modul = a;
			a = prevMod; //euclides
		}
		if (a != 1)
			this->privateKey = 0;
		else {
			resul = inversus(results, modOriginal);
			this->privateKey = resul;
		}
	}
public:
	Cesar(int pubkey){
		this -> publicKey = pubkey;
		this->alfabetoSize = 256;
		privSetPrivKey();
	}
	//setters and getters
	void setPublicKey(int pubkey) { this -> publicKey = pubkey; }
	void setPrivateKey(int privkey) { this -> privateKey = privkey; }
	int getPrivateKey() { return this->privateKey;}
	int getPubKey() {return this->publicKey;}
	//class functions
	string cifrar(string cadena){
    int i, ascii, res, modula;
    char letra;
    for(i = 0; i <= cadena.size(); i++){
        letra = cadena[i];
		//DEBUGGINGcout << "char " << letra << endl;
		ascii = int(letra);
		//DEBUGGINGcout << "ascii: " << ascii << endl;
		res = ascii * this->publicKey;
		//DEBUGGINGcout << "multiplicacion " << res << endl;
		modula = modulo(res, this->alfabetoSize);
		if (res == 10 || modula == 10){
			cadena[i] = 'b';
		}
        else if (res >= this->alfabetoSize){
            cadena[i] = char(modulo(res, this->alfabetoSize));
			//DEBUGGINGcout << "modulo " << modulo(res, this->alfabetoSize) << endl;
        }else
            cadena[i] = char(res);
		//DEBUGGINGcout << "char cifrado: " << cadena[i] << endl;
    }
    return cadena;
}
	string descifrar(string cadena){
		int i, ascii, res, modula;
		char letra;
		for (i = 0; i <= cadena.size(); i++){
			letra = cadena[i];
			if (letra == 'b')
				continue;
			//DEBUGGINGcout << "char " << letra << endl;
			ascii = int(letra);
			//DEBUGGINGcout << "ascii: " << ascii << endl;
			res = ascii * this->privateKey;
			//DEBUGGINGcout << "multiplicacion " << res << endl;
			if(res >= this->alfabetoSize){
				cadena[i] = char(modulo(res, this->alfabetoSize));
				//DEBUGGINGcout << "modulo " << modulo(res, this->alfabetoSize) << endl;
			}else
				cadena[i] = char(res);
			//DEBUGGINGcout << "char descifrado: " << cadena[i] << endl;
		}
		return cadena;
	}
};

void cifrando(){
	ifstream msjOriginal;
	ofstream msjCifrado;
	string msj, cifrado;
	int publicKey;
	msjOriginal.open("cifrar.txt");
	msjCifrado.open("descifrar.txt");
	cout << "Ingrese su clave publica: ";
	cin >> publicKey;
	Cesar Algoritmo(publicKey);
	cout << "Su clave privada: " << Algoritmo.getPrivateKey() << endl;
	while(getline(msjOriginal, msj)){
		cifrado = Algoritmo.cifrar(msj);
		msjCifrado << cifrado << endl;
	}
	cout << "Mensaje cifrado.\n";
	msjOriginal.close();
	msjCifrado.close();
}

void descifrando(){
	ifstream msjCifrado;
	ofstream plainText;
	string cifrado, descifrado;
	int privateKey;
	msjCifrado.open("descifrar.txt");
	plainText.open("plaintext.txt");
	cout << "Ingrese su clave privada: ";
	cin >> privateKey;
	Cesar Algoritmo(15); //solo por crear, igual solo importa la clave privada para descifrar
	Algoritmo.setPrivateKey(privateKey);
	while(getline(msjCifrado, cifrado)){
		descifrado = Algoritmo.descifrar(cifrado);
		plainText << descifrado << endl;
	}
	cout << "Mensaje descifrado.\n";
	msjCifrado.close();
	plainText.close();
}

int main(){
	cifrando();
	descifrando();
	return 0;
}
