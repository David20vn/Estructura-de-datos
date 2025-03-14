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
	printf("\t1) agregar al comienzo\n");
	printf("\t2) agregar al final\n");
	printf("\t3) agregar en posicion\n");
	printf("\t4) agregar ordenado\n");
	printf("\t5) eliminar\n");
	printf("\t6) modificar\n");
	printf("\t7) consultar\n");
	printf("\t8) mostrar lista\n");
	printf("\nOpcion: ");
	scanf ("%d", &opcion);
	printf("\n");
	
	return opcion;
	
}

void muestra(Nodo *lista) {
    Nodo *aux;
    printf("->");
    for (aux = lista; aux != NULL; aux = aux->sig) {
        printf("[%s - %d]-> ", aux->info.nombre, aux->info.id);
    }
    printf("\n");
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

Nodo* insertar_comienzo(Nodo *lista) {
    Info *inf = (Info*)malloc(sizeof(Info));
    lee_nodo(inf);
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = *inf;
    nuevo->sig = lista;
    lista = nuevo;
    return lista;
}

Nodo* insertar_final(Nodo *lista) {
    Info *inf = (Info*)malloc(sizeof(Info));
    lee_nodo(inf);
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = *inf;
    Nodo *actual = lista;
    
    nuevo->sig = NULL;
    
    if ( lista == NULL ){
    	return nuevo;
		}
   
    while ( actual->sig != NULL ){
    	actual = actual->sig;
		}
	
		actual->sig = nuevo;
    return lista;
}

Nodo* insertar_posicion(Nodo *lista, int posicion) {

    Info *inf = (Info*)malloc(sizeof(Info));
    lee_nodo(inf);
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = *inf;
   
    if (posicion == 0) {
        nuevo->sig = lista;
        return nuevo;
    }

    Nodo *actual = lista;
    int i;
   
    for (i = 0; i < posicion - 1 && actual != NULL; i++) {
        actual = actual->sig;
    }

    nuevo->sig = actual->sig;
    actual->sig = nuevo;

    return lista;
}

Nodo* insertar_ordenado(Nodo *lista) {
	
    Info *inf = (Info*)malloc(sizeof(Info));
    lee_nodo(inf);
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = *inf;
    Nodo *aux = lista;
   
    if ( lista == NULL || nuevo->info.id <= lista->info.id ) {
        nuevo->sig = lista;
        return nuevo;
    }
    
   
    while ( aux->sig != NULL && nuevo->info.id > aux->sig->info.id) {
    	aux = aux->sig;
    }

		nuevo->sig = aux->sig;
    aux->sig = nuevo;
    

    return lista;
    
}

int buscar(Nodo *lista, int id_buscar){
	
	int i = 0;
	Nodo *aux = lista;
	
	while ( aux->info.id != id_buscar && aux != NULL ){
		i++;
		aux = aux->sig;
	}
	
	if ( aux == NULL ){
		return -1;
	} else {
		return i;
	}	
}

Nodo* eliminar(Nodo *lista, int id_eliminar) {
	
    int posicion = buscar(lista, id_eliminar), i;
    
    if (posicion == -1) {
        printf("\nEl id no está en la lista.\n");
        return lista;
    }

    Nodo *aux = lista;
    
    if (posicion == 0) {
        Nodo *temp = lista;
        lista = lista->sig;
        free(temp);
        return lista;
    }

    for ( i = 0; i < posicion-1; i++) {
        aux = aux->sig;
    }

    Nodo *temp = aux->sig;
    aux->sig = aux->sig->sig;
    free(temp);

    return lista;
}


Nodo* modificar ( Nodo* lista, int id_modificar ){
	
	int posicion = buscar (lista, id_modificar);
	
	if ( posicion == -1 ){
		printf ("\nEl id no esta en la lista.");
		return lista;
	}
	
	lista = eliminar(lista, id_modificar);
	lista = insertar_posicion ( lista, posicion);
	
	return lista;
}

void consultar ( Nodo* lista, int id_consultar ){
	
	int i, posicion = buscar ( lista, id_consultar );
	
	if (posicion == -1) {
        printf("\nEl id no está en la lista.\n");
        return;
    }
    
	Nodo *aux = lista;
	
	for ( i = 0; i < posicion; i++ ){
		aux = aux->sig;
	}
	
	printf ( "\nId: %d\n", aux->info.id );
	printf ( "nombre: %s\n", aux->info.nombre );
}






