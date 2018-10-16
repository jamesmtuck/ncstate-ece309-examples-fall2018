#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  BinarySearchTree bst;

  srand(time(NULL));

  int num = 1000000;
  for (int i = 0; i < num; i++) {
    int r = rand() % 10;
    if (bst.search(r)) {
      printf("remove %d\n:", r);
      bst.remove(r);
      bst.print();
    } else {
      bst.insert(r);
      printf("insert %d\n:", r);
      bst.print();
    }
  }

  printf("Did %d comparisons when searching. %d per search.\n", bst.count,
         bst.count / num);

  return 0;
}
