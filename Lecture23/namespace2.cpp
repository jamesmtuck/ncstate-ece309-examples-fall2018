#include <stdio.h>

int a;

namespace A {
int a; // variable a declared in namespace A
int b;
} // namespace A

int main() {
  int a = 5;
  ::a = 6; // We can access the global namespace with unqualified ::
  A::a = 10;

  printf("a = %p ::a = %p A::a = %p\n", &a, &::a, &A::a);
  return 0;
}
