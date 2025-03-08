#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

int main() {
    Nodo *lista = NULL;  // Inicializar la lista como vacía

    // Insertar nodos
    lista = insertar_comienzo(lista);
    lista = insertar_final(lista);
		lista = insertar_posicion(lista, 2);
		lista = insertar_ordenado(lista);

		//mostrar la lista
    muestra(lista);

    return 0;
}
