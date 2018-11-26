#include <stdio.h>

namespace {
int x;
} // namespace

namespace A {
extern int a; // variable a declared
void f();
} // namespace A
namespace A {
int a = 0;
void f(); // function f declared
namespace B {
void f(); // function f in namespace B
}
} // namespace A

void A::f() { printf("A::f defined. a=%d\n", A::a); }

void A::B::f() { printf("A::B::f defined. a=%d\n", A::a); }

namespace A {
int z;
}

int main() {
  // using namespace A;

  int x;
  ::x = 3;
  x = 4;

  A::f();
  A::a = 5;
  A::B::f();
  return 0;
}
