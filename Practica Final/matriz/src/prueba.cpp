/*
METODOLOGIAS DE PROGRAMACION
MODULO DE PRUEBAS - VERSION INICIAL
*/

#include <iostream>
#include <cstring>
#include <imagen.h>
#include <codificar.h>
#include <byte.h>
#include <string>

using namespace std;

int main(){
	Imagen original;
	 bool exito= true;
		
	/***************** BLOQUE 1 ****************************************/
	// Crear una U blanca sobre fondo negro
	cout << "\n***Bloque 1: generacion y escritura de Imagen ***" << endl;
	cout << "\nConstruir Imagen imgBase usando constructor con parametros" << endl;
	Imagen degrada(200,100);
    for (int i=0; i < degrada.filas(); i++)
    	for (int j=5; j < 15; j++)
		{ degrada.set(i,j,255);
		  degrada.set(i,80+j,255);
		}
	
	for (int i=180; i < 190; i++)
    	for (int j=5; j < degrada.columnas()-5; j++)
     		   degrada.set(i,j,255);
		
	cout << "\nGuardar Imagen construida en imgBase.pgm" << endl;   
	// Guardar la imagen destino en el fichero imgBase.pgm
	if (!degrada.escribirImagen("imagenes/imgBase.pgm"))
		{exito = false; return(-1);}
	
	cout << "\n*** FIN Bloque 1***n" << endl;		
	
	/***************** BLOQUE 2 ****************************************/
	cout << "\n*** Bloque 2: cargar imagen, rotar, salvar ***" << endl;		
	
	char entrada[50] = "imagenes/imgBase.pgm";
	char salida1[50] = "imagenes/img1.pgm";
	char salida2[50] = "imagenes/img2.pgm";

	cout << "Cargar Imagen" << endl;
	if(!original.leerImagen(entrada))
		{exito = false; return(-1);}
    
	cout << "Construir Imagen img1 con constructor de copia" << endl;
	Imagen img1(original);
	cout << "Rotar y salvar img1" << endl;
	img1.rotacion(90,true);
	if(!img1.escribirImagen(salida1))
		{exito = false; return(-1);}
	
	cout << "Construir Imagen img2 con operador de asignacion" << endl;
	Imagen img2 = img1;
	cout << "Rotar y salvar img2" << endl;
	img2.rotacion(180,false);
	if(!img2.escribirImagen(salida2))
		{exito = false; return(-1);}

	cout << "\n*** FIN Bloque 2 ***" << endl;		
	
	/***************** BLOQUE 3 ****************************************/
	

	cout << "\n*** Bloque 3: Ocultar / Revelar ***" << endl;		
	char entrada_b3[50] = "imagenes/img2.pgm";
	char salida_b3[50] = "imagenes/img2_msg.pgm";
	Imagen imgB3;
	
	cout << "Leo imagen img2.pgm desde fichero" << endl;
	if(!imgB3.leerImagen(entrada_b3))
		{exito = false; return(-1);}

	char mensaje[26]= "Mensaje en practica final";
		
	cout << "Voy a ocultar la cadena '" << mensaje << "' y el '\\0' en la imagen\n";
		
	if (!ocultar(imgB3, mensaje)){
		cout << "Error: El mensaje es muy largo para ocultarlo en la imagen\n";
		return 1;
		}
	cout << "Salvo imagen con mensaje incrustado img2_msg.pgm" << endl;
	if(!imgB3.escribirImagen(salida_b3))
		{exito = false; return(-1);}

	cout << "Leo imagen con mensaje incrustado img2_msg.pgm" << endl;
	Imagen decode;
	if(!decode.leerImagen(salida_b3))
		{exito = false; return(-1);}

	if (!revelar(decode, mensaje, 26)){
		cout << "Error: La imagen no contiene un mensaje o el mensaje es demasiado largo\n";
		return 1;
		}
	else 
		cout << "El mensaje oculto en la imagen es: " << mensaje << endl;

	cout << "\n*** FIN Bloque 3 ***" << endl;		
	/***************** BLOQUE 4 (opcional ) ****************************************/
	

	cout << "*** Bloque 4 (opcional): sobrecarga de la suma ***" << endl;
	
	Imagen base,izq,completa;
	
	cout << "Leer Imagen imgBase.pgm desde fichero" << endl;
	if(!base.leerImagen(entrada))
		{exito = false; return(-1);}
    
	cout << "Rotacion y asignacion" << endl;
	base.rotacion(90,true);
	Imagen der = base;
	base.rotacion(90,true);
	izq = base;
	cout << "Aplico operador + sobrecargado" << endl;
	completa = izq + der;
	char salida[50] = "imagenes/concat.pgm";
	cout << "Guardar Imagen resultante en concat.pgm" << endl;
	if(!completa.escribirImagen(salida))
		{exito = false; return(-1);}

	cout << "\n*** FIN Bloque 4. ***" << endl;		
	
	return(exito);
}
