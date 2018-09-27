#include <iostream>

using namespace std;

#include "bloqueLed.h"

int main(){
    bloqueLed b;
    int posiciones[8];
    int size;

    apagar(b);
    cout << "\nBloque apagado LEDs: ";
    print(b);
    // enciendo dos LEDs
    on(b,5); 
    on(b,7);
    cout << "\nEnciendo el 5 y el 7: ";
    print(b);
    cout << "\nAhora enciendo los LEDs 0, 1 y 2\n";
    on(b,0);
    print(b);
    on(b,1);
    print(b);
    on(b,2);
    print(b);

    cout << "\nLos LEDs encendidos estan en las posiciones: ";
    encendidos(b,posiciones, size); 
    for(int i=0; i< size; i++)
        cout << posiciones[i] << ",";

    cout << endl;  

    cout << "\nTodos encendidos: ";
    encender(b);
    print(b);

    cout << "\nTodos apagados: ";
    apagar(b);
    print(b);


    cout << "\nAhora la animacion\nEjemplo 1 \n";
    // aqui debes escribir las instrucciones para que se muestre 
    // el primer ejemplo de animacion.
    ejemplo1(b);

    cout << "\n\nEjemplo 2 \n";
    // aqui debes escribir las instrucciones para que se muestre 
    // el segundo ejemplo de animacion. 
	ejemplo2(b);
	
	
	cout<<"\n\nAsignamos una secuencia en este caso: (true,false,true,false,true,false,true,false)"<<endl;
	bool v[]={true,false,true,false,true,false,true,false};
	asignar(b, v);
	print(b);
	
	cout<<"\n\nRealizamos la funcion volcar"<<endl;
	bool v2[8]; // Creamos un nuevo array booleano para verificar que 
	on(b,0);	// verdaderamente se vuelva la informacion en el array
	volcar(b, v2);
	
}
