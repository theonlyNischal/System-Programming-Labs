#include <stdlib.h>
#include <string.h>



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

    /*
    if (node == NULL)
    return NULL;
else if (node->number == key)
    return node;
else {
    data *left = search(node->left, key);
    return left? left: search(node->right, key);
}*/
}


/*struct node *iter_next(struct node* node){
    struct node* rightResult = NULL;

    if(node==NULL)
        return NULL;

    while(node->left && !(node->left->visited))
        node = node->left;

    if(!(node->visited))
        return node;

    //move right
    rightResult = iter_next(node->right);

    if(rightResult)
        return rightResult;

    while(node && node->visited)
        node = node->parent;

    return node;
}*/






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

        printf("Symbol %s: Doesn't exist.\n", symbol);
    }else{
        printf("Symbol %s:  Found.\n");
            //while(strcmp(node->symbol, symbol) != 0){
              //  node = iter_next(node, symbol);
            //}
            node = iter_next(node, symbol);
            printf("%s \t  %X \t  %s\n", node->symbol, node->value, node->flag ? "true":"false");


    }
}

struct node *enterSymbol(struct node *node, char symbol[], unsigned char value, bool flag){

    if(isalpha(symbol[0]) && SymbolNotExist(node, symbol)){

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
                if(isalpha(symbol[0])){
                    printf("%s already exist.\n", symbol);
                }else{
                    printf("%s is not a Alphabetic Character.\n", symbol);
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



