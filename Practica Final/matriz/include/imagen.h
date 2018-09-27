/**
@file 
@brief Clase imagen blanco y negro.
*/

#ifndef _IMAGEN_H_
#define _IMAGEN_H_


typedef unsigned char byte; ///< byte = 8bits almacenado en un unsigned char

/**
@brief Una imagen en blanco y negro. Cada píxel es un byte
*/
class Imagen{
private:
   byte **datos ;///< datos de la imagen
   int nfilas; 			///< número de filas de la imagen
   int ncolumnas;		///< número de columnsa de la imagen
public:
/// Construye una imagen vacía (0 filas, 0 columnas)
   Imagen(); 
   

/**
@brief Construye una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen

Construye una imagen de tamaño @a filas x @a columnas y pone todos 
sus elementos a 0. Reserva la memoria necesaria para almacenar la imagen.
*/
   Imagen(int filas, int columnas);
   
/**

Construye una copia de una imagen de tamaño @a filas x @a columnas. Reserva la memoria necesaria para almacenar la imagen.
*/
   Imagen(const Imagen &p);
   
/**
@brief Crea una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen

Dimensiona la imagen a tamaño @a filas x @a columnas y pone todos 
sus elementos a 0. Reserva la memoria necesaria para almacenar la imagen.
*/
   void crear(int filas, int columnas);
   
/**
@brief Destructor automático para los objetos 
*/ 
   ~Imagen();

/**
@brief Funcion para resetear o liberar el espacio del vector.
*/ 
  void destruir();
   
/**
@brief sobrecarga del operador de asignacion
*/ 
   void operator=(const Imagen &p);

/**
@brief sobrecarga del operador de suma
*/ 
   Imagen operator+(const Imagen &p) const;
/**
@brief Devuelve el número de filas de las imagen
@return el número de filas de la imagen
*/
   int filas()const ; 

   
/**
@brief Devuelve el número de columnas de las imagen
@return el número de columnas de la imagen
*/
   int columnas() const; 
   

/**
@brief Asigna el valor @a v a la posición (@a x,@a y) de la imagen
@param y 	fila de la imagen
@param x 	columna de la imagen 
@param v 	valor a asignar

Asigna el valor @a v a la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x 
del vector.    
*/
   void set(int y, int x, byte v); 
   
   
/**
@brief Devuelve el valor de la posición (@a x,@a y) de la imagen
@param y	 fila de la imagen
@param x	 columna de la imagen 
@return el valor de la posición (@a x,@a y) de la imagen

Devuelve el valor de la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x 
del vector.    
*/
   byte get(int y, int x) const; 
   
   
/**
@brief Asigna el valor @a v a la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector
@param v 	valor a asignar

Asigna el valor @a v a la posición @a i de la imagen considerada como vector. La posición @a i 
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la 
fila y @c x representa la columna.    
*/
   void setPos(int i, byte v); 
   
 
/**
@brief Devuelve el valor de la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector

Devuelve el valor de la posición @a i de la imagen considerada como vector. La posición @a i 
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la 
fila y @c x representa la columna.    
*/
   byte getPos(int i) const;

   
/**
@brief Carga una imagen desde un fichero 
@param nombreFichero nombre del fichero que contiene la imagen
@retval true 	si ha tenido éxito en la lectura
@retval false 	si se ha producido algún error en la lectura

Lee desde disco los datos de la imagen llamada @a nombreFichero y la guarda en la memoria. La función debe asegurarse de que la imagen es de un tipo de imagen conocido y de reservar la memoria necesaria para almacenar la imagen.
*/
   bool leerImagen(const char nombreFichero[]);
   

/**
@brief Guarda una imagen desde un fichero 
@param nombreFichero nombre del fichero que contiene la imagen
@retval true 	si ha tenido éxito en la escritura
@retval false 	si se ha producido algún error en la escritura
*/
   bool escribirImagen(const char nombreFichero[]);    

/**
@brief Rota una imagen en sentido horario 90 grados
*/
   void rotar();    
   

/**
@brief Rota una imagen en múltiplos de 90 grados
@param grados en múltiplos de 90 (90,180,270)
@param sentidoHorario Sentido en que se realizará la rotación: true (sentido horario) o false (sentido contraorario)
*/
   void rotacion(int grados, bool sentidoHorario);    
   
   
};

#endif 
