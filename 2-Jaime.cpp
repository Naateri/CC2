#include <iostream>

using namespace std;


int main()
{
    int regular[]={0,3,3,6,1,4,6,2,5,0,3,5};
    int bisiesto[]={0,3,4,0,2,5,0,3,6,1,4,6};
    int d,m,a;

    int result1,result2,result3,result4,result5;

    cout<<"Introduce el dia :";
    cin>>d;
    cout<<"Introduce el mes:";
    cin>>m;
    cout<<"Introduce el ano:";
    cin>>a;

    if((a%4==0) && (a%100!=0 || a%400==0))
    {
        m=bisiesto[m-1];
    }
    else
    {
        m=regular[m-1];
    }

    result1=(a-1)%7;
    result2=(a-1)/4;
    result3=(3*(((a-1)/100)+1))/4;
    result4=(result2-result3)%7;
    result5=d%7;
    d=(result1+result4+m+result5)%7;

    switch(d)
    {
        case 0:
            cout<<"Domingo\n";
            break;
        case 1:
            cout<<"Lunes\n";
            break;
        case 2:
            cout<<"Martes\n";
            break;
        case 3:
            cout<<"Miercoles\n";
            break;
        case 4:
            cout<<"Jueves\n";
            break;
        case 5:
            cout<<"Viernes\n";
            break;
        case 6:
            cout<<"Sabado\n";
            break;
    }
}
