#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Necesario para strcpy y strlen

typedef struct Info {
  int id;
  char *nombre;
} Info;

typedef struct Nodo {
    Info info;
    struct Nodo *sig;
} Nodo;

Nodo* crear_cola(){
	return NULL;
}

int menu(){
	
	int opcion;
	
	printf("\n\n\t\tMENU\n\n");
	printf("\t1) Insertar: Añade un dato por el final de la cola\n");
	printf("\t2) Quitar: Retira (extrae) el elemento frente de la cola\n");
	printf("\t3) Cola vacía: Comprobar si la cola no tiene elementos\n");
	printf("\t4) Frente: Obtiene el elemento frente o primero de la cola\n");
	printf("\t5) mostrar lista\n");
	printf("\t6) salir\n");
	
	printf("\nOpcion: ");
	scanf ("%d", &opcion);
	printf("\n");
	
	return opcion;
	
}

//auxiliares 

void lee_nodo(Info *inf) {
    int i;
    char w[20], *pw;
    printf("Ingresa el id: ");
    scanf(" %d", &i);
    printf("Ingresa el nombre: ");
    scanf(" %[^\n]", w);
    printf("\n");
    inf->id = i;
    pw = (char*)malloc(strlen(w) + 1);
    strcpy(pw, w);
    inf->nombre = pw;
}

//1 insertar

void insertar(Nodo **cola) {
    Info *inf = (Info*)malloc(sizeof(Info));
    lee_nodo(inf);
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = *inf;
    nuevo->sig = *cola;
    *cola = nuevo;
}

//2 quitar

void eliminar(Nodo **cola) {
	
	if ( *cola == NULL ){
		printf("\nLa lista esta vacia.");
			return;
		}

    Nodo *aux = *cola;
		
		if ( aux->sig == NULL ){
			free(aux);
			*cola = NULL;
			printf("\nEliminado exitosamente.");
    	return;
		}
		
		
		while ( aux->sig->sig != NULL ) {
      aux = aux->sig;
    }
    

    Nodo *temp = aux->sig;
    aux->sig = NULL;
    free(temp);
    
    printf("\nEliminado exitosamente.");
}

// 3 cola vacia

int cola_vacia ( Nodo* cola ){
	return cola == NULL ? 1: 0;
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
    printf("\nExtraido exitosamente.");
    
    return aux;
}

//5 muestra

void muestra(Nodo *lista) {
    Nodo *aux;
    printf("->");
    for (aux = lista; aux != NULL; aux = aux->sig) {
        printf("[%s - %d]-> ", aux->info.nombre, aux->info.id);
    }
    printf("NULL\n");
}






