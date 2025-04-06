#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Necesario para strcpy y strlen

/*
crear nodo
mostrar el arbol
recorridos (inOrden, preOrden y postOrden)
buscar un elemento
eliminar un elemento
valor mínimo
valor máximo
contar nodos.
*/

typedef struct Node {
    int number;
    struct Node *left;
    struct Node *right;
} Node;

int menu(){
	
	int option;
	
	printf("\n\n\t\tMENU\n\n");
	printf("\t1) Crear nuevo nodo\n");
	printf("\t2) Imprimir arbol inOrden\n");
	printf("\t3) Imprimir arbol preOrden\n");
	printf("\t4) Imprimir arbol postOrden\n");
	printf("\t5) Buscar un elemento\n");
	printf("\t6) Valor mínimo\n");
	printf("\t7) Valor máximo\n");
	printf("\t8) Contar nodos.\n");
	printf("\nOpcion: ");
	scanf ("%d", &option);
	printf("\n");
	
	return option;
	
}

// auxiliares

void read_node ( Node *node ) {
  
	int number;
	
	printf( "\nDigite el valor del nodo: ");
	scanf ( "%d", &number );
	
  node->number = number;
  node->left = NULL; 
  node->right = NULL;


}

int empty_tree(Node* tree) {
    return tree == NULL;
}

void position_node( Node** tree, Node* node ){

	if ( empty_tree( *tree )){
		*tree = node;
		return;
	}
	
	if ( node->number < (*tree)->number ){
		position_node( &((*tree)->left), node );
	} else {
		position_node( &((*tree)->right), node );
	}
}

// 1.

void create_node ( Node **tree ){
	
	Node *new_node = (Node*) malloc( sizeof( Node ) );
	
	read_node (new_node);
	position_node( tree, new_node);
	
}

// 2.

void in_orden (Node *tree) {
    
    if ( empty_tree(tree) ){
    	return;
		}
		
		in_orden ( tree->left );
		printf ( "%d - ", tree->number );
		in_orden ( tree->right );
		
}

// 3.

void pre_orden (Node *tree) {
    
    if ( empty_tree(tree) ){
    	return;
		}
		
		printf ( "%d - ", tree->number );
		pre_orden ( tree->left );
		pre_orden ( tree->right );
		
}

// 4.

void post_orden (Node *tree) {
    
    if ( empty_tree(tree) ){
    	return;
		}
		
		post_orden ( tree->left );
		post_orden ( tree->right );
		printf ( "%d - ", tree->number );
		
}

// 5.

int search_element(Node *tree, int element) {
    if (empty_tree(tree)) {
        return 0;
    }

    if (tree->number == element) {
        return 1;
    }

    return ( search_element(tree->left, element) || search_element(tree->right, element) );
}

// 6.

int minimum_value(Node* tree) {
	
    if (empty_tree(tree)) {
        printf("Árbol vacío.\n");
        return -1;
    }

    while (tree->left != NULL) {
        tree = tree->left;
    }

    return tree->number;
}

// 7.

int maximum_value(Node* tree) {
	
    if (empty_tree(tree)) {
        printf("Árbol vacío.\n");
        return -1;
    }

    while (tree->right != NULL) {
        tree = tree->right;
    }

    return tree->number;
}

// 8.

int count_nodes ( Node *tree ){
	
	if (empty_tree(tree)) {
        return 0;
    }
    
    return ( 1 + count_nodes(tree->left) + count_nodes(tree->right) );
    
}













