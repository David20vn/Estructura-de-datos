
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Nodo Nodo;

struct Nodo{
    char letra;
    Nodo* sig;
};

int menu(){
	
	int opcion;
	
	printf("\n\n\t\tMENU\n");
	printf("\n\t1) Comprobar palabra palindrome.");
	printf("\n\t2) pasar de infija a posfija.");
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

// Prioridad de operadores
int prioridad(char operador) {
    switch (operador) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

char cima ( Nodo* pila ){
	if ( pila_vacia ( pila )){
		return 0;
	}
	
	return pila->letra;
}

// Conversión de infija a posfija
void inf_a_posf (char *expresion) {
	
    Nodo* pila = (Nodo*) malloc ( sizeof(Nodo) );
    pila = NULL;
    char *posfija = (char*) malloc ( sizeof(char) * strlen(expresion) + 1), temporal;
    posfija[0] = '\0';
    int i;

    for ( i = 0; expresion[i] != '\0'; i++) {
    	
        char caracter = expresion[i];

        if (isalnum(caracter)) {
            // Si es operando, agregar a la salida
            strncat(posfija, &caracter, 1);
            
        } else if (caracter == '(') {
        	
            push(&pila, caracter);
            
        } else if (caracter == ')') {
            // Sacar elementos hasta encontrar '('
            while (!pila_vacia(pila) && cima(pila) != '(') {
            	
            		temporal = pop(&pila);
                strncat(posfija, &temporal, 1);
                
            }
            pop(&pila); // Eliminar el paréntesis izquierdo
            
        } else { // Es un operador
            while (!pila_vacia(pila) && prioridad(caracter) <= prioridad(cima(pila))) {
                temporal = pop(&pila);
                strncat(posfija, &temporal, 1);
            }
            push(&pila, caracter);
        }
    }

    // Sacar los elementos restantes de la pila
    while (!pila_vacia(pila)) {
        temporal = pop(&pila);
        strncat(posfija, &temporal, 1);
    }

    strcpy ( expresion, posfija );
    free(posfija);
}
















