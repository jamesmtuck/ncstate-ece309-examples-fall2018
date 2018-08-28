// Lecture 2 example
// James Tuck
// August 28, 2018

// Print a message when an object is created
// and destroyed.

#include <stdio.h>

class A {
  const char *msg;
public:
  // default constructor
  A(const char *m="") { 
    printf("Just got constructed (%s)\n", m);
    msg = m;
  }
  //destructor
  ~A() {
    printf("Just got destroyed (%s)\n", msg);
  }
};

// Global instance of A, created before main runs
// and destroyed when the program ends
A a3("a3");

int main()
{
  // This object is created on the heap and never
  // destroyed
  A * a1 = new A("a1");
  // Uncomment following line to see what happens
  // if a1 is destroyed.
  ///delete a1;

  // Local instance of A, created when main is called,
  // and destroyed when main returns:
  A a2("a2");

  return 0;
}
