#include <iostream>
using namespace std;

#include "byte.h"

typedef unsigned char byte;
unsigned char mask;

void on(byte &b, int pos){
	mask = 1 << pos;
	b=b | mask;		
}

void off(byte &b, int pos){
	mask = 1 << pos;
	mask = ~ mask;
	b= b & mask;
}

bool get(byte b, int pos){
	unsigned char aux;
	bool estado;
	mask = 1 << pos;
	aux=mask & b;
	if(aux==mask){
		estado=true;
	}
	else{
		estado=false;
	}
	return estado;
}

void print(byte b){
	for(int i=7; i>=0; i--){
		cout<<get(b,i);
	}
}

void encender(byte &b){
		mask = 0;
		b = ~ mask;
}
void apagar(byte &b){
		mask = 0;
		b = mask;
	
}

void asignar(byte &b, const bool v[]){
	int contador=7;
	for(int i=0; i<=7; i++){
		if(v[i]==true){
			on(b, contador);
		}
		else{
			off(b, contador);
		}
		contador--;
	}
}
void volcar(byte b, bool v[]){
	int contador=7;
	for(int i=0; i<=7; i++){
		v[i]=get(b, contador);
		contador--;
	}
	for(int i=0; i<=7; i++){
		cout<<v[i];
	}
	cout<<endl;
}
void encendidos(byte b, int posic[], int &cuantos){
	cuantos=0;
	int contador=0;
	for(int i=0; i<=7; i++){
		if(get(b,i)){
			posic[cuantos]=contador;
			cuantos++;
		}
		contador++;
	}
}


