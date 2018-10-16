#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stdlib.h>

class BinarySearchTree {
protected:
  class BTNode {
  public:
    int data;
    BTNode *left;
    BTNode *right;

    BTNode(int d, BTNode *l = NULL, BTNode *r = NULL)
        : data(d), left(l), right(r) {}
  };

  bool Case1(BTNode *parent, BTNode *node);
  bool Case2(BTNode *parent, BTNode *node);
  void Case3(BTNode *parent, BTNode *node);

  void inorderPrint(BTNode *node);

  BTNode *root;

public:
  int count;
  BinarySearchTree() : root(NULL), count(0) {}
  virtual void insert(int data);
  virtual bool search(int data);
  virtual void remove(int data);

  virtual void print();
};

#endif // BINARYSEARCHTREE_H
