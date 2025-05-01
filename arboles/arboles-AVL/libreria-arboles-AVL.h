#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// inicio auxiliares

int menu (){

	int option;
	
	printf ("\n\n\t\tMENU");
	printf ("\n\t1) Insertar elemento.");
	printf ("\n\t2) Eliminar elemento.");
	printf ("\n\t3) Mostrar arbol.");
	printf ("\n\t0) Salir.");
	printf ("\n\nOpcion: ");
	
	scanf("%d", &option);
	
	return option;
}

int height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

int minimum_value(Node* node) {

    while (node->left != NULL) {
        node = node->left;
    }

    return node->key;
}

int maximum_value(Node* node) {

    while (node->right != NULL) {
        node = node->right;
    }

    return node->key;
}

int sheet ( Node* tree ){
	return ( tree->left == NULL && tree->right == NULL );
}

// inicio rotaciones

Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// fin rotaciones

Node* to_balance(Node *node, int balance) {

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
    
}

// fin auxiliares

// 1-insertar

Node* insert(Node* node, int key) {

    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    return to_balance ( node, balance );
}

// 2-eliminar

Node* delete_node ( Node* node, int key ){

	int minimum, maximum;
	
	if ( node == NULL ){
		return NULL;
	}
	
  if ( key < node->key ){
  	node->left = delete_node ( node->left, key );
  	
	} else if ( key > node->key ){
		node->right = delete_node ( node->right, key);
		
	} else if ( sheet(node) ){
		free(node);
		return NULL;
		
	} else if ( node->left != NULL	 ){
		maximum = maximum_value(node->left);
		node->key = maximum;
		node->left = delete_node (node->left, maximum);
		
	} else {
		minimum = minimum_value(node->right);
		node->key = minimum;
		node->right = delete_node (node->right, minimum);
	}
	
	node->height = 1 + max(height(node->left), height(node->right));
	
	int balance = getBalance ( node );
	
  return to_balance ( node, balance );
	
}

// 3-mostrar

void in_order(Node *root) {
    if (root != NULL) {
        in_order(root->left);
        printf("%d ", root->key);
        in_order(root->right);
    }
}





















