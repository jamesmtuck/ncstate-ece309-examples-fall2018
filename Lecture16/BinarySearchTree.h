#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <algorithm>
#include <stdlib.h>

class BinarySearchTree {
protected:
  class BTNode {
  public:
    int data;
    BTNode *left;
    BTNode *right;
    BTNode *parent;
    int height;

    void replace(BTNode *remove, BTNode *node) {
      if (left == remove)
        setLeft(node);
      else
        setRight(node);
    }

    void setLeft(BTNode *l) {
      left = l;
      if (l)
        l->parent = this;
    }
    void setRight(BTNode *r) {
      right = r;
      if (r)
        r->parent = this;
    }

    int computeHeight() {
      if (left == NULL && right == NULL)
        height = 0;
      else if (left && right == NULL)
        height = left->height + 1;
      else if (left == NULL && right)
        height = right->height + 1;
      else
        height = std::max(right->height, left->height) + 1;
      return height;
    }

    BTNode(int d, BTNode *l = NULL, BTNode *r = NULL, BTNode *p = NULL)
        : data(d), left(l), right(r), parent(p), height(0) {}
  };

  virtual bool Case1(BTNode *parent, BTNode *node);
  virtual bool Case2(BTNode *parent, BTNode *node);
  virtual void Case3(BTNode *parent, BTNode *node, BTNode *&parent_succ);

  void inorderPrint(BTNode *node);

  BTNode *root;

  void setRoot(BTNode *node) {
    root = node;
    if (node)
      node->parent = NULL;
  }

  void updateHeight(BTNode *node);

  virtual void insertHelper(BTNode *node);
  virtual BTNode *removeHelper(int data);

public:
  int count;
  BinarySearchTree() : root(NULL), count(0) {}
  virtual void insert(int data);
  virtual bool search(int data);
  virtual void remove(int data);

  virtual void print();
};

#endif // BINARYSEARCHTREE_H
