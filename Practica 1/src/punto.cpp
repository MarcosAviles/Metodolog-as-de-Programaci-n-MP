#include <iostream>
#include "punto.h"
using namespace std;

Punto::Punto() {
    x=0;
    y=0;
}

Punto::Punto(double px, double py) {
    x=px;
    y=px;
}

double Punto::getX() {
	return x;
}

double Punto::getY() {
	return y;
}

void Punto::setX(double px) {
	x = px;
}

void Punto::setY(double py) {
	y = py;
}


void Punto::escribir() {
    // Formato de escritura del punto: (x,y)
    cout << "(" << x << "," << y << ")";
}

void Punto::leer(){
    // Formato de lectura del punto: (x,y)
    char car;
    cin >> car >> x >> car >> y >> car;
}
