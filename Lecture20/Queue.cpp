#include "Queue.h"

void Queue::push(Item item)
{
  list.append(item);
}

void Queue::pop()
{
  List::iterator it; // NULL iterator
  // remove from the head of the queue using NULL iterator
  list.removeAfter(it);
}

Item& Queue::peek()
{
  List::iterator it = list.begin();
  return it.getItem();
}

bool Queue::empty()
{
  return list.empty();
}
