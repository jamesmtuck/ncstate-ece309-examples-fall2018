#include <stdio.h>

template <typename T> void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int a = 5, b = 10;

  swap(a, b);

  printf("a = % d b = % d\n", a, b);

  return 0;
}
