#include <iostream>
#include <cstring>
#include "codificar.h"
#include "imagen.h"
#include "byte.h"
using namespace std;
typedef unsigned char byte;


bool ocultar(Imagen &imagen, char cadena[]){
	unsigned char mask_1, mask_2;
	bool exito;
	int aux=strlen(cadena), aux2=0, posicion_bit=7, tamanio_i=imagen.filas()*imagen.columnas();
	int tamanio_cadena=aux*8;
	if(tamanio_cadena<=tamanio_i){
		for(int i=0; i<=aux; i++){
			mask_1=cadena[i];
			for(int x=0; x<=7; x++){
				if(get(mask_1, posicion_bit)==1){
					mask_2=imagen.getPos(aux2);
					on(mask_2, 0);
					imagen.setPos(aux2, mask_2);
					aux2++;
					posicion_bit--;
				}
				else{
					mask_2=imagen.getPos(aux2);
					off(mask_2, 0);
					imagen.setPos(aux2, mask_2);
					aux2++;
					posicion_bit--;
				}
			}
			posicion_bit=7;
		}
		exito=true;
	}
	else {
		exito=false;
	}
	
	return exito;
}

bool revelar(Imagen img, char mensaje[], const int MAXTAM){
	bool exito=true;
	unsigned char mask;
	int posicion_i=0, posicion_men=0;
	int tamanio_i=(img.filas()*img.columnas());
	for(int i=0; i<=tamanio_i; i++){
		mask=0;
		for(int x=7; x>=0; x--){
			if(get(img.getPos(posicion_i),0)==1){
				on(mask, x);
				posicion_i++;
				i++;
			}
			else{
				off(mask, x);
				posicion_i++;
				i++;
			}
		}
		mensaje[posicion_men]=mask;
		posicion_men++;
	}
	int error=0;
	for(int i=0; i<=posicion_men; i++){
		if(mensaje[i]=='\0'){
			error++;
		}
	}
	if(error==0){
		exito=false;
	}
	return exito;
}
