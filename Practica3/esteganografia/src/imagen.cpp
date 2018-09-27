#include <iostream>

using namespace std;

#include "imagen.h"
#include "pgm.h"

typedef unsigned char byte;


Imagen::Imagen(){
	nfilas=0;
	ncolumnas=0;
} 

Imagen::Imagen(int filas, int columnas){
	if(filas*columnas<=MAXPIXELS){
		nfilas=filas;
		ncolumnas=columnas;
		for(int i=0; i<filas*columnas; i++){
			datos[i]=0;
		}
	}
}

void Imagen::crear(int filas, int columnas){
	if(filas*columnas<=MAXPIXELS){
		nfilas=filas;
		ncolumnas=columnas;
		for(int i=0; i<filas*columnas; i++){
			datos[i]=0;
		}
	}
}

int Imagen::filas(){
	return nfilas;	
}

int Imagen::columnas(){
	return ncolumnas;
}

void Imagen::set(int y, int x, byte v){
	int i=y*ncolumnas+x;
	datos[i]=v;
}

byte Imagen::get(int y, int x){
	int i=y*ncolumnas+x;
	return datos[i];
}

void Imagen::setPos(int i, byte v){
	datos[i]=v;
}

byte Imagen::getPos(int i){
	return datos[i];
}

bool Imagen::leerImagen(const char nombreFichero[]){
	bool exito=false;
	TipoImagen tipo=infoPGM(nombreFichero, nfilas, ncolumnas);
	if(tipo==IMG_PGM_BINARIO){
		if(nfilas*ncolumnas<=MAXPIXELS){
			exito=leerPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
		}
	}
	return exito;
	
}
bool Imagen::escribirImagen(const char nombreFichero[]){
	bool exito=escribirPGMBinario(nombreFichero, datos, nfilas, ncolumnas);	
	return exito;
}

