#include "BinarySearchTree.h"
#include <algorithm>
#include <stdio.h>

int BinarySearchTree::computeHeight(BTNode *node) {
  if (node->left == NULL && node->right == NULL)
    node->height = 0;
  else if (node->left && node->right == NULL)
    node->height = node->left->height + 1;
  else if (node->left == NULL && node->right)
    node->height = node->right->height + 1;
  else
    node->height = std::max(node->right->height, node->left->height) + 1;
  return node->height;
}

void BinarySearchTree::updateHeight(BTNode *node) {
  if (node == NULL)
    return;
  int height = computeHeight(node);

  while (node->parent != NULL && node->parent->height < height + 1) {
    node->parent->height = height + 1;
    height++;
    node = node->parent;
  }
}

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
          node->parent = tmp;
          updateHeight(node);
          return;
        } else
          tmp = tmp->left;
      } else {
        if (tmp->right == NULL) {
          tmp->right = node;
          node->parent = tmp;
          updateHeight(node);
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
    updateHeight(parent);
    return true;
  }
  return false;
}

bool BinarySearchTree::Case2(BTNode *parent, BTNode *node) {
  if (node->left != NULL && node->right == NULL) {
    if (parent == NULL) {
      root = node->left;
    } else if (parent->left == node) {
      parent->left = node->left;
    } else {
      parent->right = node->left;
    }
    node->left->parent = parent;
    updateHeight(parent);
    return true;
  } else if (node->left == NULL && node->right != NULL) {
    if (parent == NULL) {
      root = node->right;
    } else if (parent->left == node) {
      parent->left = node->right;
    } else {
      parent->right = node->right;
    }
    node->right->parent = parent;
    updateHeight(parent);
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
}

void BinarySearchTree::remove(int data) {
  BTNode *node = root;
  while (node != NULL) {
    if (data == node->data) {
      // Found the node, remove it.
      if (!Case1(node->parent, node))
        if (!Case2(node->parent, node))
          Case3(node->parent, node);

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
