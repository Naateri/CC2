#include <iostream>
#include <vector>
#define multiplicacion 1
#define resta 2
#define suma 3
#define inverso 4
#define salir 5
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

void menu()
{
    cout<<"CALCULADORA"<<endl;
    cout<<"Menu principal:"<<endl;
    cout<<"1. Multiplicacion"<<endl;
    cout<<"2. Resta"<<endl;
    cout<<"3. Suma"<<endl;
    cout<<"4. Inverso"<<endl;
    cout<<"5. Salir"<<endl;
}
int sum()
{
    int a,b,resul,resul1,modul;
    cout<<"ingrese valores:";
    cin>>a;
    cin>>b;
    cout<<"ingrese el modulo:";
    cin>>modul;
    resul=a+b;
    resul1=modulo(resul,modul);
    cout<<resul1;
}
void rest()
{
    int a,b,resul1,resul2,modul;
    cout<<"Ingrese valor 1: ";
    cin>>a;
	cout <<"Ingrese valor 2: ";
    cin>>b;
    cout<<"Ingrese el modulo: ";
    cin>>modul;
    resul1=a-b;
    resul2=modulo(resul1,modul);
    cout<<resul2;

}
void multi()
{
    int a,b,resul,resul2,modul;
    cout<<"Ingrese valor 1: ";
    cin>>a;
	cout <<"Ingrese valor 2: ";
    cin>>b;
    cout<<"Ingrese el modulo: ";
    cin>>modul;
    resul=a*b;
    resul2=modulo(resul,modul);
    cout<<resul2;
}

int inversus(vector<int> &cocientes, int mod){
	int p_0 = 0, p_1 = 1, p, q;
	for(int i = 0; i < cocientes.size()-1; i++){
		q = cocientes.at(i);
		p = p_0 - (p_1*q);
		if (p<0)//p = modulo(p, mod);
			p = p%mod;
		p_0 = p_1;
		p_1 = p;
	}
	return p_1;
}
void inv()
{
    int a, b, resul, modul, modOriginal, prevMod = 1;
    cout<<"Ingrese el valor: ";
    cin>>a;
    cout<<"Ingrese el modulo: ";
    cin>>modul;
	vector<int> results;
	modOriginal = modul;
	while(1){ 
		prevMod = modul % a; //prevmod = r
		b = (modul - prevMod) / a;
		//cout << modul << " = " << b << "(" << a << ") + " << prevMod << endl;
		results.push_back(b);
		if (prevMod == 0)
			break;
		modul = a;	
		a = prevMod; //euclides	
	}
	if (a != 1)
		cout << "No tiene inverso.";
	else {
		resul = inversus(results, modOriginal); //division entre 0?
		cout << "El inverso es: " << resul << endl;
	}	
}
int main()
{
    int operacion;
        menu();
        cout<<"Ingrese operacion: ";
        cin>>operacion;
        switch(operacion){
            case multiplicacion:
                multi();
                break;
            case suma:
                sum();
                break;
            case resta:
                rest();
                break;
            case inverso:
                inv();
                break;
            case salir:
                break;
            default:
                cout<<"opcion no valida";

        }
    return 0;
}
