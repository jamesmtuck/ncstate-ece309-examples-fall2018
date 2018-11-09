#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

class Queue {
private:
  List list;

public:
  Queue() {}
  void push(Item);
  void pop();
  Item& peek();
  bool empty();
};

#endif //QUEUE_H
