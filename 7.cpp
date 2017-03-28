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
	string alfabeto;
	int publicKey;
	int privateKey;
	void privSetPrivKey(){ //private key setter, private function
		int a = this->publicKey, b, resul, modul = alfabeto.length(), modOriginal, prevMod = 1;
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
		this -> alfabeto = "abcdefghijklmnopqrstuvwxyz";
		this -> publicKey = pubkey;
		privSetPrivKey();
	}
	//setters and getters
	void setPublicKey(int pubkey) { this -> publicKey = pubkey; }
	void setPrivateKey(int privkey) { this -> privateKey = privkey; }
	int getPrivateKey() { return this->privateKey;}
	int getPubKey() {return this->publicKey;}
	//class functions
	string cifrar(string cadena){
		/*int i = 0, found;
		string cifrado, letra;// = "";
		for (i; i<msj.length(); i++){
			letra = msj[i];
			if (letra == " "){
				cifrado += " ";
				continue;
			}
			found = alfabeto.find(letra);
			found += this->privateKey;
			if (found > alfabeto.length())
				found = found % alfabeto.length();
			cifrado += alfabeto[found];*/
    int i;
    string letra;
    for(i = 0; i <= cadena.size(); i++){
        letra = cadena[i];
        if (letra == " ")
            continue;
        else if (alfabeto.find(cadena[i])+privateKey >= alfabeto.size())
            cadena[i] = alfabeto[modulo(alfabeto.find(cadena[i])+privateKey , alfabeto.size())];
        else
            cadena[i] = alfabeto[alfabeto.find(cadena[i])+privateKey];
    }
    return cadena;
		}
	string descifrar(string cadena){
		/*int i = 0, found;
		string descifrado, letra;
		for (i; i<cifrado.length(); i++){
			letra = cifrado[i];
			if (letra == " "){
				descifrado += " ";
				continue;
			}
			found = alfabeto.find(letra);
			found -= this->privateKey;
			if (found < 0){
				found = found % alfabeto.length();
			}
			descifrado += alfabeto[found];
		}
		return descifrado;
	}*/
	int i;
    string letra;
    for (i = 0; i <= cadena.size(); i++){
        letra = cadena[i];
        if (letra == " ")
            continue;
        if(privateKey - alfabeto.find(cadena[i]) > 0)
            cadena[i] = alfabeto[modulo(alfabeto.find(cadena[i]) - privateKey , alfabeto.size())];
        else
            cadena[i] = alfabeto[alfabeto.find(cadena[i])-privateKey];
    }
    return cadena;
    }
};

/*class Cesar
{
private:
    int clave;
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    int privateKey;
	void privSetPrivKey(){ //private key setter, private function
		int a = this->clave, b, resul, modul = alfabeto.length(), modOriginal, prevMod = 1;
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
    void setPublicKey(int pubkey) { this -> clave = pubkey; }
	void setPrivateKey(int privkey) { this -> privateKey = privkey; }
	int getPrivateKey() { return this->privateKey;}
	int getPubKey() {return this->clave;}
Cesar(int clav)
{
    this->clave = clav;
    privSetPrivKey();
}int i;
    for (i = 0; i <= cadena.size(); i++){
        if(clave - alfabeto.find(cadena[i]) > 0)
            cadena[i] = alfabeto[modulo(alfabeto.find(cadena[i]) - clave , alfabeto.size())];
        else
            cadena[i] = alfabeto[alfabeto.find(cadena[i])-clave];
    }
    return cadena;
    }

string cifrar(string cadena)
{
    int i;
    for(i = 0; i <= cadena.size(); i++){
        if (cadena[i] == " ")
            continue;
        else if (alfabeto.find(cadena[i])+clave >= alfabeto.size())
            cadena[i] = alfabeto[modulo(alfabeto.find(cadena[i])+clave , alfabeto.size())];
        else
            cadena[i] = alfabeto[alfabeto.find(cadena[i])+clave];
    }
    return cadena;
}

string descifrar(string cadena)
{
    int i;
    for (i = 0; i <= cadena.size(); i++){
        if(clave - alfabeto.find(cadena[i]) > 0)
            cadena[i] = alfabeto[modulo(alfabeto.find(cadena[i]) - clave , alfabeto.size())];
        else
            cadena[i] = alfabeto[alfabeto.find(cadena[i])-clave];
    }
    return cadena;
    }
};*/
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
