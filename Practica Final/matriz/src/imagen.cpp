#include <iostream>

using namespace std;

#include "imagen.h"
#include "pgm.h"

typedef unsigned char byte;


Imagen::Imagen(){ //constructor por defecto
	nfilas=0;
	ncolumnas=0;	
	datos = NULL;
} 

Imagen::Imagen(int filas, int columnas){ // constructor con parametros
	datos=new byte *[filas];
	datos[0] = new byte[filas*columnas];
	for (int i=1; i<filas; i++){
		datos[i] = datos[i-1]+columnas;
	}
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			datos[i][j]=0;
		}
	}
	nfilas=filas;
	ncolumnas=columnas;
}

Imagen::Imagen(const Imagen &p){ // constructor de copia
	nfilas=p.nfilas;
	ncolumnas=p.ncolumnas;
	datos=new byte *[nfilas];
	datos[0] = new byte[nfilas*ncolumnas];
	for (int i=1; i<nfilas; i++){
		datos[i] = datos[i-1]+ncolumnas;
	}
	for(int i=0; i<nfilas; i++){
		for(int j=0; j<ncolumnas; j++){
			datos[i][j]=0;
		}
	}
	for (int i=0; i<nfilas; i++){
		for(int x=0; x<ncolumnas; x++){
			datos[i][x]=p.datos[i][x];
		}
	}
}

void Imagen::crear(int filas, int columnas){ // metodo crear
	if(datos!=NULL){
		destruir();
	}
	datos=new byte *[filas];
	datos[0] = new byte[filas*columnas];
	for (int i=1; i<filas; i++){
		datos[i] = datos[i-1]+columnas;
	}
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			datos[i][j]=0;
		}
	}
	nfilas=filas;
	ncolumnas=columnas;
}

Imagen::~Imagen(){ // destructor por defecto
	destruir();
	
}

void Imagen::destruir(){ // metodo destruir
	if(datos!=NULL){
		delete [] datos[0];
		delete [] datos;
	}
	datos=NULL;
	nfilas=0;
	ncolumnas=0;
}

void Imagen::operator=(const Imagen &p){
	if(&p!=this){
		nfilas=p.nfilas;
		ncolumnas=p.ncolumnas;
		crear(nfilas, ncolumnas);
		for (int i=0; i<p.nfilas; i++){
			for(int x=0; x<p.ncolumnas; x++){
				datos[i][x]=p.datos[i][x];
			}
		}
	}
}

Imagen Imagen::operator+(const Imagen &p) const{
	int filas;
	if(nfilas<=p.nfilas){
		filas=p.nfilas;
	}
	else {
		filas=nfilas;
	}
	Imagen resultado(filas, ncolumnas+p.ncolumnas);
	for(int i=0; i<nfilas; i++){
		for(int x=0; x<ncolumnas; x++){
			resultado.datos[i][x]=datos[i][x];
		}
	}
	int aux=0;
	for(int i=0; i<p.nfilas; i++){
		for(int x=ncolumnas; x<resultado.ncolumnas; x++){
			resultado.datos[i][x]=p.datos[i][aux];
			aux++;
		}
		aux=0;
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
		if(y<=nfilas || x<=ncolumnas){
			datos[y][x]=v;
		}
	}
	
}

byte Imagen::get(int y, int x) const{
	byte equis;
	if(datos!=NULL){
		if(y<=nfilas || x<=ncolumnas){
			equis=datos[y][x];
		}
	}
	return equis;	
}

byte Imagen::getPos(int i) const{
	int fila, columna;
	fila=i/ncolumnas;
	columna=i%ncolumnas;
	byte aux;
	if(datos!=NULL){
		if(fila<=nfilas || columna<=ncolumnas){
			aux=datos[fila][columna];
		}
		else{
			aux=0;
		}
	}
	return aux;
}
void Imagen::setPos(int i, byte v){
	int fila, columna;
	fila=i/ncolumnas;
	columna=i%ncolumnas;
	if(datos!=NULL){
		if(fila<=nfilas || columna<=ncolumnas){
			datos[fila][columna]=v;
		}
	}
}
bool Imagen::leerImagen(const char nombreFichero[]){
	bool exito=false;
	TipoImagen tipo=infoPGM(nombreFichero, nfilas, ncolumnas);
	crear(nfilas, ncolumnas);
	
	if(tipo==IMG_PGM_BINARIO){
		exito=leerPGMBinario(nombreFichero, datos[0], nfilas, ncolumnas);
	}
	if(tipo==IMG_PGM_TEXTO){
		exito=leerPGMTexto(nombreFichero, datos[0], nfilas, ncolumnas);	
	}
	return exito;
	
}
bool Imagen::escribirImagen(const char nombreFichero[]){
	bool exito=escribirPGMTexto(nombreFichero, datos[0], nfilas, ncolumnas);	
	return exito;
}

void Imagen::rotar(){
		// Creamos un objeto nuevo auxiliar para poder copiar la imagem original rotada
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
