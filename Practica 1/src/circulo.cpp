#include <iostream>
#include "circulo.h"
#include <cmath>
using namespace std;

Circulo::Circulo() {
	radio = 0;
}

Circulo::Circulo(Punto p, double rradio) {
	radio = rradio;
	centro = p;
}

void Circulo::set(Punto p, double rradio) {
	radio = rradio;
	centro = p;
}


Punto Circulo::getCentro()  {
	return centro;
}

double Circulo::getRadio()  {
	return radio;
}

void Circulo::escribir() {
    // Formato de escritura del círculo: radio-(x,y)
    cout << radio << "-";
    centro.escribir();
}

void Circulo::leer(){
    // Formato de lectura del círculo: radio-(x,y)
    char car;

    cin >> radio;
    cin >> car; //Leer -
    centro.leer();
}

double Circulo::area() {
    return M_PI*radio*radio;
}
