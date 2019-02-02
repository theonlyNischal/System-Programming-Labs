#include <stdlib.h>
#include <string.h>

struct node{
    char symbol[6];
    char value;
    bool flag;
    struct node *left;
    struct node *right;
};


/* newNode() allocates a new node with the given data and NULL left and
   right pointers. */
struct node *newNode(char symbol[], unsigned char value, bool flag)
{
    printf("newNode() is called.\n");

  // Allocate memory for new node
  struct node *temp = (struct node *)malloc(sizeof(struct node));

    printf("Memory allocated.\n");
  // Assign data to this node
  strcpy(temp->symbol, symbol);
  printf("Symbol assigned.\n");
  //strcpy(temp->value, value);
  temp->value = value;
  printf("Value Copied.\n");
  temp->flag = flag;

  // Initialize left and right children as NULL
  temp->left = NULL;
  temp->right = NULL;
  printf("newNode() exited.\n");
  return(temp);

}

struct node *enterSymbol(struct node *node, char symbol[], unsigned char value, bool flag){
    printf("enterSymbol called.\n");
    if(node == NULL){
        printf("Creating root node.\n");
        return newNode(symbol, value, flag);
        printf("Root node is created.\n");
    }

    if(strcmp(symbol, node->symbol) < 0){
        node->left = enterSymbol(node->left, symbol, value, flag);
        printf("Left node visited.");
    }else if(strcmp(symbol, node->symbol) > 0){
        node->right = enterSymbol(node->right, symbol, value, flag);
        printf("Right node visited.");
    }

    return node;
}


// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%s - %X - %s\n", root->symbol, root->value, root->flag ? "true":"false");
		inorder(root->right);
	}
}


