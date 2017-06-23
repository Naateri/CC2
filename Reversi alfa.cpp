#include <iostream>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
using namespace std;

char temp=' ';
char tablero[8][8];
int c,f;
int espacios=60;

#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ESP 32

void generar(char (*mat)[8]){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			*(*(tablero+i)+j) = ' ';
		}
		cout << endl;
	}
}

void winner(char (*mat)[8]){ ///1 si gano P1, 0 si ganó P2
	int uno = 0, dos = 0;
	char *row = *mat;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (*row == 'O'){
				uno++;
			} else if(*row == '*'){
				dos++;
			}
			row++;
		}
		mat++;
	}
	if (uno > dos){
		cout << "Gano el jugador 1! Con un puntaje de " << uno << " contra " << dos << endl;
	}
	else if (uno < dos){
		cout << "Gano el jugador 2! Con un puntaje de " << dos << " contra " << uno << endl;
	} else {
		cout << "Empate! Ambos consiguieron un puntaje de " << uno << endl;
	}
}

void imprimir(char (*mat)[8]){
    system("cls");
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout <<"[" << *(*(mat+i)+j) << "]";
		}
		cout << endl;
	}
}

class jugador{
	bool buscar_up_left(){
		int f_temp=f, c_temp=c;
		bool hay=false;
		if(f>1&&c>1){
			f--;
			c--;
		}
		while(f>0&&c>0&&tablero[f][c]==next->ficha){
			f--;
			c--;
			hay=true;
		}
		if(tablero[f][c]!=ficha)
			hay=false;
		f=f_temp;
		c=c_temp;
		return hay;
	}
	bool buscar_up_right(){
		int f_temp=f, c_temp=c;
		bool hay=false;
		if(f>1&&c<6){
			f--;
			c++;
		}
		while(f>0&&c<7&&tablero[f][c]==next->ficha){
			f--;
			c++;
			hay=true;
		}
		if(tablero[f][c]!=ficha)
			hay=false;
		f=f_temp;
		c=c_temp;
		return hay;
	}
	bool buscar_down_right(){
		int f_temp=f, c_temp=c;
		bool hay=false;
		if(f<6&&c<6){
			f++;
			c++;
		}
		while(f<7&&c<7&&tablero[f][c]==next->ficha){
			f++;
			c++;
			hay=true;
		}
		if(tablero[f][c]!=ficha)
			hay=false;
		f=f_temp;
		c=c_temp;
		return hay;
	}
	bool buscar_down_left(){
		int f_temp=f, c_temp=c;
		bool hay=false;
		if(f<6&&c>1){
			f++;
			c--;
		}
		while(f<7&&c>0&&tablero[f][c]==next->ficha){
			f++;
			c--;
			hay=true;
		}
		if(tablero[f][c]!=ficha)
			hay=false;
		f=f_temp;
		c=c_temp;
		return hay;
	}
	bool buscar_down(){
		int f_temp=f;
		bool hay=false;
		if(f<6){
			f++;
		}
		while(f<7&&tablero[f][c]==next->ficha){
			f++;
			hay=true;
		}
		if(tablero[f][c]!=ficha)
			hay=false;
		f=f_temp;
		return hay;
	}
	bool buscar_up(){
		int f_temp=f;
		bool hay=false;
		if(f>1){
			f--;
		}
		while(f>0&&tablero[f][c]==next->ficha){
			f--;
			hay=true;
		}
		if(tablero[f][c]!=ficha)
			hay=false;
		f=f_temp;
		return hay;
	}
	bool buscar_left(){
		int c_temp=c;
		bool hay=false;
		if(c>1){
			c--;
		}
		while(c>0&&tablero[f][c]==next->ficha){
			c--;
			hay=true;
		}
		if(tablero[f][c]!=ficha)
			hay=false;
		c=c_temp;
		return hay;
	}
	bool buscar_right(){
		int c_temp=c;
		bool hay=false;
		if(c<6){
			c++;
		}
		while(c<7&&tablero[f][c]==next->ficha){
			c++;
			hay=true;
		}
		if(tablero[f][c]!=ficha)
			hay=false;
		c=c_temp;
		return hay;
	}
	bool buscar_pos(){
		return buscar_down()||buscar_down_left()||buscar_down_right()||buscar_left()||buscar_right()||buscar_up()||buscar_up_left()||buscar_up_right();
	}
	void colocar_up(){
		if(buscar_up()==true){
			int f_temp=f;
			f--;
			while(tablero[f][c]==next->ficha){
				tablero[f][c]=ficha;
				f--;
				puntaje++;
				next->puntaje--;
			}
			f=f_temp;
			tablero[f][c]=ficha;
		}
	}
	void colocar_down(){
		if(buscar_down()==true){
			int f_temp=f;
			f++;
			while(tablero[f][c]==next->ficha){
				tablero[f][c]=ficha;
				f++;
				puntaje++;
				next->puntaje--;
			}
			f=f_temp;
			tablero[f][c]=ficha;
		}
	}
	void colocar_right(){
		if(buscar_right()==true){
			int c_temp=c;
			c++;
			while(tablero[f][c]==next->ficha){
				tablero[f][c]=ficha;
				c++;
				puntaje++;
				next->puntaje--;
			}
			c=c_temp;
			tablero[f][c]=ficha;
		}
	}
	void colocar_left(){
		if(buscar_left()==true){
			int c_temp=c;
			c--;
			while(tablero[f][c]==next->ficha){
				tablero[f][c]=ficha;
				c--;
				puntaje++;
				next->puntaje--;
			}
			c=c_temp;
			tablero[f][c]=ficha;
		}
	}
	void colocar_up_left(){
		if(buscar_up_left()==true){
			int f_temp=f,c_temp=c;
			f--;
			c--;
			while(tablero[f][c]==next->ficha){
				tablero[f][c]=ficha;
				f--;
				c--;
				puntaje++;
				next->puntaje--;
			}
			f=f_temp;
			c=c_temp;
			tablero[f][c]=ficha;
		}
	}
	void colocar_up_right(){
		if(buscar_up_right()==true){
			int f_temp=f,c_temp=c;
			f--;
			c++;
			while(tablero[f][c]==next->ficha){
				tablero[f][c]=ficha;
				f--;
				c++;
				puntaje++;
				next->puntaje--;
			}
			f=f_temp;
			c=c_temp;
			tablero[f][c]=ficha;
		}
	}
	void colocar_down_right(){
		if(buscar_down_right()==true){
			int f_temp=f,c_temp=c;
			f++;
			c++;
			while(tablero[f][c]==next->ficha){
				tablero[f][c]=ficha;
				f++;
				c++;
				puntaje++;
				next->puntaje--;
			}
			f=f_temp;
			c=c_temp;
			tablero[f][c]=ficha;
		}
	}
	void colocar_down_left(){
		if(buscar_down_left()==true){
			int f_temp=f,c_temp=c;
			f++;
			c--;
			while(tablero[f][c]==next->ficha){
				tablero[f][c]=ficha;
				f++;
				c--;
				puntaje++;
				next->puntaje--;
			}
			f=f_temp;
			c=c_temp;
			tablero[f][c]=ficha;
		}
	}
	void colocar_fichas(){
		colocar_up();
		colocar_down();
		colocar_right();
		colocar_left();
		colocar_down_left();
		colocar_down_right();
		colocar_up_left();
		colocar_up_right();
		puntaje++;
	}
	bool revisar_jugadas(){
		int c_temp=c, f_temp=f;
		c=0;
		f=0;
		for(;f<8;f++){
			for(;c<8;c++){
				if(tablero[f][c]==' '){
					if(buscar_pos()){
						c=c_temp;
						f=f_temp;
						return true;
					     }
				}
			}
			c=0;
		}
		c=c_temp;
		f=f_temp;
		return false;
	}
public:
	bool jugadas;
	jugador *next;
	char ficha;
	int puntaje;
	jugador(char simbolo){
		ficha=simbolo;
		puntaje=2;
		jugadas=true;
	}
	jugador* key_press(char tecla){
		jugador *player;
		player=this;
		tablero[f][c]=temp;
		if(tecla==KEY_DOWN)
			if(f!=7)
				f++;
		if(tecla==KEY_UP)
			if(f!=0)
				f--;
		if(tecla==KEY_LEFT)
			if(c!=0)
				c--;
		if(tecla==KEY_RIGHT)
			if(c!=7)
				c++;
		if(tecla==KEY_ESP){
			if((tablero[f][c]==' ')&&(buscar_pos())){
				colocar_fichas();
				espacios--;
				if(next->revisar_jugadas())
					player=player->next;
			}
		}
		temp=tablero[f][c];
		return player;
	}
};



int main(){
	c=2;
	f=2;
	jugador player1('O'), player2('*');
	player1.next=&player2;
	player2.next=&player1;
	jugador *player=&player1;
	generar(tablero);
	tablero[3][3]=player1.ficha;
	tablero[4][4]=player1.ficha;
	tablero[4][3]=player2.ficha;
	tablero[3][4]=player2.ficha;
	char tecla;
	while((espacios>0)&&(player1.puntaje!=0)&&(player2.puntaje!=0)&&(tecla!=KEY_ESC)){
		tablero[f][c]='-';
		imprimir(tablero);
		cout << endl;
		cout << "Turno de la ficha: " << player->ficha << endl;
		cout << "Fichas jugador 1: " << player1.puntaje << endl;
		cout << "Fichas jugador 2: " << player2.puntaje << endl;
		tecla=getch();
		player=player->key_press(tecla);
	}
	imprimir(tablero);
	winner(tablero);
}
