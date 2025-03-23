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
			/*case 2:
				printf("\n\nDigite la ecuacion a pasar de infija a prefija: ");
				scanf("%[^\n]", cadena);
				printf( "\nLa ecuacion es: %s", inf_a_posf(cadena) );
				break;*/
			case 3: 
				printf( "\n\nDigite la ecuacion a evaluar el balanceo: ");
				scanf("%[^\n]", cadena);
				printf ( balanceo(cadena) ? "Esta bien balanceado" : "Esta mal balanceado" );
				break;
		}
	} while ( opcion != 4 );
	
	
}
