#include "imagen.h"
/**
@file 
@brief Clase codificar un mensaje oculto.
*/

#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_

bool ocultar(Imagen &imagen, char cadena[]);
bool revelar(Imagen img, char mensaje[], const int MAXTAM);

#endif

