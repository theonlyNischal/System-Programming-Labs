#include <stdlib.h>
#include <string.h>

struct node{
    char symbol[6];
    unsigned char value;
    bool flag;
    struct node *left;
    struct node *right;
};


/* newNode() allocates a new node with the given data and NULL left and
   right pointers. */
struct node* newNode(char symbol, unsigned char value, bool flag)
{
  // Allocate memory for new node
  struct node* node = (struct node*)malloc(sizeof(struct node));

  // Assign data to this node
  strcpy(node->symbol, symbol);
  strcpy(node->value, value);
  node->flag = flag;

  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}
