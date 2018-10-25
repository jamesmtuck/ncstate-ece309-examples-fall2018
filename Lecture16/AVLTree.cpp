#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class AVLTree : public BinarySearchTree {
protected:
  int balanceFactor(BTNode *node) {
    int left = -1, right = -1;
    if (node == NULL)
      return -1;
    if (node->left)
      left = node->left->height;
    if (node->right)
      right = node->right->height;
    return left - right;
  }

  void balance(BTNode *node);
  void rotateRight(BTNode *node);
  void rotateLeft(BTNode *node);

public:
  void insert(int data) override;
  void remove(int data) override;
};

void AVLTree::rotateRight(AVLTree::BTNode *node) {
  BTNode *parent = node->parent;
  BTNode *left = node->left;
  BTNode *leftright = node->left->right;

  left->setRight(node);
  node->setLeft(leftright);

  if (root == node)
    setRoot(left);
  else
    parent->replace(node, left);

  updateHeight(node);
}

void AVLTree::rotateLeft(AVLTree::BTNode *node) {
  BTNode *parent = node->parent;
  BTNode *right = node->right;
  BTNode *rightleft = node->right->left;

  right->setLeft(node);
  node->setRight(rightleft);

  if (root == node)
    setRoot(right);
  else
    parent->replace(node, right);

  updateHeight(node);
}

void AVLTree::balance(BTNode *node) {
  if (balanceFactor(node) == -2) {
    if (balanceFactor(node->right) == 1)
      rotateRight(node->right);
    rotateLeft(node);
  } else if (balanceFactor(node) == 2) {
    if (balanceFactor(node->left) == -1)
      rotateLeft(node->left);
    rotateRight(node);
  }
}

void AVLTree::insert(int data) {
  BTNode *node = new BTNode(data);
  insertHelper(node);
  BTNode *ancestor = node->parent;
  while (ancestor != NULL) {
    balance(ancestor);
    ancestor = ancestor->parent;
  }
}

void AVLTree::remove(int data) {
  BTNode *ancestor = removeHelper(data);
  while (ancestor != NULL) {
    balance(ancestor);
    ancestor = ancestor->parent;
  }
}

int main() {
  AVLTree bst;
  // BinarySearchTree bst;
  srand(time(NULL));

  int num = 1000;
  for (int i = 0; i < num; i++) {
    int r = i + rand() % 50;
    if (!bst.search(r)) {
      bst.insert(r);
      // printf("insert %d\n:", r);
      // bst.print();
    }
  }

  printf("Did %d comparisons when searching. %d per search.\n", bst.count,
         bst.count / num);

  return 0;
}
