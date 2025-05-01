#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

int main() {
	
    Node *tree = NULL;
    int option, number, minimum, maximum;
    do {
    	option = menu();
    	while (getchar() != '\n');
    
			switch ( option ){
				case 1:
					create_node ( &tree );
					printf( "\nCreado exitosamente.");
					break;
				case 2:
					in_orden (tree);
					break;
				case 3:
					pre_orden (tree);
					break;
				case 4:
					post_orden (tree);
					break;
				case 5:
					printf ("\nDigite el numero del nodo a buscar: ");
					scanf ("%d", &number);
					while (getchar() != '\n');
					printf( search_element(tree, number ) ? "El numero si se encuentra en el arbol." : "El numero no se encuentra en el arbol." );
					break;
				case 6:
					minimum = minimum_value(tree);
					if ( minimum != -1 )
						printf( "El valor minimo es: %d", minimum );
					break;
				case 7:
					maximum = maximum_value(tree);
					if ( maximum != -1 )
						printf( "El valor maximo es: %d", maximum );
					break;
				case 8: 
					printf( "El arbol tiene %d nodos", count_nodes(tree));
					break;
				case 9: 
					printf ("\nDigite el numero del nodo a eliminar: ");
					scanf ("%d", &number);
					while (getchar() != '\n');
					
					delete_node(&tree, number );
					break;
			}
		} while ( option != 10 );

    return 0;
}




