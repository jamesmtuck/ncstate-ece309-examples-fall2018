// RefCount.cpp
#include "RefCount.h"
#include <stdio.h>

// Defining declarations
int RefCount::count = 0; // private, can’t access it!
int RefCount::getCount() { return count; }

RefCount one;

int main() {
  RefCount two;
  printf("Number of RefCounts : % d", RefCount::getCount());
  return 0;
}
