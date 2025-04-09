#include <string.h>
#include <stdio.h>
#include "pilas.h"

int main(){
	
	int opcion;
	char cadena[100];
	
	do {
		opcion = menu();
		while (getchar() != '\n');
		
		switch( opcion ){
			case 1:
				printf( "\n\nDigite su palabra a comprobar: ");
				scanf("%[^\n]", cadena);
				printf ( palindrome(cadena) ? "\nLa palabra si es palindrome" : "\nLa palabra no es palindrome" );
				break;
			case 2:
				printf("\n\nDigite la ecuacion a pasar de infija a posfija: ");
				scanf("%[^\n]", cadena);
				inf_a_posf(cadena);
				printf( "\nLa ecuacion es: %s", cadena );
				break;
			case 3: 
				printf( "\n\nDigite la ecuacion a evaluar el balanceo: ");
				scanf("%[^\n]", cadena);
				printf ( balanceo(cadena) ? "Esta bien balanceado" : "Esta mal balanceado" );
				break;
			case 4: 
				printf( "\n\nDigite la ecuacion a evaluar: ");
				scanf("%[^\n]", cadena);
				printf ( evaluar_posfija(cadena) ? "Bien" : "mal" );
				break;
		}
	} while ( opcion != 5 );
	
	
}


































