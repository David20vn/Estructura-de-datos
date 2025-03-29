#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

int main() {
	
    Nodo *pila = NULL;  // Inicializar la lista como vacía
    int opcion;
    do {
    	opcion = menu();
    
			switch ( opcion ){
				case 1:
					pila = insertar(pila);
					break;
				case 2:
					pila = eliminar( pila );
					break;
				case 3:
					muestra(pila);
					break;
			}
		} while ( opcion != 4 );

    return 0;
}
