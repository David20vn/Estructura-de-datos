#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

int main() {
	
    Nodo *lista = NULL;  // Inicializar la lista como vacía
    int opcion, posicion, id;
    do {
    	opcion = menu();
    
			switch ( opcion ){
				case 1:
					lista = insertar_comienzo(lista);
					break;
				case 2:
					lista = insertar_final(lista);
					break;
				case 3:
					printf ("Digite la posicion para insertar: ");
					scanf ("%d", &posicion);
					lista = insertar_posicion(lista, posicion);
					break;
				case 4:
					printf ("'el nodo se pondra en la posicion inmediatamente anterior a la de el primer id con valor mayor a el del nodo ingresado'\n\n");
					lista = insertar_ordenado(lista);
					break;
				case 5:
					printf ("Digite el id del nodo a eliminar: ");
					scanf ("%d", &id);
					lista = eliminar( lista, id);
					break;
				case 6: 
					printf ("Digite el id del nodo a modificar: ");
					scanf ("%d", &id);
					lista = modificar(lista, id);
					break;
				case 7:
					printf ("Digite el id del nodo a consultar: ");
					scanf ("%d", &id);
					consultar(lista, id);
					break;
				case 8: 
					muestra(lista);
					break;
			}
		} while ( opcion != 9 );

    return 0;
}
