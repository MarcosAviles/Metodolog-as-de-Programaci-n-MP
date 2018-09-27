#include "punto.h"
#include "circulo.h"
#include <cmath>
#include <iostream>
using namespace std;

/**
@brief Calcula la distancia entre dos puntos
@param p1 primer punto
@param p2 segundo punto
@return la distancia entre el punto @a p1 y el punto @a p2
*/
double distancia(Punto p1, Punto p2){
    return sqrt((p1.getX()-p2.getX())*(p1.getX()-p2.getX()) +
         (p1.getY()-p2.getY())*(p1.getY()-p2.getY()));
}

/**
@brief Calcula el punto que está entre dos puntos dados con distancia mínima a ambos
@param p1 primer punto
@param p2 segundo punto
@return un punto entre el punto @a p1 y el punto @a p2 con distancia mínima a ambos
*/
Punto puntoMedio(Punto p1, Punto p2){
    Punto pMedio;
    pMedio.setX((p1.getX()+p2.getX())/2.0);
    pMedio.setY((p1.getY()+p2.getY())/2.0);
    return pMedio;
}

/**
@brief Calcula la distancia entre dos circulos
@param c1 primer círculo
@param c2 segundo círculo
@return la distancia entre el círculo @a c1 y el círculo @a c2

La distancia entre dos círculos se define como la distancia entre los centros menos los dos radios.
Nótese que la distancia puede ser negativa si los círculos se intersecan
*/
double distancia (Circulo c1, Circulo c2){
    Punto centro1, centro2;
    double dist;

    centro1=c1.getCentro();
    centro2=c2.getCentro();
    dist=distancia(centro1,centro2)-c1.getRadio()-c2.getRadio();
    return dist;
}

/**
@brief Comprueba si un punto es interior a un círculo
@param p punto a comprobar
@param c circulo
@retval true si el punto @a p es interior al círculo @a c
@retval false en caso contrario
*/
bool interior (Punto p, Circulo c){
    if(distancia(p,c.getCentro())<=c.getRadio()) {
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    Circulo c1,c2;

    do {
        cout << "Introduzca un circulo en formato radio-(x,y): ";
        c1.leer();
        cout << "Introduzca otro circulo: ";
        c2.leer();
    } while (distancia(c1.getCentro(),c2.getCentro())==0);

    Circulo res;

    res.set(puntoMedio(c1.getCentro(),c2.getCentro()),
                     distancia(c1.getCentro(),c2.getCentro())/2);
    cout << "El círculo que pasa por los dos centros es: ";
    res.escribir();
    cout << endl;
}

