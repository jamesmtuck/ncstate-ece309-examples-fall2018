#include "BinarySearchTree.h"
#include <algorithm>
#include <stdio.h>

void BinarySearchTree::updateHeight(BTNode *node) {
  if (node == NULL)
    return;
  int height = node->computeHeight();

  while (node->parent != NULL && node->parent->height < height + 1) {
    node = node->parent;
    height = node->computeHeight();
  }
}

void BinarySearchTree::insertHelper(BinarySearchTree::BTNode *node) {
  if (root == NULL)
    setRoot(node);
  else {
    BTNode *tmp = root;
    while (tmp != NULL) {
      if (node->data < tmp->data) {
        // left subtree
        if (tmp->left == NULL) {
          tmp->setLeft(node);
          updateHeight(node);
          return;
        } else
          tmp = tmp->left;
      } else {
        if (tmp->right == NULL) {
          tmp->setRight(node);
          updateHeight(node);
          return;
        } else {
          tmp = tmp->right;
        }
      }
    }
  }
}

BinarySearchTree::BTNode *BinarySearchTree::removeHelper(int data) {
  BTNode *node = root;
  while (node != NULL) {
    if (data == node->data) {
      // Found the node, remove it.
      BTNode *parent = node->parent;
      if (!Case1(node->parent, node))
        if (!Case2(node->parent, node))
          Case3(node->parent, node, parent);

      // now we can delete the node
      delete node;
      return parent;
    } else if (data < node->data) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  // if parent==NULL, then no node to remove
  return NULL;
}

void BinarySearchTree::insert(int data) {
  BTNode *node = new BTNode(data);
  insertHelper(node);
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
      setRoot(NULL);
    else
      parent->replace(node, NULL);

    updateHeight(parent);
    return true;
  }
  return false;
}

bool BinarySearchTree::Case2(BTNode *parent, BTNode *node) {
  if (node->left != NULL && node->right == NULL) {
    if (parent == NULL)
      setRoot(node->left);
    else
      parent->replace(node, node->left);

    updateHeight(parent);
    return true;
  } else if (node->left == NULL && node->right != NULL) {
    if (parent == NULL)
      setRoot(node->right);
    else
      parent->replace(node, node->right);
    updateHeight(parent);
    return true;
  }
  return false;
}

void BinarySearchTree::Case3(BTNode *parent, BTNode *node,
                             BTNode *&parent_succ) {
  BTNode *succ = node->right;
  while (succ->left != NULL) {
    succ = succ->left; // go to left-most child
  }
  parent_succ = succ->parent;
  if (!Case1(parent_succ, succ))
    Case2(parent_succ, succ);

  // succ no longer in tree!
  succ->setLeft(node->left);
  succ->setRight(node->right);

  if (parent == NULL)
    setRoot(succ);
  else
    parent->replace(node, succ);

  updateHeight(succ);
}

void BinarySearchTree::remove(int data) { removeHelper(data); }

void BinarySearchTree::inorderPrint(BTNode *node) {
  if (node == NULL)
    return;

  printf(" ( ", node->height);
  inorderPrint(node->left);
  printf("%d", node->data);
  inorderPrint(node->right);
  printf(" ) ");
}

void BinarySearchTree::print() {
  printf(">>");
  inorderPrint(root);
  printf("\n");
}
