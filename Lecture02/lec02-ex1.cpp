// Lecture 2 example
// James Tuck
// August 28, 2018

#include <stdio.h>

class R {
  int x;
public:
  R(int ax) { x = ax; }
  void print() { printf("%d\n",x); }
};

int main()
{
  // heap allocated instance of R
  // r is a pointer
  R *r = new R(10);

  // stack allocated instance of R
  // r2 is an object
  R r2 = R(100);

  // since r is a pointer, must dereference
  // it first to use it
  // Use star first, then . operator
  (*r).print();
  // or, just use the arrow operator
  r->print();

  // Since r2 is an object, no need to 
  // use the arrow operator.
  r2.print();

  return 0;
}
