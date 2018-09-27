#include<iostream>
#include<imagen.h>

using namespace std;

int main(){
    Imagen origen;
    Imagen destino(150,200);
	
	// Crear un degradado en la imagen destino
    for (int i=0; i < destino.filas()*destino.columnas(); i++)
		   destino.setPos(i, i%destino.columnas()+20);
	   
	// Guardar la imagen destino en el fichero degradado.pgm
	if (destino.escribirImagen("degradado_texto.pgm")){
		// si todo va bien
		cout << "degradado_texto.pgm guardado correctamente \n";
		cout << "usa: display degradado_texto.pgm para ver el resultado\n";
	} else { // si error
		cerr << "Error guardando la imagen degradado_texto.pgm\n";
		return 1;
	}
	
	// Leer la imagen lena.pgm
	if (!origen.leerImagen("lena_texto.pgm")){
		cerr << "error leyendo lena_texto.pgm\n";
		return 1;
	}
	
	// Recortar un trozo de la imagen origen
	destino.crear(40,90);
	for (int i=0; i < destino.filas(); i++)
		for (int j=0; j < destino.columnas(); j++)
			destino.set(i, j, origen.get(i+110,j+100));
		
	// Guardar la imagen destino en el fichero trozo.pgm
	if (destino.escribirImagen("trozo_texto.pgm")){
		// si todo va bien
		cout << "trozo_texto.pgm guardado correctamente \n";
		cout << "usa: display trozo_texto.pgm para ver el resultado\n";
	} else { // si error
		cerr << "Error guardando la imagen trozo_texto.pgm\n";
		return 1;
	}	
	
	return 0;
}
