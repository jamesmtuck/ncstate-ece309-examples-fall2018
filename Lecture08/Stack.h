#ifndef STACK_H
#define STACK_H

#include "Item.h"
#include "List.h"

class Stack : private List {

public:
  Stack() {}
  void push(Item item) { insertAfter(iterator(),item); }
  void pop() { removeAfter(iterator()); }
  Item& peek() { iterator it = begin(); return it.getItem(); }
  //bool empty() { return List::empty(); }
  using List::empty;
};

#endif //STACK_H
