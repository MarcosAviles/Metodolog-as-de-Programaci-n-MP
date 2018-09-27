#include <iostream>
#include <cstring>
#include "imagen.h"
#include "codificar.h"
#include "byte.h"
using namespace std;
int const MAXIMAGEN=100;
int const MAXTAM=256;

int main(){
	int opcion;
	char mensaje[MAXTAM];
	char nombre_imagen[MAXIMAGEN];
	Imagen entrada;
	do{
		cout<<"1 - Ocultar:"<<endl<<"2 - Revelar:"<<endl<<"3 - Salir:"<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"Introduzca la imagen de entrada:";
				cin.getline(nombre_imagen, MAXTAM);
				cin.getline(nombre_imagen, MAXTAM);
				if (!entrada.leerImagen(nombre_imagen)){
					cerr << "error leyendo "<<nombre_imagen<<"\n";
				return 1;
				}
				cout<<"Introduzca la imagen de salida:";
				cin.getline(nombre_imagen, MAXTAM);
				cout<<"Introduzca el mensaje:";
				cin.getline(mensaje, MAXTAM);
				if (!ocultar(entrada, mensaje)){
					cout << "Error: El mensaje es muy largo para ocultarlo en la imagen\n";
				return 1;
				}
				if (entrada.escribirImagen(nombre_imagen));
				else { // si error
					cerr << "Error guardando la imagen"<< nombre_imagen <<"\n";
				return 1;
				}
				cout<<"Ocultando..."<<endl;
				break;
			case 2: 
				cout<<"Introduzca la imagen de entrada:";
				cin.getline(nombre_imagen, MAXTAM);
				cin.getline(nombre_imagen, MAXTAM);
				if (!entrada.leerImagen(nombre_imagen)){
					cerr << "error leyendo "<<nombre_imagen<<" \n";
				return 1;
				}
				if (!revelar(entrada, mensaje, MAXTAM)){
					cout << "Error: La imagen no contiene un mensaje o el mensaje es demasiado largo\n";
					return 1;
				}
				else {
					cout << "El mensaje oculto en la imagen es: '" << mensaje << "'\n";
				}
				break;
			case 3: break;
		}
	}
	while(opcion!=3);
}
