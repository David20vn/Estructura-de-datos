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

void muestra(Nodo *lista) {
    Nodo *aux;
    printf("->");
    for (aux = lista; aux != NULL; aux = aux->sig) {
        printf("[%s]-> ", aux->info.nombre);
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
    pw = malloc(strlen(w) + 1);
    strcpy(pw, w);
    inf->nombre = pw;
}

Nodo* insertar_comienzo(Nodo *lista) {
    Info *inf = malloc(sizeof(Info));
    lee_nodo(inf);
    Nodo *nuevo = malloc(sizeof(Nodo));
    nuevo->info = *inf;
    nuevo->sig = lista;
    lista = nuevo;
    return lista;
}

Nodo* insertar_final(Nodo *lista) {
    Info *inf = malloc(sizeof(Info));
    lee_nodo(inf);
    Nodo *nuevo = malloc(sizeof(Nodo));
    nuevo->info = *inf;
    Nodo *actual;
   
    for ( actual = lista; actual != NULL; actual = actual->sig){
    if ( actual->sig == NULL ){
    actual->sig = nuevo;
    nuevo->sig = NULL;
}
}

    return lista;
}

Nodo* insertar_posicion(Nodo *lista, int posicion) {
    Info *inf = malloc(sizeof(Info));
    lee_nodo(inf);
    Nodo *nuevo = malloc(sizeof(Nodo));
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
	
    Info *inf = malloc(sizeof(Info));
    lee_nodo(inf);
    Nodo *nuevo = malloc(sizeof(Nodo));
    nuevo->info = *inf;
    Nodo *aux = lista;
   
    if ( lista == NULL || nuevo->info.id <= lista->info.id ) {
        nuevo->sig = lista;
        return nuevo;
    }
    
   
    while ( nuevo->info.id > aux->info.id) {
    	aux = aux->sig;
    }

		nuevo->sig = aux->sig;
    aux->sig = nuevo;
    

    return lista;
    
}
