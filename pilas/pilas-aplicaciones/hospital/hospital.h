#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    struct Nodo *sig;
} Nodo;

//1 insertar

void insertar(Nodo **cola) {

    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->sig = *cola;
    *cola = nuevo;
}

//2 quitar

void eliminar(Nodo **cola) {
	
	if ( *cola == NULL ){
			return;
		}

    Nodo *aux = *cola;
		
	if ( aux->sig == NULL ){
		free(aux);
		*cola = NULL;
    	return;
	}
		
		
	while ( aux->sig->sig != NULL ) {
      	aux = aux->sig;
    }
    

    Nodo *temp = aux->sig;
    aux->sig = NULL;
    free(temp);

}

// 4 obtener frente

Nodo* frente ( Nodo** cola ){
	if ( *cola == NULL ){
			return NULL;
		}

    Nodo *aux = *cola;
		
	while ( aux->sig != NULL ) {
      aux = aux->sig;
    }
    
    eliminar (cola);
    
    return aux;
}

