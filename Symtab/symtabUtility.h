#include <stdlib.h>
#include <string.h>
#define SYMBOL_SIZE_LIMIT 6


struct node{
    char symbol[7];
    unsigned char value;
    bool flag;
    struct node *left;
    struct node *right;


};



struct node *iter_next(struct node *node, char symbol[]){
    if(node == NULL){
        return NULL;
    }else if(strcmp(node->symbol, symbol) == 0){
        return node;
    }else{
        struct node *left = iter_next(node->left, symbol);
        return left?left:iter_next(node->right, symbol);
    }


}



/* newNode() allocates a new node with the given data and NULL left and
   right pointers. */
struct node *newNode(char symbol[], unsigned char value, bool flag)
{

  // Allocate memory for new node
  struct node *temp = (struct node *)malloc(sizeof(struct node));

  // Assign data to this node
  strcpy(temp->symbol, symbol);
  //strcpy(temp->value, value);
  temp->value = value;
  temp->flag = flag;

  // Initialize left and right children as NULL
  temp->left = NULL;
  temp->right = NULL;
  return(temp);

}

bool SymbolNotExist(struct node *node, char symbol[]){
    if(node == NULL){return true;}
    if(strcmp(node->symbol, symbol) == 0) {return false;}
    if(strcmp(symbol, node->symbol) < 0 ) {return SymbolNotExist(node->left, symbol);}

    return SymbolNotExist(node->right, symbol);

}

void searchTree(struct node *node, char symbol[]){
    struct node *temp = node;

    if (SymbolNotExist(node, symbol)){

        printf("Symbol %s: Doesn't exist.\n\n", symbol);
    }else{
        printf("Symbol %s:  Found.\n");
            node = iter_next(node, symbol);
            printf("%s \t  %X \t  %s\n\n", node->symbol, node->value, node->flag ? "true":"false");


    }
}

struct node *enterSymbol(struct node *node, char symbol[], unsigned char value, bool flag){

    if(isalpha(symbol[0]) && SymbolNotExist(node, symbol) && strlen(symbol) <= 6){

        if(node == NULL){
            return newNode(symbol, value, flag);
        }

        if(strcmp(symbol, node->symbol) < 0){
            node->left = enterSymbol(node->left, symbol, value, flag);
            }else if(strcmp(symbol, node->symbol) > 0){
                node->right = enterSymbol(node->right, symbol, value, flag);
            }
        } else {// IsAlpha
                printf("Cannot Insert %s.\n", symbol);
                if(isalpha(symbol[0]) == 0){
                    printf("%s is not a Alphabetic Character.\n\n", symbol);
                }else if (strlen(symbol) > 6){
                    printf("%s exceeds the size limit of 6.\n\n");
                }else if (!SymbolNotExist(node, symbol)){
                    printf("%s already exists.\n\n");
                }
            }

    return node;
}


// A utility function to do inorder traversal of BST
void printTable(struct node *root)
{
	if (root != NULL)
	{
		printTable(root->left);
		printf("%s \t  %X \t  %s\n", root->symbol, root->value, root->flag ? "true":"false");
		printTable(root->right);
	}
}



