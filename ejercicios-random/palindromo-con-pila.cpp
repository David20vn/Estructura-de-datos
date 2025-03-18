#include <stdio.h>
#include <string.h>

int main(){
	
	char palabra[100], pila[100];
	int i, validacion = 1;
	
	printf ("Digite la palabra a comprobar: ");
	scanf("%s", palabra);
	
	strcpy( pila, palabra);
	
	for ( i = 0; i < strlen(palabra)/2; i++ ){
		if (pila[i] != palabra[strlen(palabra)-i-1] ){
			validacion = 0;
		}
	}
	
	printf( validacion ? "La palabra si es palindromo." : "La palabra no es palindromo.");
	
	return 0;
	
}
