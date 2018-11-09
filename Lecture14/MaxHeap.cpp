#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

class MaxHeap {
private:
  int *heapArray;    // this is the maxheap
  int heapArraySize; // size of the array
  int nextIndex;     // location of next free array entry

protected:
  void percolate_up(int);
  void percolate_down(int, int);

public:
  MaxHeap(int size = 100) : heapArraySize(size) {
    heapArray = new int[size];
    for (int i = 0; i < size; i++)
      heapArray[i] = 0;
    nextIndex = 0;
  }

  void topthree(int &gold, int &silver, int &bronze) const {
    if (nextIndex > 0) {
      gold = heapArray[0]; // have at least one
      if (nextIndex == 2) {
        silver = heapArray[1];    // have exactly two
      } else if (nextIndex > 2) { // have 3 or more
        silver = std::max(heapArray[1], heapArray[2]);
        int silver_index = 1;
        int bronze_index = 2;
        if (heapArray[2] > heapArray[1]) {
          silver_index = 2;
          bronze_index = 1;
        }
        bronze = heapArray[bronze_index];
        // But, the children of the silver could be larger than
        // the sibling of silver! So check here too!
        // First silver child
        if (silver_index * 2 + 1 < nextIndex &&
            heapArray[silver_index * 2 + 1] > bronze)
          bronze = heapArray[silver_index * 2 + 1];
        // Second silver child
        if (silver_index * 2 + 2 < nextIndex &&
            heapArray[silver_index * 2 + 2] > bronze)
          bronze = heapArray[silver_index * 2 + 2];
      }
    }
  }

  void print() {
    for (int i = 0; i < nextIndex; i++) {
      printf("%d ", heapArray[i]);
    }
    printf("\n");
  }

  bool insert(int);
  bool remove(int &); // remove the max value
};

void MaxHeap::percolate_up(int index) {
  while (index > 0) {
    int parent_index = (index - 1) / 2;
    if (heapArray[index] > heapArray[parent_index]) {
      int tmp = heapArray[index];
      heapArray[index] = heapArray[parent_index];
      heapArray[parent_index] = tmp;
      index = parent_index;
    } else
      return;
  }
}

void MaxHeap::percolate_down(int index, int size) {
  int child_index = index * 2 + 1;
  int val = heapArray[index];
  while (child_index < size) {
    int max_val = val;
    int max_index = -1;
    for (int i = child_index; i < child_index + 2 && i < size; i++) {
      if (heapArray[i] > max_val) {
        max_val = heapArray[i];
        max_index = i;
      }
    }
    if (max_val == val)
      return;
    heapArray[index] = max_val;
    heapArray[max_index] = val;
    index = max_index;
    child_index = index * 2 + 1;
  }
}

bool MaxHeap::insert(int data) {
  if (nextIndex < heapArraySize) {
    heapArray[nextIndex] = data;
    percolate_up(nextIndex);
    nextIndex++;
    return true;
  } else {
    return false;
  }
}

bool MaxHeap::remove(int &val) {
  if (nextIndex > 0) {
    val = heapArray[0];
    heapArray[0] = heapArray[nextIndex - 1];
    nextIndex -= 1;
    percolate_down(0, nextIndex);
    return true;
  }
  return false;
}

int main() {
  MaxHeap heap;

  int gold = -1, silver = -1, bronze = -1;
  heap.topthree(gold, silver, bronze);
  printf("topthree: %d %d %d\n", gold, silver, bronze);

  heap.insert(45);
  heap.print();

  heap.topthree(gold, silver, bronze);
  printf("topthree: %d %d %d\n", gold, silver, bronze);

  heap.insert(100);
  heap.print();

  heap.topthree(gold, silver, bronze);
  printf("topthree: %d %d %d\n", gold, silver, bronze);

  heap.insert(83);
  heap.insert(15);

  heap.topthree(gold, silver, bronze);
  printf("topthree: %d %d %d\n", gold, silver, bronze);

  heap.insert(5);
  heap.insert(50);
  heap.insert(82);
  heap.print();

  heap.topthree(gold, silver, bronze);
  printf("topthree: %d %d %d\n", gold, silver, bronze);

  /*
    int ref;
    heap.remove(ref);
    heap.print();

    for (int i = 0; i < 100; i++)
      heap.insert(rand() % 1000);

    for (int i = 0; i < 20; i++)
      heap.remove(ref);
  */
  heap.print();

  return 0;
}
