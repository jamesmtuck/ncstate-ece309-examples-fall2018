#include <stdio.h>
#include <stdlib.h>

class BTree {

  class BTreeNode { // 2-3-4 B-tree node
  public:
    BTreeNode *parent; // point to the parent node (helpful later)
    int A;

    int B;
    bool B_null; // B_null=true means B has no key

    int C;
    bool C_null; // C_null=true means C has no key

    BTreeNode *left; // Child pointers
    BTreeNode *middle1;
    BTreeNode *middle2;
    BTreeNode *right;

    void print() {
      printf("\n");
      printf("[%p] ", this);
      printf("A=%d B=%d C=%d \n", A, B, C);
      printf("\t\t left=%p m1=%p m2=%p r=%p", left, middle1, middle2, right);
    }

    // Normally when we construct, we are splitting nodes, and those nodes
    // have only 1 key and 2 children.
    BTreeNode(int a, BTreeNode *par = NULL, BTreeNode *l = NULL,
              BTreeNode *r = NULL)
        : parent(par), A(a), B(-1), B_null(true), C(-1), C_null(true), left(l),
          middle1(r), middle2(NULL), right(NULL) {
      if (l)
        l->parent = this;
      if (r)
        r->parent = this;
    }

    void insert(int key) {
      if (key < A) {
        C = B;
        C_null = B_null;
        B = A;
        B_null = false;
        A = key;
      } else if (B_null || key < B) {
        C = B;
        C_null = B_null;
        B = key;
        B_null = false;
      } else {
        C = key;
        C_null = false;
      }
    }

    bool hasKey(int key) {
      return A == key || (!B_null && B == key) || (!C_null && C == key);
    }

    bool isLeaf() {
      return left == NULL && middle1 == NULL && middle2 == NULL &&
             right == NULL;
    }
    bool isFull() { return !B_null && !C_null; }
  };

  BTreeNode *root;

  BTreeNode *search_helper(BTreeNode *node, int key) {
    if (node) {
      if (key == node->A || (!node->B_null && key == node->B) ||
          (!node->B_null && key == node->C)) {
        return node;
      }
      if (key < node->A)
        return search_helper(node->left, key);
      else if (node->B_null || key < node->B)
        return search_helper(node->middle1, key);
      else if (node->C_null || key < node->C)
        return search_helper(node->middle2, key);
      else
        return search_helper(node->right, key);
    }
    return NULL;
  }

  void insertKeyWithChildren(BTreeNode *parent, int key, BTreeNode *leftChild,
                             BTreeNode *rightChild) {

    // printf("insertKeyWithChildren [%p] (%p) ---(%d,%d,%d)---\n", parent,
    //       parent->parent, parent->A, parent->B, parent->C);

    if (key < parent->A) { // insert key at A, move everything else over
      parent->C = parent->B;
      parent->C_null = parent->B_null;
      parent->B = parent->A;
      parent->B_null = false;
      parent->A = key;
      parent->right = parent->middle2;
      parent->middle2 = parent->middle1;
      parent->middle1 = rightChild;
      parent->left = leftChild;
    } else if (parent->B_null || key < parent->B) { // insert key at B, and move
                                                    // everything else over
      parent->C = parent->B;
      parent->C_null = parent->B_null;
      parent->B = key;
      parent->B_null = false;
      parent->right = parent->middle2;
      parent->middle2 = rightChild;
      parent->middle1 = leftChild;
    } else { // last case, insert at C
      parent->C = key;
      parent->C_null = false;
      parent->right = rightChild;
      parent->middle2 = leftChild;
    }
  }

  BTreeNode *split(BTreeNode *node) {
    if (!node->isFull())
      return NULL;

    BTreeNode *nodeParent = node->parent;

    BTreeNode *splitLeft =
        new BTreeNode(node->A, NULL, node->left, node->middle1);

    BTreeNode *splitRight =
        new BTreeNode(node->C, NULL, node->middle2, node->right);

    // if (nodeParent)
    //  nodeParent->print();
    // splitLeft->print();
    // splitRight->print();

    if (nodeParent) { // Case 1: not the root
      insertKeyWithChildren(nodeParent, node->B, splitLeft, splitRight);
      splitLeft->parent = nodeParent;
      splitRight->parent = nodeParent;
    } else { // Case 2: the root!
      nodeParent = new BTreeNode(node->B, NULL, splitLeft, splitRight);
      splitLeft->parent = nodeParent;
      splitRight->parent = nodeParent;
      root = nodeParent;
    }

    // printf("After: \n");
    // nodeParent->print();
    // splitLeft->print();
    // splitRight->print();

    delete node; // delete the old node

    return nodeParent;
  }

  BTreeNode *insert_helper(BTreeNode *node, int key) {
    if (node->hasKey(key)) {
      return NULL; // duplicates not allowed
    }
    if (node->isFull()) {
      node = split(node);
    }
    if (!node->isLeaf()) {
      if (key < node->A)
        return insert_helper(node->left, key);
      else if (node->B_null || key < node->B)
        return insert_helper(node->middle1, key);
      else if (node->C_null || key < node->C)
        return insert_helper(node->middle2, key);
      else
        return insert_helper(node->right, key);
    } else {
      node->insert(key);
      return node;
    }
  }
  void inorder_helper(BTreeNode *node) {
    if (node == NULL)
      return;

    inorder_helper(node->left);
    printf("%d, ", node->A);
    inorder_helper(node->middle1);
    if (node->B_null)
      return;
    printf("%d, ", node->B);

    inorder_helper(node->middle2);

    if (node->C_null)
      return;
    printf("%d, ", node->C);

    inorder_helper(node->right);
  }

public:
  BTree() : root(NULL) {}

  bool search(int key) {
    if (root)
      return search_helper(root, key) != NULL;
    else
      return false;
  }
  void insert(int key) {
    if (root)
      insert_helper(root, key);
    else {
      root = new BTreeNode(key);
    }
  }
  void remove(int key) { // To be added
  }

  void inorder() {
    printf("inorder: ");
    if (root)
      inorder_helper(root);
    printf("\n");
  }
};

int main() {
  BTree btree;

  for (int i = 0; i < 100; i++) {
    printf("insert: %d\n", i);
    btree.insert(i);
    btree.inorder();
  }

  // btree.inorder();

  return 0;
}
