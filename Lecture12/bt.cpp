#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

  BTNode *root;

public:
  int count;
  BinarySearchTree() : root(NULL), count(0) {}
  virtual void insert(int data);
  virtual bool search(int data);
};

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

int main() {

  /*BTNode *root = new BTNode(100);
  root->left = new BTNode(25);
  root->right = new BTNode(150);

  BTNode *root2 = new BTNode(9, new BTNode(5, new BTNode(1), new BTNode(7)),
                             new BTNode(15));

  BTNode *root3 = new BTNode(100, NULL, new BTNode(150, NULL, new BTNode(200)));
*/

  BinarySearchTree bst;
  /*bst.insert(50);
  bst.insert(25);
  bst.insert(100);*/

  srand(time(NULL));
  for (int i = 0; i < 100000; i++) {
    bst.insert(rand());
  }

  if (bst.search(100))
    printf("Found 100!\n");

  printf("Did %d comparisons when searching.\n", bst.count);

  return 0;
}
