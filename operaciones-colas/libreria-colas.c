#include <stdio.h>
#include <stdlib.h>
#include "colas.h"

int main() {

    Nodo *cola = crear_cola();  // Inicializar la lista como vacía
    int opcion, posicion, id;
    do {
    	opcion = menu();
    
			switch ( opcion ){
				case 1:
					insertar(&cola);
					break;
				case 2:
					eliminar (&cola);
					break;
				case 3:
					printf (cola_vacia(cola) ? "\nLa cola si esta vacia." : "\nLa cola no esta vacia.");
					break;
				case 4:
					frente (&cola);
					break;
				case 5:
					muestra(cola);
					break;
			}
		} while ( opcion != 6 );

    return 0;
}
