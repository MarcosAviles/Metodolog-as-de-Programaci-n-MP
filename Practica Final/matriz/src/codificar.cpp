#include <iostream>
#include <cstring>
#include "codificar.h"
#include "imagen.h"
#include "byte.h"
using namespace std;
typedef unsigned char byte;


bool ocultar(Imagen &imagen, char cadena[]){
	byte mask_1, mask_2;
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

bool revelar(Imagen imagen, char mensaje[] ,const int MAXTAM){
	byte letra;
	
	int a=0;
	
	do{
		letra=1;
		int aux=0;
		for(int i=7; i>=0 ;i--){
			if( get(imagen.getPos(a*8+aux),0 ))
				on(letra , i);
			else
				off(letra , i);	
			aux++;	
		}
		mensaje[a] = letra;
		a++;
		
	}while( letra != '\0' && a<=MAXTAM);
	
	if(a <= MAXTAM)
		return true;
	else 
		return false;

}
