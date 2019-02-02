#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include "symtabUtility.h"



int main(){
    printf("I am in the main.\n");

	struct node *root = NULL;
	root = enterSymbol(root, "ORANGE", 0x32, false);
	enterSymbol(root, "PEAR", 0x1C, true);
	enterSymbol(root, "BANANA", 0x50, false);
	enterSymbol(root, "MANGO", 0x45, true);
	enterSymbol(root, "MELLON", 0x80, true);
	enterSymbol(root, "APPLE", 0x5A, true);

	// print inoder traversal of the BST
	inorder(root);



getch();
}
