#include <stdio.h>
#include "libreria-arboles-AVL.h"

int main() {
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorden del árbol AVL:\n");
    in_order(root);

    return 0;
}

