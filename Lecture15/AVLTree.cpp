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

  void Case3(BTNode *parent, BTNode *node) override;

public:
  void insert(int data) override;
  void remove(int data) override;
};

void AVLTree::rotateRight(AVLTree::BTNode *node) {
  BTNode *parent = node->parent;
  BTNode *left = node->left;
  BTNode *leftright = node->left->right;
  left->right = node;
  node->parent = left;
  node->left = leftright;
  if (leftright) {
    leftright->parent = node;
  }
  if (root == node) {
    root = left;
    left->parent = NULL;
  } else if (parent->left == node) {
    parent->left = left;
    left->parent = parent;
  } else {
    parent->right = left;
    left->parent = parent;
  }
  updateHeight(node);
}

void AVLTree::rotateLeft(AVLTree::BTNode *node) {
  BTNode *parent = node->parent;
  BTNode *right = node->right;
  BTNode *rightleft = node->right->left;
  right->left = node;
  node->parent = right;
  node->right = rightleft;
  if (rightleft)
    rightleft->parent = node;
  if (root == node) {
    root = right;
    right->parent = NULL;
  } else if (parent->left == node) {
    parent->left = right;
    right->parent = parent;
  } else {
    parent->right = right;
    right->parent = parent;
  }
  updateHeight(node);
}

void AVLTree::balance(BTNode *node) {
  // node = node->parent;
  while (node != NULL) {
    if (balanceFactor(node) == -2) {
      if (balanceFactor(node->right) == 1)
        rotateRight(node->right);
      rotateLeft(node);
    } else if (balanceFactor(node) == 2) {
      if (balanceFactor(node->left) == -1)
        rotateLeft(node->left);
      rotateRight(node);
    }
    node = node->parent;
  }
}

void AVLTree::insert(int data) {
  BTNode *node = new BTNode(data);
  if (root == NULL)
    root = node;
  else {
    BTNode *tmp = root;
    while (tmp != NULL) {
      if (data < tmp->data) {
        // left subtree
        if (tmp->left == NULL) {
          tmp->left = node;
          node->parent = tmp;
          updateHeight(node);
          balance(node);
          return;
        } else
          tmp = tmp->left;
      } else {
        if (tmp->right == NULL) {
          tmp->right = node;
          node->parent = tmp;
          updateHeight(node);
          balance(node);
          return;
        } else {
          tmp = tmp->right;
        }
      }
    }
  }
}

void AVLTree::Case3(BTNode *parent, BTNode *node) {
  BTNode *succ = node->right;
  BTNode *parent_succ = node;
  while (succ->left != NULL) {
    parent_succ = succ;
    succ = succ->left; // go to left-most child
  }

  if (!Case1(parent_succ, succ))
    Case2(parent_succ, succ);

  // succ no longer in tree!
  succ->left = node->left;
  succ->right = node->right;
  succ->parent = parent;

  node->left->parent = succ;
  if (node->right)
    node->right->parent = succ;

  if (parent == NULL)
    root = succ;
  else if (parent->left == node)
    parent->left = succ;
  else
    parent->right = succ;

  updateHeight(succ);
  if (parent_succ != node)
    balance(parent_succ);
  else
    balance(succ);
}

void AVLTree::remove(int data) {
  BTNode *node = root;
  while (node != NULL) {
    if (data == node->data) {
      // Found the node, remove it.
      BTNode *parent = node->parent;
      if (!Case1(node->parent, node))
        if (!Case2(node->parent, node))
          Case3(node->parent, node);

      if (parent)
        balance(parent);
      // now we can delete the node
      delete node;
      return;
    } else if (data < node->data) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  // no node to remove!
  return;
}

int main() {
  AVLTree bst;
  // BinarySearchTree bst;
  srand(time(NULL));

  for (int i = 0; i < 10; i++)
    bst.insert(i);

  bst.print();

  for (int i = 5; i < 10; i++)
    bst.remove(i);

  bst.print();
  bst.insert(-1);

  bst.print();

  /*int num = 1000;
  for (int i = 0; i < num; i++) {
    int r = i + rand() % 10;
    if (bst.search(r)) {
      printf("remove %d\n:", r);
      bst.remove(r);
      // bst.print();
    } else {
      bst.insert(r);
      printf("insert %d\n:", r);
      // bst.print();
    }
  }

  printf("Did %d comparisons when searching. %d per search.\n", bst.count,
         bst.count / num);
*/
  return 0;
}
