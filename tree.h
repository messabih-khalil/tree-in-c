#ifndef _TREE
#define _TREE
#include <stdlib.h>

// tree nodes

typedef struct TreeNode {
  int data;
  struct TreeNode *leftChild;
  struct TreeNode *rightChild;
} TreeNode;

// check if the tree is empty
int isEmpty(TreeNode *tree);

// **** Display ****

void inOrder(TreeNode *tree);

void preOrder(TreeNode *tree);

void postOrder(TreeNode *tree);

// tree height
int treeHeight(TreeNode *tree);

// search in tree
int searchNode(int value, TreeNode *tree);

// min value of tree

TreeNode * minValue(TreeNode *tree);

// max value of tree

int maxValue(TreeNode *tree);


// insert in th tree
TreeNode *insertNewNode(TreeNode *tree, int value);

// remove from the tree

TreeNode *deleteNode(TreeNode *root, int value);
#endif