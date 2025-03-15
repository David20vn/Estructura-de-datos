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

int menu(){
	
	int opcion;
	
	printf("\n\t\tMENU\n\n");
	printf("\t1) agregar\n");
	printf("\t2) eliminar\n");
	printf("\t3) mostrar\n");
	printf("\t4) Salir.\n");
	printf("\nOpcion: ");
	scanf ("%d", &opcion);
	printf("\n");
	
	return opcion;
	
}
int pila_vacia ( Nodo *pila ){
	if ( pila == NULL ){
		return 1;
	}
	return 0;
}

void muestra(Nodo *pila) {
	
	if ( pila_vacia(pila)){
		printf("\nPila vacia.\n");
		return;
	}
	
    Nodo *aux;
    printf("->");
    for (aux = pila; aux != NULL; aux = aux->sig) {
        printf("[%s - %d]-> ", aux->info.nombre, aux->info.id);
    }
    printf("NULL\n");
}

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

Nodo* insertar(Nodo *pila) {
    Info *inf = (Info*)malloc(sizeof(Info));
    lee_nodo(inf);
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = *inf;
    nuevo->sig = pila;
    pila = nuevo;
    return pila;
}

Nodo* eliminar(Nodo *pila) {

	if ( pila_vacia(pila) ){
		printf ("\nLa pila ya esta vacia.\n");
		return pila;
	}
	
    Nodo *aux = pila;
    pila = pila->sig;
    free(aux);
    return pila;
}





