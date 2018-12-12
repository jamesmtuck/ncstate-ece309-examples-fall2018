#include <stdio.h>

class A {
public:
  A() { printf("A()"); }
};

class IntArray {
public:
  int size;
  int *array;

  IntArray(int sz, int val = 0) {
    array = new int[sz];
    size = sz;
    for (int i = 0; i < size; i++)
      array[i] = val;
  }

  IntArray(const IntArray &copy) {
    array = new int[copy.size];
    size = copy.size;

    for (int i = 0; i < copy.size; i++) {
      array[i] = copy.array[i];
    }
  }
};

int main() {
  IntArray array(10, 0);
  IntArray array2 = array;

  A a;
  return 0;
}
