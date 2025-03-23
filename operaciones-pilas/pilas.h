
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo Nodo;

struct Nodo{
    char letra;
    Nodo* sig;
};

int menu(){
	
	int opcion;
	
	printf("\n\n\t\tMENU\n");
	printf("\n\t1) Comprobar palabra palindrome.");
	printf("\n\t2) pasar de infija a prefija.");
	printf("\n\t3) Comprobar balanceo de parentesis.");
	
	printf("\nOpcion: ");
	scanf ("%d", &opcion);
	
	return opcion;
}

int pila_vacia (Nodo* pila){
	if ( pila == NULL ){
		return 1;
	}
	return 0;
}

void push(Nodo **pila, char ch) {
	
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->letra = ch;
    nuevo->sig = *pila;
    *pila = nuevo;
    
}

char pop(Nodo **pila) {
	
	char letra;

	if ( pila_vacia(*pila) ){
		return 0;
	}
	
    Nodo *aux = *pila;
    letra = aux->letra;
    *pila = aux->sig;
    
    free(aux);
    
    return letra;
}

void llenar_pila ( Nodo** pila, char cadena[]){
	
	int i;
	
	for ( i = 0; i < strlen (cadena); i++ ){
		push( pila, cadena [strlen(cadena) - 1 -i]);
	}
}

int palindrome ( char palabra[] ){
	
	Nodo *pila=NULL;
	int i, validacion = 1;
	
	llenar_pila ( &pila, palabra );
	
	for ( i = 0; i < strlen(palabra); i++ ){
		if ( pop( &pila ) != palabra[ strlen(palabra) - 1 - i ] ){
			validacion = 0;
		}
	}
	
	free(pila);
	return validacion;
}

int balanceo ( char ecuacion[]){
	
	Nodo *pila=NULL;
	int i;
	char cerrar;
	
	for ( i = 0; i < strlen ( ecuacion ); i++ ){
		if ( ecuacion[i] == '(' || ecuacion[i] == '[' || ecuacion[i] == '{' ){
			push ( &pila, ecuacion[i] );
		} else if ( ecuacion[i] == ')' || ecuacion[i] == ']' || ecuacion[i] == '}'){
			cerrar = pop (&pila);
			if ( (ecuacion[i] == ')' && cerrar != '(') || (ecuacion[i] == ']' && cerrar != '[') || (ecuacion[i] == '}' && cerrar != '{') ){
				return 0;
			}
		}
	}
	
	if ( pila_vacia(pila) ){
		return 1;
	} else {
		return 0;
	}
}

















