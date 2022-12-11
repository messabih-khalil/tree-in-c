#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VALEUR_MAX 100000
//  global variable

TreeNode *root = NULL;
int numberOfElements = 0;

// check if the tree is empty

int isEmpty(TreeNode *tree) { return tree == NULL; }

// **** Display ****

void inOrder(TreeNode *tree) {
  if (!isEmpty(tree)) {
    /* code */
    inOrder(tree->leftChild);
    printf("%d ,", tree->data);
    inOrder(tree->rightChild);
  }
}

void preOrder(TreeNode *tree) {
  if (!isEmpty(tree)) {
    /* code */
    printf("%d ,", tree->data);
    preOrder(tree->leftChild);
    preOrder(tree->rightChild);
  }
}

void postOrder(TreeNode *tree) {
  if (!isEmpty(tree)) {
    /* code */
    postOrder(tree->leftChild);
    postOrder(tree->rightChild);
    printf("%d ,", tree->data);
  }
}

// **** Tree Operation ****

TreeNode *createNewNode(int value) {
  TreeNode *newNode = malloc(sizeof(TreeNode));
  newNode->data = value;
  newNode->leftChild = NULL;
  newNode->rightChild = NULL;
  numberOfElements++;
  return newNode;
}

TreeNode *insertNewNode(TreeNode *tree, int value) {
  if (tree == NULL) {
    tree = createNewNode(value);
  } else {
    if (value > tree->data) {
      tree->rightChild = insertNewNode(tree->rightChild, value);
    } else {
      tree->leftChild = insertNewNode(tree->leftChild, value);
    }
  }

  return tree;
}

// tree Height

int treeHeight(TreeNode *tree) {
  if (tree == NULL)
    return -1;
  else {

    int leftHeight = treeHeight(tree->leftChild);
    int rightHeight = treeHeight(tree->rightChild);
    if (leftHeight > rightHeight)
      return (leftHeight + 1);
    else
      return (rightHeight + 1);
  }
}

// search in tree
int searchNode(int value, TreeNode *tree) {
  if (tree == NULL) {
    return 0;
  } else if (tree->data == value) {
    return 1;
  } else {
    if (value > tree->data) {
      return searchNode(value, tree->rightChild);
    } else {
      return searchNode(value, tree->leftChild);
    }
  }
}

// min value of tree

TreeNode *minValue(TreeNode *tree) {
  while (tree->leftChild != NULL) {
    tree = tree->leftChild;
  }
  return tree;
}

// max value of tree

int maxValue(TreeNode *tree) {
  while (tree->rightChild != NULL) {
    tree = tree->rightChild;
  }
  return tree->data;
}

TreeNode *deleteNode(TreeNode *root, int value) {

  if (root == NULL)
    return root;

  if (value < root->data)
    root->leftChild = deleteNode(root->leftChild, value);

  else if (value > root->data)
    root->rightChild = deleteNode(root->rightChild, value);

  else {
    // node with only one child or no child
    if (root->leftChild == NULL) {
      TreeNode *temp = root->rightChild;
      free(root);
      return temp;
    } else if (root->rightChild == NULL) {
      TreeNode *temp = root->leftChild;
      free(root);
      return temp;
    }

    TreeNode *temp = minValue(root->rightChild);

    root->data = temp->data;

    root->rightChild = deleteNode(root->rightChild, temp->data);
  }
  return root;
}

int main() {
  int randomNum;

  srand(time(NULL));

  for (int i = 0; i < 100; i++) {
    randomNum = rand() % (VALEUR_MAX + 1);
    root = insertNewNode(root, randomNum);
  }

  printf("************* Tree Opertaions *************\n\n");
  int res;
  do {
    printf("\n\n1 - Insert into tree\n2 - Search Element\n3 - Min Of Tree\n4 - "
           "Max Of Tree\n5 - Height of Tree\n6 - number of Element\n* - Tree "
           "Traversal : \n  7 - preorder\n  8 - postorder\n  9 - inorder\n10 - "
           "remove node from tree");
    printf("\n\n Your Choice : ");

    scanf("%d", &res);
    printf("\n\n***********");
    if (res == 1) {
      int value;
      printf("\n Give me ur value : ");
      scanf("%d", &value);
      root = insertNewNode(root, value);
    } else if (res == 7) {
      printf("\n\n Pre Order : *************\n\n");
      preOrder(root);
      printf("\n\n");
    } else if (res == 8) {
      printf("\n\n Post Order : *************\n\n");
      postOrder(root);
      printf("\n\n");
    } else if (res == 9) {
      printf("\n\n In Order : *************\n\n");
      inOrder(root);
      printf("\n\n");
    } else if (res == 3) {
      TreeNode *min = minValue(root);
      printf("\n\n min value is : %d", min->data);
    } else if (res == 4) {
      int max = maxValue(root);
      printf("\n\n max value is : %d", max);
    } else if (res == 6) {
      printf("\n\n Number of Elements in Tree is : %d", numberOfElements);
    } else if (res == 2) {
      int value;
      printf("\n\n What's the value you search for : ");
      scanf("%d", &value);

      if (searchNode(value, root)) {
        printf("\n\n The Value is exist in the Tree");
      } else {
        printf("\n\n The Value is not exist in the Tree");
      }
    } else if (res == 5) {
      printf("\n\n The height of tree is : %d", treeHeight(root));
    } else if (res == 10) {
      int value;
      printf("\n\n What's the value you want to remove : ");
      scanf("%d", &value);

      if (searchNode(value, root)) {
        root = deleteNode(root, value);
      } else {
        printf("\n\n The Value is not exist in the Tree");
      }
    }
  } while (res > 0 && res < 11);

  return 0;
}
