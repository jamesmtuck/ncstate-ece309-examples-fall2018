#include "BinarySearchTree.h"
#include <stdio.h>

void BinarySearchTree::insert(int data) {
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
          return;
        } else
          tmp = tmp->left;
      } else {
        if (tmp->right == NULL) {
          tmp->right = node;
          return;
        } else {
          tmp = tmp->right;
        }
      }
    }
  }
}

bool BinarySearchTree::search(int data) {
  BTNode *tmp = root;
  while (tmp != NULL) {
    count++;
    if (data == tmp->data)
      return true;
    if (data < tmp->data) {
      tmp = tmp->left;
    } else {
      tmp = tmp->right;
    }
  }
  return false;
}

bool BinarySearchTree::Case1(BTNode *parent, BTNode *node) {
  if (node->left == NULL && node->right == NULL) {
    if (parent == NULL)
      root = NULL;
    else if (parent->left == node)
      parent->left = NULL;
    else
      parent->right = NULL;
    return true;
  }
  return false;
}

bool BinarySearchTree::Case2(BTNode *parent, BTNode *node) {
  if (node->left != NULL && node->right == NULL) {
    if (parent == NULL)
      root = node->left;
    else if (parent->left == node)
      parent->left = node->left;
    else
      parent->right = node->left;
    return true;
  } else if (node->left == NULL && node->right != NULL) {
    if (parent == NULL)
      root = node->right;
    else if (parent->left == node)
      parent->left = node->right;
    else
      parent->right = node->right;
    return true;
  }
  return false;
}

void BinarySearchTree::Case3(BTNode *parent, BTNode *node) {
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

  if (parent == NULL)
    root = succ;
  else if (parent->left == node)
    parent->left = succ;
  else
    parent->right = succ;
}

void BinarySearchTree::remove(int data) {
  BTNode *node = root;
  BTNode *parent = NULL;
  while (node != NULL) {
    if (data == node->data) {
      // Found the node, remove it.
      if (!Case1(parent, node))
        if (!Case2(parent, node))
          Case3(parent, node);

      // now we can delete the node
      delete node;
      return;
    } else if (data < node->data) {
      parent = node;
      node = node->left;
    } else {
      parent = node;
      node = node->right;
    }
  }
  // no node to remove!
  return;
}

void BinarySearchTree::inorderPrint(BTNode *node) {
  if (node == NULL)
    return;
  // printf("(");
  inorderPrint(node->left);
  printf("%d", node->data);
  inorderPrint(node->right);
  // printf(")");
}

void BinarySearchTree::print() {
  printf(">>");
  inorderPrint(root);
  printf("\n");
}
