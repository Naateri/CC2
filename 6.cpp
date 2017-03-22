#include <iostream>
#define multiplicacion 1
#define resta 2
#define suma 3
#define inverso 4
#define salir 5
using namespace std;

void menu()
{
    cout<<"CALCULADORA"<<endl;
    cout<<"Menu principal:"<<endl;
    cout<<"1. Multiplicacion"<<endl;
    cout<<"2. resta"<<endl;
    cout<<"3. suma"<<endl;
    cout<<"4. inverso"<<endl;
    cout<<"5. salir"<<endl;
}
int modulo(int a,int n)
{
    int q=a/n;
    int r=a-q*n;
    if(r<0){
        q=q-1;
        r=r+n;
    }
    return r;
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
    cout<<"ingrese valores:";
    cin>>a;
    cin>>b;
    cout<<"ingrese el modulo:";
    cin>>modul;
    resul1=a-b;
    resul2=modulo(resul1,modul);
    cout<<resul2;

}
void multi()
{
    int a,b,resul,resul2,modul;
    cout<<"ingrese valores:";
    cin>>a;
    cin>>b;
    cout<<"ingrese el modulo:";
    cin>>modul;
    resul=a*b;
    resul2=modulo(resul,modul);
    cout<<resul2;
}
void inv()
{
    int a,r,resul,modul;
    cout<<"ingrese valores:";
    cin>>a;
    cout<<"ingrese el modulo:";
    cin>>modul;
    r=modulo(a,b);
    while(r!=0){
        a=b;
        b=r;
        r=modulo(a,b);
    }
    cout<<b;
}
int main()
{
    int operacion;
        menu();
        cout<<"ingrese operacion:";
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
