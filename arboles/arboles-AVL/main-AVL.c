#include <stdio.h>
#include "libreria-arboles-AVL.h"

int main() {
	
    Node *root = NULL;
    int option, key;
    
    do {
    	
    	option = menu();
    	while (getchar() != '\n');
    	
    	switch ( option ){
  
    	case 1:
    		printf("\nDigite el numero que desea insertar: ");
    		scanf("%d", &key);
				root = insert(root, key);
				
				break;
			case 2:
				printf("\nDigite el numero que desea eliminar: ");
    		scanf("%d", &key);
				root = delete_node(root, key);
				printf("\nEliminado correctamente.");
				break;
			case 3:
				printf("\nInorden del arbol AVL:\n");
				in_order(root);
				break;
			}
		} while ( option );
		
    return 0;
}





















