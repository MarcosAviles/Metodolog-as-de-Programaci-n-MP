#include <iostream>
using namespace std;

#include "bloqueLed.h"

typedef unsigned char bloqueLed;
unsigned char mask;

void on(bloqueLed &b, int pos){
	mask = 1 << pos;
	b=b | mask;		
}

void off(bloqueLed &b, int pos){
	mask = 1 << pos;
	mask = ~ mask;
	b= b & mask;
}

bool get(bloqueLed b, int pos){
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

void print(bloqueLed b){
	for(int i=7; i>=0; i--){
		cout<<get(b,i);
	}
	cout<<endl;
}

void encender(bloqueLed &b){
		mask = 0;
		b = ~ mask;
}
void apagar(bloqueLed &b){
		mask = 0;
		b = mask;
	
}

void asignar(bloqueLed &b, const bool v[]){
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
void volcar(bloqueLed b, bool v[]){
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
void encendidos(bloqueLed b, int posic[], int &cuantos){
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

void ejemplo1(bloqueLed b){
	for(int i=7; i>=0; i--){
		on(b, i);
		print(b);
		off(b, i);

	}
	
}

void ejemplo2(bloqueLed b){
	int contador=7;
	for(int i=7; i>=4; i--){
		on(b, i);
		on(b, i-contador);
		print(b);
		off(b, i);
		off(b, i-contador);
		contador-=2;
	}	
	
	contador=1;
	for(int i=4; i<=7; i++){
		on(b, i);
		on(b, i-contador);
		print(b);
		off(b, i);
		off(b, i-contador);
		contador+=2;
		}
	
}
