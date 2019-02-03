#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include "symtabUtility.h"



int main(){

	struct node *root = NULL;
	root = enterSymbol(root, "ORANGE", 0x32, false);
	enterSymbol(root, "PEAR", 0x1C, true);
	enterSymbol(root, "1PEAR", 0x2A, false);
	enterSymbol(root, "PEACH", 0x60, true);
	enterSymbol(root, "ORANGE", 0x0D, false);
	enterSymbol(root, "PEACH1", 0x20, true);
	enterSymbol(root, "BANANA", 0x50, false);
	enterSymbol(root, "MANGO", 0x45, true);
	enterSymbol(root, "MELLON", 0x80, true);
	enterSymbol(root, "APPLE", 0x5A, true);
	enterSymbol(root, "APPLE", 0x65, false);
	enterSymbol(root, "EGGPLANT", 0x9C, false);
	enterSymbol(root, "MANGO", 0x93, false);
	enterSymbol(root, "PINEAPPLE", 0x8C, true);


	// print inoder traversal of the BST
	    printf("\n\nSymbol\t Value\t Flag\n");
	    printf("-------------------------\n");
        printTable(root);
        printf("-------------------------\n\n");

        printf("******Searching for CARROT, APPLE, MANGO, MELLON******\n\n");

        searchTree(root, "CARROT");
        searchTree(root, "APPLE");
        searchTree(root, "MANGO");
        searchTree(root, "MELLON");
        searchTree(root, "PINEAPPLE");
        searchTree(root, "PINEAP");



getch();
}
