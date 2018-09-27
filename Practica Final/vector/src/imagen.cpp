#include <iostream>

using namespace std;

#include "imagen.h"
#include "pgm.h"

typedef unsigned char byte;


Imagen::Imagen(){
	nfilas=0;
	ncolumnas=0;	
	datos = NULL;
} 

Imagen::Imagen(int filas, int columnas){
	datos=new byte [filas*columnas];
	for(int i=0; i<filas*columnas; i++){
		datos[i]=0;
	}
	nfilas=filas;
	ncolumnas=columnas;
}

Imagen::Imagen(const Imagen &p){
	nfilas=p.nfilas;
	ncolumnas=p.ncolumnas;
	datos=new byte [nfilas*ncolumnas];
	for(int i=0; i<nfilas*ncolumnas; i++){
		datos[i]=0;
	}
	for (int i=0; i<p.nfilas*p.ncolumnas; i++){
		datos[i]=p.datos[i];
	}
	
}

void Imagen::crear(int filas, int columnas){
	if(datos!=NULL){
		destruir();
	}
	datos=new byte [filas*columnas];
	for(int i=0; i<filas*columnas; i++){
		datos[i]=0;
	}
	nfilas=filas;
	ncolumnas=columnas;
}

Imagen::~Imagen(){
	destruir();
}

void Imagen::destruir(){
	if(datos!=NULL){
		delete [] datos;
	}
	datos=NULL;
	nfilas=0;
	ncolumnas=0;
}

void Imagen::operator=(const Imagen &p) {
	if(&p!=this){
		crear(p.nfilas, p.ncolumnas);
		for(int i=0; i<nfilas*ncolumnas; i++){
			datos[i]=p.datos[i];
		}
	}
}

Imagen Imagen::operator+(const Imagen &p) const{
	int filas;
	if(nfilas<p.nfilas){
		filas=p.nfilas;
	}
	else {
		filas=nfilas;
	}
	Imagen resultado(filas, ncolumnas+p.ncolumnas);
	int posicion=0;
	for(int i=0; i<resultado.nfilas; i++){
		if(i<nfilas){
			for(int x=0; x<ncolumnas; x++){
				resultado.datos[posicion]=datos[i*ncolumnas+x];
				posicion++;
			}
		}
		else{
			for(int x=0; x<ncolumnas; x++){
				posicion++;
			}
		}
		if(i<p.nfilas){
			for(int j=0; j<p.ncolumnas; j++){
				resultado.datos[posicion]=p.datos[i*p.ncolumnas+j];
				posicion++;
			}
		}
		else{
			for(int j=0; j<p.ncolumnas; j++){
				posicion++;
			}
		}
	}
	return resultado;
}

int Imagen::filas() const {
	return nfilas;	
}

int Imagen::columnas() const {
	return ncolumnas;
}

void Imagen::set(int y, int x, byte v){
	if(datos!=NULL){
		int i=y*ncolumnas+x;
		if(i < nfilas *ncolumnas)
		datos[i]=v;
	}
	
}

byte Imagen::get(int y, int x) const{
	byte equis;
	if(datos!=NULL){
		int i=y*ncolumnas+x;
		if(i < nfilas *ncolumnas){
			equis=datos[i];
		}
	}
	return equis;
	
}


void Imagen::setPos(int i, byte v){
	if(datos!=NULL){
		if(i<nfilas*ncolumnas){
			datos[i]=v;
		}
	}
}

byte Imagen::getPos(int i) const{
	byte aux;
	if(datos!=NULL){
		if(i<nfilas*ncolumnas){
			aux=datos[i];
		}
		else{
			aux=0;
		}
	}
	return aux;
}

bool Imagen::leerImagen(const char nombreFichero[]){
	bool exito=false;
	TipoImagen tipo=infoPGM(nombreFichero, nfilas, ncolumnas);
	crear(nfilas, ncolumnas);
	
	if(tipo==IMG_PGM_BINARIO){
		exito=leerPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
	}
	if(tipo==IMG_PGM_TEXTO){
		exito=leerPGMTexto(nombreFichero, datos, nfilas, ncolumnas);	
	}
	return exito;
	
}
bool Imagen::escribirImagen(const char nombreFichero[]){
	bool exito=escribirPGMTexto(nombreFichero, datos, nfilas, ncolumnas);	
	return exito;
}

void Imagen::rotar(){
		Imagen ImagenRotar(ncolumnas,nfilas);
		int pos=0;
		for(int i=0; i<ncolumnas; i++){
			for (int j=nfilas-1; j>=0; j--){
				ImagenRotar.setPos(pos,get(j,i));
				pos++;	
			}
		}
		crear(ImagenRotar.filas(), ImagenRotar.columnas());	
		for(int x=0; x<nfilas*ncolumnas; x++){
			setPos(x,ImagenRotar.getPos(x));
		}
}
void Imagen::rotacion(int grados, bool sentidoHorario){
	int vueltas;
	if(sentidoHorario){
		vueltas=grados/90;
		for(int i=0; i<vueltas; i++){
			rotar();
		}
	}
	if(!sentidoHorario){
		vueltas=(360-grados)/90;
		for(int i=0; i<vueltas; i++){
			rotar();
		}
	}
	
}     
